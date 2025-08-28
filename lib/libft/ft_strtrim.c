/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 22:38:19 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/26 20:36:11 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*trim;

	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	j = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[j]))
		j--;
	trim = ft_substr(s1, i, j - i + 1);
	return (trim);
}

/*int	main(void)
{
	char	s1[] = "Benjamin Linus";
	char	s2[] = "njamin Linus";
	printf("%s", ft_strtrim(s1, s2));
	return(0);
}*/
