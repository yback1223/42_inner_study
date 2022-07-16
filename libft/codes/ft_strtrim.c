/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 13:31:31 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 19:45:18 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//set에 있는 요소를 s1에서 찾아 제거시킨 후에 남은 포인터의 부분을 반환하는 함수
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		start;
	size_t		end;
	size_t		s1_size;

	if (!s1 || !set)
		return (0);
	start = 0;
	s1_size = ft_strlen(s1);
	end = s1_size - 1;
	//start를 0부터 set의 요소 중에서 s1의 요소를 찾지 못할 때까지 민다.
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	//end를 마지막 인덱스부터 set의 요소 중에서 s1의 요소를 찾지 못할 때까지 민다.
	//주의할 점은 end가 start를 지나서 줄어들면 안된다.
	while (s1[end] && ft_strchr(set, s1[end]) && end > start)
		end--;
	//밀었던 start부터 end까지의 요소를 잘라서 반환해준다.
	return (ft_substr(s1, start, end - start + 1));
}
