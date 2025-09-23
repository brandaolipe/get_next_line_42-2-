/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:03:58 by febranda          #+#    #+#             */
/*   Updated: 2025/09/23 20:00:34 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	buffer = fill_buffer(buffer, fd);
	if (!buffer[0])
	{
		free(buffer);
		return (NULL);
	}
	next_line = extract_line(buffer);
	buffer = rearrange_buffer(buffer);
	return (next_line);
}

char	*fill_buffer(char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	temp = buffer;
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			return (NULL);
		}
		temp = ft_strjoin(temp, buffer);
		ft_bzero(buffer, BUFFER_SIZE);
		if (bytes_read < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	buffer = ft_strdup(temp);
	free(temp);
	return (buffer);
}

char	*extract_line(char	*buffer)
{
	char	*new_line;
	int		len_new_line;
	int		i;

	i = 0;
	len_new_line = 1;
	while (buffer[i])
	{
		i++;
		len_new_line++;
		if (buffer[i] == '\n')
			break ;
	}
	i = 0;
	new_line = ft_calloc((len_new_line + 1), sizeof(char));
	while (buffer[i])
	{
		new_line[i] = buffer[i];
		if (buffer[i] == '\n')
			break ;
		i++;
	}
	return (new_line);
}

char	*rearrange_buffer(char *buffer)
{
	char	*str;
	int		len_str;
	int		i;

	while (*buffer)
	{
		if (*buffer == '\n')
		{
			buffer++;
			break ;
		}
		buffer++;
	}
	len_str = ft_strlen(buffer);
	str = ft_calloc((len_str + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (buffer[i++])
		str[i] = buffer[i];
	buffer = ft_strdup(str);
	free(str);
	return (buffer);
}

void	ft_bzero(void *s, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0' ;
		i++;
	}
}
