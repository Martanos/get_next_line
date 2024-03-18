/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:57:34 by malee             #+#    #+#             */
/*   Updated: 2024/03/18 16:36:21 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *str1, char *str2);
ssize_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strndup(char *str, size_t len);
char	*ft_strchr(const char *str, int element);
void	*fakelloc(size_t elementcount, size_t size);
ssize_t	read_to_buffer(int fd, char **payload, char *read_buffer,
			ssize_t *read_bytes);
char	*extract_line(char **payload);
void	buffer_clear(char *read_buffer);
#endif