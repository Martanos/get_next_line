/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:38:05 by malee             #+#    #+#             */
/*   Updated: 2024/03/18 16:09:35 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*ft_strjoin(char *str1, char *str2);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_strndup(char *str, size_t len);
char	*ft_strchr(const char *str, int element);
void	*fakelloc(size_t elementcount, size_t size);
ssize_t	read_to_buffer(int fd, char **payload, char *read_buffer);
char	*extract_line(char **payload);
void	buffer_clear(char *read_buffer);
#endif