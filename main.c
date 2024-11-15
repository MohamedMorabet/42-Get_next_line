/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-mora <mel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:45:40 by mel-mora          #+#    #+#             */
/*   Updated: 2024/11/15 10:46:09 by mel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	char	*s;
	int		i;
	int		fd;

	fd = open("text.txt", O_RDWR);
	i = 0;
	while (i < 14)
	{
		s = get_next_line(fd);
		printf("%s", s);
		i++;
	}
	close (fd);
	free (s);
	return (1);
}
