/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:31:17 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/15 10:41:43 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	didnt_reach_end(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (p[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char		*s;
	ssize_t		bytes_read;
	static char	p[BUFFER_SIZE + 1];

	s = NULL;
	if (fd > 0)
	{
		read(fd, p, BUFFER_SIZE);
		while (didnt_reach_end(p) == 1)
		{
			s = ft_strjoin(s, p);
			bytes_read = read(fd, p, BUFFER_SIZE);
			if (bytes_read <= 0)
				break ;
		}
		s = ft_strjoin(s, ft_substr(p, 0, bytes_read));
	}
	return (s);
}
