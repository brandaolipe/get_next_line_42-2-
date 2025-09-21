/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:03:58 by febranda          #+#    #+#             */
/*   Updated: 2025/09/21 16:55:05 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;

	buffer = fill_buffer(buffer, fd);
	next_line = extract_line(buffer);
	buffer = rearrange_buffer(buffer);
	return (next_line);
}

char	*fill_buffer(char *buffer, int fd)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	if (!buffer)
		temp = ft_calloc(1, 1);
	else
	{
		temp = buffer;
	}
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	while (!ft_strchr(buffer, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		temp = ft_strjoin(temp, buffer);
	}
	buffer = temp;
	return (buffer);
}

char	*extract_line(char	*buffer)
{
	char	*new_line;
	int		len_new_line;
	int		i;

	i = 0;
	len_new_line = 0;
	while (buffer[i])
	{
		i++;
		if (buffer[i] == '\n')
			break ;
		len_new_line++;
	}
	i = 0;
	new_line = (char *)ft_calloc((len_new_line + 2), sizeof(char));
	//ft_strlcpy(new_line, buffer, len_new_line);
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
			break;
		}
		buffer++;
	}
	len_str = ft_strlen(buffer);
	str = ft_calloc((len_str + 1), sizeof(char));
	i = 0;
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	return (str);
}
