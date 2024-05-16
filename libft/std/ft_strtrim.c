/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yublee <yublee@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:52:14 by yublee            #+#    #+#             */
/*   Updated: 2024/05/16 16:32:42 by yublee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	left;
	size_t	right;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	right = ft_strlen(s1) - 1;
	while (s1[left] && ft_charcheck((char *)set, s1[left]))
		left++;
	if (left < right)
		while (ft_charcheck((char *)set, s1[right]))
			right--;
	result = ft_substr(s1, left, right - left + 1);
	return (result);
}
