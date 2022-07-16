/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:36:14 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 21:18:02 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//lst를 기점으로 이어진 모든 list를 삭제하는 함수
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst)
		return ;
	//lst가 널을 만날 때까지, 즉 list의 끝까지 while문을 진행	
	while (*lst)
	{
		//tmp에 잠시 lst의 next값을 저장
		tmp = (*lst)->next;
		//lstdelone함수로 필요없어진 lst를 del함수로 제거한다.
		ft_lstdelone(*lst, del);
		//tmp에 담아뒀던 lst의 next값을 lst의 주소에 넣어줘서 첫 노드로 만들어준다.
		*lst = tmp;
	}
}
