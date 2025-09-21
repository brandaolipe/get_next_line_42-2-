/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: febranda <febranda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:20:33 by febranda          #+#    #+#             */
/*   Updated: 2025/09/21 15:25:43 by febranda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 7
# endif

char	*get_next_line(int fd);
char	*fill_buffer(char *buffer, int fd);

char	*ft_strchr(const char *str, int letter);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
char	*extract_line(char	*buffer);
char	*rearrange_buffer(char *buffer);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
