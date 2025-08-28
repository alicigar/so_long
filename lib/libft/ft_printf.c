/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 17:26:24 by alicigar          #+#    #+#             */
/*   Updated: 2025/02/04 22:05:03 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_format(va_list *args, char format)
{
	int		count;

	count = 0;
	if (format == 'c')
		count += ft_print_c(va_arg(*args, int));
	if (format == 's')
		count += ft_print_s(va_arg(*args, char *));
	if (format == 'd' || format == 'i')
		count += ft_print_dec(va_arg(*args, int));
	if (format == 'u')
		count += ft_print_u(va_arg(*args, unsigned int));
	if (format == 'x')
		count += ft_print_hexa(va_arg(*args, unsigned int));
	if (format == 'X')
		count += ft_print_hexacaps(va_arg(*args, unsigned int));
	if (format == 'p')
		count += ft_print_ptr(va_arg(*args, void *));
	if (format == '%')
		count += ft_print_c(format);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	va_list	list;
	int		count;
	int		i;

	count = 0;
	i = 0;
	va_start(list, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			count += ft_format(&list, format[i + 1]);
			i++;
		}
		else
		{
			count += ft_print_c(format[i]);
		}
		i++;
	}
	va_end (list);
	return (count);
}
