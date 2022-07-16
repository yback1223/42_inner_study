/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:59:59 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 20:11:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s 포인터의 start 부분부터 len만큼 자른 포인터를 반환하는 함수
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*src;
	char		*arr;
	size_t		src_len;
	size_t		dst_len;

	if (!s)
		return (0);
	src_len = ft_strlen(s);
	//s의 길이보다 시작점이 더 뒤에 있다면 start에 src의 길이를 대입한다.
	if (start > src_len)
		start = src_len;
	//s의 start	부분 전은 필요가 없으므로 새로운 포인터를 선언해서 s의 start부분의 포인터를 반환한다.
	src = s + start;
	//새로 만든 포인터의 길이를 측정한다.
	dst_len = ft_strlen(src);
	//만약 len보다 dst_len이 더 길다면 len을 dst_len에 대입해준다.
	if (dst_len > len)
		dst_len = len;
	arr = ft_calloc(dst_len + 1, sizeof(char));
	if (!arr)
		return (0);
	ft_memcpy(arr, src, dst_len);
	arr[dst_len] = '\0';
	return (arr);
}
