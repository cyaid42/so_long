/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:46:12 by msan              #+#    #+#             */
/*   Updated: 2024/01/24 04:30:45 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (ft_strdup(s2));
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[j++] = s1[i++];
	}
	i = 0;
	while (s2[i])
	{
		str[j] = s2[i];
		i++;
		j++;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!s[0])
		return (NULL);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	j = 0;
	i = start;
	while (len > 0 && s[i])
	{
		str[j] = s[i];
		j++;
		i++;
		len--;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strdup(char *str)
{
	int		i;
	int		slen;
	char	*dup;

	i = 0;
	slen = ft_strlen(str);
	dup = malloc(sizeof(char) * (slen + 1));
	if (!dup)
		return (0);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// size_t	ft_strlen(char *str)
// {
// 	int	i;

// 	if (!str)
// 		return (0);
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
