/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:10:43 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 14:05:39 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//write 함수를 사용해서 c를 출력하는 함수
void	ft_putchar_fd(char c, int fd)
{
	//fd는 0을 포함한 양수여야 한다.
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
