/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 03:36:42 by alicigar          #+#    #+#             */
/*   Updated: 2025/02/04 04:09:06 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_print_u(n / 10);
	write (1, &"0123456789"[n % 10], 1);
	count++;
	return (count);
}
