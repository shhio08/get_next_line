/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stakimot <stakimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:32:12 by stakimot          #+#    #+#             */
/*   Updated: 2023/01/07 20:43:43 by stakimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	cnt;

	if (!s)
		return (NULL);
	cnt = 0;
	while (s[cnt])
	{
		if (s[cnt] == (char)c)
			return ((char *)&s[cnt]);
		cnt++;
	}
	if (!c)
		return ((char *)&s[cnt]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	cnt;

	if (!str)
		return (0);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	cnt;

	cnt = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (*s1)
		dest[cnt++] = *s1++;
	while (*s2)
		dest[cnt++] = *s2++;
	dest[cnt] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	char	*src;
	size_t	cnt;

	src = (char *)s1;
	cnt = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (cnt + 1));
	if (!dest)
		return (NULL);
	cnt = 0;
	while (src[cnt])
	{
		dest[cnt] = src[cnt];
		cnt++;
	}
	dest[cnt] = '\0';
	return (dest);
}
