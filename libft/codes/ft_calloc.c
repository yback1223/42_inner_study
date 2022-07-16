/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:27:52 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 20:25:09 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	mul; //count와 size의 곱을 저장할 변수
	void	*arr; //calloc 함수에서 결과값으로 반환될 포인터

	//이 프로젝트의 calloc 함수는 unsigned long의 max값의 제곱을 파라미터로 넣었을 때 널을 출력하게 만들어야 한다.
	if (count == 18446744073709551615UL && size == 18446744073709551615UL)
		return (0);
	mul = count * size;
	arr = malloc(mul);
	//널가드는 필수
	if (!arr)
		return (0);
	//메모리를 할당했으면 그 자리를 모두 0으로 초기화시켜준다.
	ft_bzero(arr, mul);
	return (arr);
}
