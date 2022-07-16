/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:04:55 by yback             #+#    #+#             */
/*   Updated: 2022/07/13 16:25:33 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//haystack에 needle이 있는지 len만큼 비교하는 함수
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;

	//needle의 길이를 구해준다.
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	//haystack이 존재하고 len이 needle_len이상이라면 while문 실행
	//haystack의 첫 주소부터 len만큼만 검사를 해야하는데 len 길이를 검사하면서 중간에 needle의 시작점을 찾지 못하는데 len이 끝나면 검사할 needle이 없기 때문에 while 문을 나가서 null이 된다.
	while (*haystack && len >= needle_len)
	{
		//사이즈 안에서 haystack과 needle이 동일하다면 haystack의 현 주소를 반환한다.
		if (ft_strncmp(haystack, needle, needle_len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	//haystack이 존재하지 않거나 len이 needle_len미만이라면 널을 반환한다.
	return (NULL);
}

