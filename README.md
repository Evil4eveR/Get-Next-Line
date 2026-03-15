# GET_NEXT_LINE

> *Reading a line from a file descriptor — one call at a time.*

This project was created as part of the **42 curriculum** by **ymarmoud**.

---

## Description

`get_next_line` is a C function that reads a file descriptor line by line, returning one line per call — including the trailing `\n` when present. Each successive call picks up exactly where the last one left off, until the file is fully consumed and `NULL` is returned.

The main challenge is that a single `read()` call may return partial lines, full lines, or multiple lines at once depending on `BUFFER_SIZE`. The function must handle all of these cases transparently, without losing data between calls.

**Key constraints (42 norm):**
- Each function must be ≤ 25 lines
- No global variables — only one `static` variable allowed in `get_next_line`
- `BUFFER_SIZE` is defined at compile time and can be any positive value

---

## How It Works — The Algorithm

The core idea is a **persistent accumulator** called `stash`. Between calls, `stash` holds any leftover data that was read but not yet returned.

```
┌─────────────────────────────────────────────────────────┐
│                   get_next_line(fd)                     │
│                                                         │
│  1. Read chunks into buffer until '\n' found or EOF     │
│     └─> Append each chunk to stash via ft_strjoin       │
│                                                         │
│  2. extract_line(stash)                                 │
│     └─> Copy stash up to and including '\n' → line      │
│                                                         │
│  3. clean_stash(stash)                                  │
│     └─> Keep only what comes after '\n' for next call   │
│                                                         │
│  4. Return line                                         │
└─────────────────────────────────────────────────────────┘
```

**Example — reading `"hello\nworld\n"` with `BUFFER_SIZE=4`:**

| Call | Read chunks | Stash after reads | Returned line | Stash after clean |
|------|-------------|-------------------|---------------|-------------------|
| 1st  | `"hell"` → `"o\nwo"` | `"hello\nwo"` | `"hello\n"` | `"wo"` |
| 2nd  | `"rld\n"` | `"world\n"` | `"world\n"` | `""` → NULL |
| 3rd  | EOF (0 bytes) | NULL | `NULL` | — |

---

## The Static Variable

```c
static char *stash;
```

A `static` local variable is **allocated once** and persists for the entire lifetime of the program — its value is **preserved between function calls**, unlike a regular local variable which is destroyed when the function returns.

Without `static`, `stash` would reset to an uninitialized pointer on every call, and all leftover data from the previous `read` would be lost.

```c
// Regular variable — lost between calls
char *stash;          // ❌ garbage value on next call

// Static variable — survives between calls
static char *stash;   // ✅ retains its value from last call
```

`stash` is initialized to `NULL` automatically (static variables in C are zero-initialized), so the first call correctly treats it as an empty accumulator.

> ⚠️ Because `stash` is `static`, the function only works correctly with **one file descriptor at a time**. Reading two different fds in parallel will corrupt the stash. The bonus part of the project handles this with an array of stashes indexed by fd.

---

## Functions

### `get_next_line.c`

#### `get_next_line(int fd)`
The main function. Allocates a `buffer`, reads chunks from `fd` into it, and appends each chunk to `stash` until a `\n` is found or EOF is reached. Then extracts the next line, trims the stash, and returns the line.

```c
char *get_next_line(int fd);
```

- Returns the next line (including `\n`) on success
- Returns `NULL` on EOF, read error, or invalid fd
- Frees and resets `stash` on read error to avoid stale data on next open

#### `extract_line(char *stash)`
Scans `stash` for the first `\n`, allocates a new string, copies up to and including `\n`, and null-terminates it.

```c
static char *extract_line(char *stash);
```

#### `clean_stash(char *stash)`
After a line is extracted, removes everything up to and including the `\n` from `stash`. Returns `NULL` if nothing remains (no `\n` found, meaning EOF). Always frees the old stash.

```c
static char *clean_stash(char *stash);
```

---

### `get_next_line_utils.c`

#### `ft_strlen(char *s)`
Returns the length of string `s`, not counting the null terminator. Returns `0` if `s` is `NULL`.

#### `ft_strdup(char *s)`
Allocates a fresh copy of string `s`. Used by `ft_strjoin` when `s1` is `NULL` (first read call, stash not yet initialized).

#### `ft_strchr(char *s, int c)`
Searches for character `c` in string `s`. Returns a pointer to the first occurrence, or `NULL` if not found. Used in `get_next_line` to check whether the stash already contains a `\n` before reading more.

#### `ft_strjoin(char *s1, char *s2)`
Concatenates `s1` and `s2` into a new string. Frees `s1` after joining (since `s1` is the old stash, which is replaced). Handles `s1 == NULL` by returning a duplicate of `s2`.

---

## Instructions

### Compilation

`BUFFER_SIZE` could be defined at compile time:

```bash
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

Any positive integer works. Larger values mean fewer `read()` calls (faster for big files); smaller values (even `1`) are fully supported.

### Usage

```c
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
}
```

> Always `free()` the returned line — it is heap-allocated and the caller owns it.

### Header

```c
// get_next_line.h
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE 
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*extract_line(char *stash);

#endif
```

---

## Edge Cases Handled

| Case | Behaviour |
|------|-----------|
| Empty file | Returns `NULL` immediately |
| File with no trailing `\n` | Last line returned without `\n`, then `NULL` |
| File with only `\n` characters | Returns `"\n"` for each one |
| `BUFFER_SIZE = 1` | Reads one byte at a time — fully supported |
| `read()` returns `-1` | Stash is freed and reset, `NULL` returned |
| Invalid fd (`fd < 0`) | Returns `NULL` immediately |

---

## Resources

- the subject [GetNextLine.pdf](https://cdn.intra.42.fr/pdf/pdf/190692/en.subject.pdf)

### Documentation
- [`read(2)` — Linux man page](https://man7.org/linux/man-pages/man2/read.2.html)
- [`open(2)` — Linux man page](https://man7.org/linux/man-pages/man2/open.2.html)
- [Static variables in C — GeeksForGeeks](https://www.geeksforgeeks.org/static-variables-in-c/)
- [42 Norm v3](https://cdn.intra.42.fr/pdf/pdf/960/norme.en.pdf)

### Testing
- [francinette](https://github.com/xicodomingues/francinette) — the main GNL tester used during development
