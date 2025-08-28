/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 22:26:44 by alicigar          #+#    #+#             */
/*   Updated: 2024/12/21 23:37:21 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero (ptr, nmemb * size);
	return (ptr);
}

/*int	main(void)
{
	char *test = ft_calloc(5, sizeof(int));
	
	int	i = 0;
	while (i <= 5)
	{
		if (test[i] == 0)
			write(1, "C", 1);
		i++;
	}
	free(test);
	return (0);
}*/
