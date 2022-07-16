/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yback <yback@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:47:59 by yback             #+#    #+#             */
/*   Updated: 2022/07/11 21:42:11 by yback            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//어디에도 이어지지 않은 새로운 list를 생성하는 함수
t_list	*ft_lstnew(void *content)
{
	t_list	*arr;

	arr = malloc(sizeof(t_list));
	if (!arr)
		return (0);
	//파라미터로 받은 content를 대입해준다.
	arr->content = content;
	//arr의 next에는 아직 아무것도 없으므로 널을 대입해준다.
	arr->next = 0;
	return (arr);
}
