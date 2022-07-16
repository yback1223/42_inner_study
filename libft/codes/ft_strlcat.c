/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:17:11 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 15:03:38 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//dst 뒤에 src를 붙이는 함수, 총 목표 사이즈는 dstsize이고 널 자리를 생각해줘야 한다.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	//일단 dst뒤에 붙여야하므로 i를 밀어준다.
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize > 0)
	{	
		//dstsize - 1을 통해서 널 자리를 만들어주고, src를 dst에 대입해준다.
		while (*src && i < dstsize - 1)
			dst[i++] = *src++;
		//dst에 널 대입
		if (i < dstsize)
			dst[i] = '\0';
	}
	while (*src++)
		i++;
	return (i);
}
