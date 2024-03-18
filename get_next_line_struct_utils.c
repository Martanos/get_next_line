/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_struct_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:30:09 by malee             #+#    #+#             */
/*   Updated: 2024/03/18 17:30:27 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_struct.h"

ssize_t	ft_strlen(char *str)
{
	char	*ptr;

	if (!str)
		return (-1);
	ptr = str;
	while (*ptr)
		ptr++;
	return (ptr - str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	len1;
	size_t	len2;
	char	*output;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	output = fakelloc(len1 + len2 + 1, sizeof(char));
	if (!output)
		return (NULL);
	while (len2--)
		output[len1 + len2] = str2[len2];
	while (len1--)
		output[len1] = str1[len1];
	return (output);
}

char	*ft_strndup(char *str, size_t len)
{
	char	*dupper;
	size_t	count;

	if (!str)
		return (NULL);
	dupper = fakelloc(len + 1, sizeof(char));
	if (!dupper)
		return (NULL);
	count = 0;
	while (count < len)
	{
		dupper[count] = str[count];
		count++;
	}
	return (dupper);
}

char	*ft_strchr(const char *str, int element)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == element)
			return ((char *)str);
		str++;
	}
	return (NULL);
}

void	*fakelloc(size_t elementcount, size_t size)
{
	char	*array;

	array = malloc(elementcount * size);
	if (!array)
		return (NULL);
	while (elementcount > 0)
		array[--elementcount] = '\0';
	return ((void *)array);
}
