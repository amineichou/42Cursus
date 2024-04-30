/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moichou <moichou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 21:16:19 by moichou           #+#    #+#             */
/*   Updated: 2023/12/18 10:00:55 by moichou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_strjoin(char *first, char *second);
int		ft_strsearch(char *str, char c);
char	*ft_strdup(char *str);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

#endif