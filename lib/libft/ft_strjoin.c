/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alicigar < alicigar@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:52:07 by alicigar          #+#    #+#             */
/*   Updated: 2025/08/28 15:19:25 by alicigar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ns = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	while (s1[i])
	{
		ns[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		ns[j] = s2[i];
		j++;
		i++;
	}
	ns[j] = '\0';
	return (ns);
}

/*int	main(void)
{
	char	s1[] = "Madison";
	char	s2[] = " is an iconic and amazing woman";
	char	*r = ft_strjoin(s1, s2);
	printf("%s", r);
	free(r);
	return (0);
}*/
