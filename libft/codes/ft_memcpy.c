/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:31:16 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 12:54:51 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//scr에서 사이즈 n만큼을 dst에 복사하는 함수
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	//src와 dst가 달라야 복사를 할 수 있다. (겹치면 안된다는 뜻)
	if (src != dst)
	{
		i = 0;
		while (i < n)
		{
			//겹치지 않는다면 복사를 진행한다.
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
