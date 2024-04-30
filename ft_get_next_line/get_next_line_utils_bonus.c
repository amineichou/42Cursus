/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:20:05 by moichou           #+#    #+#             */
/*   Updated: 2023/12/17 20:20:24 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *first, char *second)
{
	char	*res;
	int		i;
	int		j;

	if (!first || !second)
		return (NULL);
	res = malloc(sizeof(char) * (ft_strlen(first) + ft_strlen(second) + 1));
	if (!res)
		return (free(first), first = NULL, NULL);
	i = 0;
	j = 0;
	while (first[j])
		res[i++] = first[j++];
	j = 0;
	while (second[j])
		res[i++] = second[j++];
	res[i] = '\0';
	free(first);
	return (res);
}

int	ft_strsearch(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;
	int		str_len;

	if (!str)
		return (NULL);
	i = 0;
	str_len = ft_strlen(str);
	result = malloc(sizeof(char) * str_len + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
