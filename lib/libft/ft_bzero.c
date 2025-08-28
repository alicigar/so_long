/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:56:19 by alicigar          #+#    #+#             */
/*   Updated: 2024/12/23 00:12:46 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n --)
	{
		*((char *)s) = 0;
		s++;
	}
}
/*int	main(void)
{
	char	str[] = "Good Night World";
	printf("%s\n", str);
	ft_bzero(str, 5);
	printf("%s\n", str);
	return (0);	
}*/
