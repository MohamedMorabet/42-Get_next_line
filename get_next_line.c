/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:31:17 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/15 12:36:55 by mel-mora         ###   ########.fr       */
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
	char		*tmp;
	ssize_t		bytes_read;
	static char	p[BUFFER_SIZE + 1];

	s = NULL;
	if (fd > 0)
	{
		while (1)
		{
			bytes_read = read(fd, p, BUFFER_SIZE);
			if (bytes_read <= 0)
				break ;
			p[bytes_read] = '\0';
			if (didnt_reach_end(p) != 1)
				break;
			tmp = ft_strjoin(s, p);
			if (s)
				free (s);
			s = tmp;
		}
		s = ft_strjoin(s, ft_substr(p, 0, bytes_read));
		free (tmp);
	}
	return (s);
}
