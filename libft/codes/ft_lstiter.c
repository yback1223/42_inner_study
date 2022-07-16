/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:58:02 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 21:22:37 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//lst의 모든 content에 f함수를 적용시키는 함수
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	//lst를 밀면서 f함수를 lst의 content에 적용시킨다.
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
