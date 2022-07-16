/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:53:43 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 12:03:27 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s1과 s2가 같다면 0을 반환, 다르다면 다른 지점에서의 ascii 코드 값의 차를 반환
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (i < n)
	{
		diff = ((const unsigned char *)s1)[i] - ((const unsigned char *)s2)[i];
		//ascii 코드 값의 차가 생긴다면 while 문을 벗어난다.
		if (diff)
			break ;
		i++;
	}
	return (diff);
}
