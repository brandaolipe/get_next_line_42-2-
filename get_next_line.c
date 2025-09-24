/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:03:58 by febranda          #+#    #+#             */
/*   Updated: 2025/09/24 19:50:20 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = fill_buffer(buffer, fd);
	if (!buffer || (!buffer[0]))
		return (NULL);
	next_line = extract_line(buffer);
	buffer = rearrange_buffer(buffer);
	return (next_line);
}

char	*fill_buffer(char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	temp =  ft_calloc((BUFFER_SIZE + 1), sizeof(char)); 
	if (!buffer)
		buffer = ft_strdup("");
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		buffer = ft_strjoin(buffer, temp);
		ft_bzero(temp, BUFFER_SIZE);
	}
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
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	str = ft_strdup(&buffer[i]);
	free(buffer);
	return (str);
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
