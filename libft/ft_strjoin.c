/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:36:07 by rkabzins          #+#    #+#             */
/*   Updated: 2022/02/18 01:36:44 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*dest;
	size_t			s1_size;
	size_t			s2_size;
	unsigned int	s2_index;
	unsigned int	s1_index;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	s1_index = 0;
	s2_index = 0;
	dest = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!dest)
		return (NULL);
	while (s1[s1_index])
	{
		dest[s1_index] = s1[s1_index];
		s1_index++;
	}
	while (s2[s2_index])
		dest[s1_index++] = s2[s2_index++];
	dest[s1_index] = 0;
	return (dest);
}
