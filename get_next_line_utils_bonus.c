/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 00:20:00 by ncarvalh          #+#    #+#             */
/*   Updated: 2022/11/14 00:21:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strclen(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(n + 1);
	if (!dup)
		return (NULL);
	while (s[i] && i < n)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	size;
	char	*res;

	i = 0;
	size = 0;
	if (s1)
		size = ft_strclen(s1, '\0');
	size += ft_strclen(s2, '\0') + 1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	if (s1)
		while (s1[i])
			*(res++) = s1[i++];
	res -= ft_strclen(s1, '\0');
	while (*s2)
		res[i++] = *(s2++);
	res[i] = '\0';
	if (s1)
		free(s1);
	return (res);
}
