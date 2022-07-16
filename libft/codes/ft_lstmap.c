/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 14:13:34 by yback             #+#    #+#             */
/*   Updated: 2022/07/12 14:03:55 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//새로운 노드를 f함수를 적용시켜 계속 생성하는 함수이다. 중간에 문제가 생긴다면 모든 list를 제거하고 널을 반환
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*result;

	result = 0;
	while (lst)
	{
		//lst->content를 이용해서 새로운 노드를 만들어 tmp에 대입
		tmp = ft_lstnew((*f)(lst->content));
		//만약 tmp가 잘 만들어지지 않았다면 모든 result의 list를 del 함수로 제거
		if (!tmp)
		{
			ft_lstclear(&result, del);
			//제거하고 널을 반환한다.
			return (NULL);
		}
		//tmp가 잘 만들어졌다면 result의 뒤에 추가시킨다.
		ft_lstadd_back(&result, tmp);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (result);
}
