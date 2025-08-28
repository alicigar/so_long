/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 21:40:00 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 16:33:23 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_help(unsigned long num)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += count + ft_help(num / 16);
	write (1, &"0123456789abcdef"[num % 16], 1);
	count++;
	return (count);
}

int	ft_print_ptr(void *ptr)
{
	int				count;
	unsigned long	d;

	d = (unsigned long)ptr;
	count = 0;
	if (ptr == NULL)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write (1, "0x", 2);
	count += ft_help(d);
	return (count);
}
