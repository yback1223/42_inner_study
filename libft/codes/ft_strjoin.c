/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:21:05 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 14:43:34 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1과 s2를 이어주는 함수
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*arr;
	int		i;
	int		tmp_i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!arr)
		return (0);
	while (s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	tmp_i = i;
	i = 0;
	while (s2[i])
		arr[tmp_i++] = s2[i++];
	arr[tmp_i] = 0;
	return (arr);
}
