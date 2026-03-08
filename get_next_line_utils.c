/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarmoud <ymarmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 14:34:28 by ymarmoud          #+#    #+#             */
/*   Updated: 2026/03/08 17:18:54 by ymarmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	int cnt;

	cnt = 0;
	while(s[cnt])
		cnt++;
	return (cnt);
}
char	*ft_strdup(char *s)
{
	char	*sdup;
	int	i;

	i = 0;
	sdup = (char *)malloc(ft_strlen(s)+1);
	if(!sdup)
		return (NULL);
	while(s[i])
	{
		sdup[i]=s[i];
		i++;
	}
	sdup[i]='\0';
	return (sdup);
}

char	*ft_substr(char	*s, unsigned int start, size_t l)
{
	char	*subs;
	size_t	i;

	if(!s)
		return (NULL);
	if(start>ft_strlen(s))
		return(ft_strdup(""));
	if(l>ft_strlen(s)-start)
		l = ft_strlen(s) - start;	
	subs = (char *)malloc(l+1);
	if(!subs)
		return (NULL);
	i = 0;
	while(s[start+i] && i<l)
	{
		subs[i]=s[start+i];
		i++;
	}
	subs[i]='\0';
	return (subs);
}

void	*ft_mmcpy(void	*des, void const *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t	i;

	d = (unsigned char	*)des;
	s = (unsigned char	*)src;
	if (!des && !src)
		return (NULL);
	i = 0;
	while(i < n)
	{
		d[i]=s[i];
		i++;
	}
	d[i]='\0';
	return (d);
}

int main(void)
{
    printf("--- Testing ft_strdup ---\n\n");

    // 1. Create a source string on the Stack
    char original[] = "Wolfsburg";
    
    // 2. Duplicate it onto the Heap
    char *duplicate = ft_strdup(original);

    if (!duplicate)
    {
        printf("Error: Malloc failed.\n");
        return (1);
    }

    // 3. Compare addresses (They MUST be different)
    printf("Addresses:\n");
    printf("Original address:  %p\n", (void *)original);
    printf("Duplicate address: %p\n", (void *)duplicate);
    
    if (original == duplicate)
        printf("FAIL: Both pointers point to the same memory!\n\n");
    else
        printf("SUCCESS: Duplicate is in a new memory location.\n\n");

    // 4. Compare content
    printf("Content:\n");
    printf("Original:  %s\n", original);
    printf("Duplicate: %s\n", duplicate);

    // 5. The "Independence" Test
    // Modify the original string. The duplicate should NOT change.
    original[0] = 'X';
    printf("\nAfter modifying original[0] to 'X':\n");
    printf("Original:  %s\n", original);
    printf("Duplicate: %s (Should still be Wolfsburg)\n", duplicate);

    // 6. Clean up the Heap
    free(duplicate);
    printf("\nMemory freed. Test complete.\n");

    return (0);
}