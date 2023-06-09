/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: averdon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:03:55 by averdon           #+#    #+#             */
/*   Updated: 2023/05/28 13:37:07 by averdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*duplicate_string;
	int		i;
	int		size_s;

	if (!s)
		return (NULL);
	size_s = ft_strlen(s) + 1;
	duplicate_string = ft_calloc(size_s, sizeof(char));
	if (!duplicate_string)
		return (NULL);
	i = 0;
	while (i < size_s)
	{
		duplicate_string[i] = s[i];
		if (s[i] == '\n')
		{
			duplicate_string[i + 1] = '\0';
			break ;
		}
		i++;
	}
	return (duplicate_string);
}

char	*concatenate_string(char *dest, const char *src)
{
	int	len_dest;
	int	i;

	i = 0;
	if (!dest[0])
		len_dest = 0;
	else
		len_dest = ft_strlen(dest);
	while (src[i])
	{
		dest[len_dest + i] = src[i];
		if (src[i] == '\n')
			break ;
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = ft_calloc(len_s1 + len_s2 + 2, sizeof(char));
	if (!new_s)
		return (NULL);
	concatenate_string(new_s, s1);
	if (new_s[ft_strlen(new_s)] == '\n')
	{
		new_s[ft_strlen(new_s) + 1] = '\0';
		return (new_s);
	}
	concatenate_string(new_s, s2);
	if (new_s[ft_strlen(new_s)] == '\n')
	{
		new_s[ft_strlen(new_s) + 1] = '\0';
		return (new_s);
	}
	new_s[len_s1 + len_s2] = '\0';
	return (new_s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*array;
	int		i;
	int		length;

	i = 0;
	length = size * nmemb;
	if (size != 0 && length / size != nmemb)
		return (NULL);
	array = malloc(length);
	if (!array)
		return (NULL);
	while (i < length)
	{
		array[i] = 0;
		i++;
	}
	return (array);
}
