/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 12:41:24 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 19:40:01 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//s에서 c를 찾아서 그 s상의 주소를 반환
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*start;
	
	//s의 시작 주소를 start에 대입
	start = (char *)s;
	i = 0;
	//s의 마지막 주소를 넘어 널자리까지 민다.
	while (*s++)
		;
	//s에서 c를 찾을 때까지 s의 주소를 앞으로 당긴다.
	while (--s != start && *s != (char)c)
		;
	//만약 s에서 c를 찾았다면 그 주소를 반환
	if (*s == (char)c)
		return ((char *)s);
	//s에서 c를 못 찾았다면 널을 반환
	return (NULL);
}
