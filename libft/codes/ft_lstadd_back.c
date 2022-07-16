/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 10:56:17 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 20:52:48 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//list의 맨 뒤에 노드를 하나 추가해주는 함수
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	//lst나 new가 없다면 아무 기능을 발휘하지 못한다.
	if (!lst || !new)
		return ;
	//tmp에 lst의 마지막 노드를 대입해준다.
	tmp = ft_lstlast(*lst);
	//lst가 존재한다면, lst의 마지막 노드인 tmp의 next로 new를 대입해준다.
	//이렇게 하면 new가 lst의 맨 마지막 노드가 되는 것이다.
	if (*lst)
		tmp->next = new;
	//만약 lst가 널이라면 new노드가 lst의 첫 노드가 되는 것이다.
	else
		*lst = new;
}
