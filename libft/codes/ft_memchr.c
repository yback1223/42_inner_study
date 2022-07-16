/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:35:22 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 11:55:01 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//포인터 s에서 n 사이즈 동안 c가 나오는지 확인하는 함수이다. 반환값은 c가 처음 나오는 주소이다.
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned int	num;
	unsigned char	*arr;

	//man memchr을 보면 c를 unsigned char로 변형하라고 나와있다.
	num = (unsigned char)c;
	arr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (arr[i] == num)
			//반환은 (void *)로 해줘야 한다.
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
