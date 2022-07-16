/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:05:57 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 13:42:14 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//memcpy와는 다르게 겹쳐도 된다. 기능은 memecpy와 같이 src를 dst에 len만큼 복사하는 함수이다.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	//src와 dst가 겹치는데 dst의 앞에서부터 겹친다면 실행되는 if 문이다.
	if (src < dst && dst < src + len)
	{
		//앞에서부터 겹치므로 src의 뒤부터 복사해준다.
		while (len > 0)
		{
			--len;
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
		}
		return (dst);
	}
	//src와 dst가 겹치는데 dst의 뒤에서부터 겹친다면 그냥 memcpy를 사용해서 복사하면 된다.
	return (ft_memcpy(dst, src, len));
}
