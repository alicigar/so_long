/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:02:51 by alicigar          #+#    #+#             */
/*   Updated: 2024/12/23 00:15:44 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src [i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*int	main(void)
{
	char	src[] = "naviduki";
	char	dst[10];
	size_t	r;
	r = ft_strlcpy(dst, src, 5);
	printf ("%zu\n", r);
	printf ("%s\n", dst);
	return (0);
}*/
