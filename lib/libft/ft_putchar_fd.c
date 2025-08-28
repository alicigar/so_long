/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:59:03 by alicigar          #+#    #+#             */
/*   Updated: 2024/12/23 00:14:04 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h> 

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

/*int	main(void)
{
	int	fd = open("outp_.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	
	if (fd == -1)
	{
		write(2, "error\n", 6);
		return (1);
	}
	ft_putchar_fd('d', fd);
	
	close(fd);
	
	return (0);
}*/
