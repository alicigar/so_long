/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:06:03 by alicigar          #+#    #+#             */
/*   Updated: 2024/12/23 00:13:37 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp_dest;
	unsigned char	*temp_src;
	unsigned int	i;

	if (!dest && !src)
		return (NULL);
	temp_src = (unsigned char *) src;
	temp_dest = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		temp_dest[i] = temp_src[i];
		i++;
	}
	return (dest);
}
/*int	main(void)
{
	char	dest[20] = "Hello World";
	char	src[20] = "Goodbye ";

	ft_memcpy(dest, src, 8);
	printf("%s", dest);
	return (0);
}*/
