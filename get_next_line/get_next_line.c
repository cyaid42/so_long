/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:46:16 by msan              #+#    #+#             */
/*   Updated: 2023/11/27 12:40:52 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_check_line(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	ft_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stock;
	char		*tmp;
	char		*ret;
	int			reader;

	reader = 1;
	if (BUFFER_SIZE < 1 || fd > 1024 || fd < 0)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	while (ft_check_line(stock) == 0 && reader > 0)
	{
		reader = read(fd, str, BUFFER_SIZE);
		tmp = stock;
		if (reader == -1)
			return (free(str), NULL);
		str[reader] = '\0';
		stock = ft_strjoin(tmp, str);
	}
	ret = ft_substr(stock, 0, ft_line(stock) + 1);
	tmp = stock;
	stock = ft_substr(tmp, ft_line(tmp)+1, (ft_strlen(tmp)-ft_line(tmp)));
	return (free(tmp), free(str), ret);
}
