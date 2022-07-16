/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:24:47 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 21:05:42 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	//del함수(삭제 기능을 가진 함수)로 해당 lst의 content을 삭제한다.
	if (del)
		del(lst->content);
	//free 함수로 lst을 아예 소멸시킨다.
	free(lst);
}
