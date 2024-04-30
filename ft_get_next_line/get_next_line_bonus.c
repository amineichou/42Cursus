/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:19:22 by moichou           #+#    #+#             */
/*   Updated: 2023/12/19 14:32:46 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_read(int fd, char *result)
{
	char	*buffer;
	int		count;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (free(result), result = NULL, NULL);
	count = 1;
	while (ft_strsearch(result, '\n') == 0 && result[0] != '\n')
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
			return (free(buffer), free(result), NULL);
		if (count == 0)
			break ;
		buffer[count] = '\0';
		result = ft_strjoin(result, buffer);
		if (!result)
			break ;
	}
	return (free(buffer), result);
}

static char	*ft_extract_line(char *result)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (result[i] != '\n' && result[i])
		i++;
	if (result[i] == '\n')
		i++;
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < i)
	{
		str[j] = result[j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

static char	*ft_extract_rest(char *result)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (result[i] != '\n' && result[i])
		i++;
	if (result[i] == '\n')
		i++;
	str = malloc(sizeof(char) * ft_strlen(result + i) + 1);
	if (!str)
		return (free(result), result = NULL, NULL);
	j = 0;
	while (result[i] != '\0')
	{
		str[j] = result[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (free(result), result = NULL, str);
}

char	*get_next_line(int fd)
{
	static char	*result[OPEN_MAX];
	char		*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	if (!result[fd])
	{
		result[fd] = ft_strdup("");
		if (!result[fd])
			return (NULL);
	}
	result[fd] = ft_read(fd, result[fd]);
	if (!result[fd])
		return (NULL);
	if (result[fd][0] == '\0')
		return (free(result[fd]), result[fd] = NULL, NULL);
	line = ft_extract_line(result[fd]);
	if (!line)
		return (free(result[fd]), result[fd] = NULL, NULL);
	result[fd] = ft_extract_rest(result[fd]);
	if (!result[fd])
		return (free(line), result[fd] = NULL, NULL);
	return (line);
}
