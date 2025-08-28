/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexacaps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 02:32:13 by alicigar          #+#    #+#             */
/*   Updated: 2025/02/04 02:35:30 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hexacaps(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 16)
		count += count + ft_print_hexacaps(num / 16);
	write (1, &"0123456789ABCDEF"[num % 16], 1);
	count++;
	return (count);
}
