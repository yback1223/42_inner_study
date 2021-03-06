/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 21:04:51 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 21:55:35 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//lst의 size를 구하는 함수
int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	//lst를 마지막까지 밀면서 count++을 해준다.
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
