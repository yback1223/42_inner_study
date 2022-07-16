/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:10:49 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 20:12:00 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	//일반 atoi 함수처럼 white space를 모두 밀어준다.
	while (*str == ' ' || (9 <= *str && *str <= 13)) 
		str++;
	//일반 atoi 함수도 부호가 하나만 나오므로 굳이 while을 돌리지 않고 if로 한 번만 처리해준다.
	if (*str == '+' || *str == '-')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9')
	{
		//while문으로 ret에 10을 곱해주면서 수를 밀어주는 형식으로 진행한다.
		ret = ret * 10 + (*str++ - '0');
		//이 프로젝트의 ft_atoi 함수 특성
		//ret의 값이 max값을 넘어가면 오버플로우가 발생하여 음수가 되는데 이때 다음의 if문이 실행된다.
		//원래의 숫자가 음수면 0, 양수면 -1을 리턴한다.
		if (ret < 0)
			return ((sign + 1) / -2);
	}
	return (sign * ret);
}
