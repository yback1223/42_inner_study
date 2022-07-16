/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 16:00:32 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 20:46:59 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//숫자의 사이즈를 측정하는 함수
int	insize(long long num)
{
	int	i;

	i = 0;
	//0은 길이가 1이므로 1을 반환
	if (num == 0)
		return (1);
	//num이 음수라면 '-'의 자리를 확보한 후에 계산하기 쉽게 -1을 곱해줘야 한다.
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	//num을 계속 10으로 나눠주면서 i값으로 크기를 잰다.
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

//본격적으로 int값을 문자열로 변형시키는 함수
void	func(char *arr, long long num, int size)
{
	//계산을 쉽게하기 위해 num이 음수라면 양수로 바꿔준다.
	if (num < 0)
		num *= -1;
	while (size >= 0)
	{
		//num을 10으로 나눈 나머지에 '0'을 더해서 문자로 만든 후에 배열의 끝에서부터 대입해준다.
		arr[size--] = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	int			size; //숫자의 사이즈
	//-2147483648에 -1을 곱하면 오버플로우가 생기기 때문에 이를 방지하기 위해 long long 변수 선언
	long long	num; 
	char		*arr; //문자열을 저장할 배열 선언

	num = n; //일단 int형인 n을 long long형으로 변형시킨다.
	size = insize(num);//num의 사이즈를 구해서 동적 할당으로 arr의 크기를 보장해준다.
	arr = (char *)malloc(sizeof(char) * size + 1);
	if (!arr)
		return (0);
	//먼저 arr의 맨 끝 자리에 널을 넣어줘서 문자열의 특성을 갖춰준다.
	arr[size--] = '\0';
	//만약 n이 0이라면 다른 함수가 필요없이 0만 출력하면 되므로 arr값에 0을 넣어줘서 arr를 반환한다.
	if (n == 0)
	{
		arr[size] = '0';
		//반환 값으로 동적 할당을 마친 arr을 반환해줘야 한다.
		return (arr);
	}
	func(arr, num, size);
	//n이 음수라면 첫 자리에 '-'를 붙여준다.
	if (n < 0)
		arr[0] = '-';
	return (arr);
}
