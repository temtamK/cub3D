/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:51:35 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 07:09:13 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elm;

	if (!lst || !f)
		return (NULL);
	if (!(new_elm = ft_lstnew(f(lst->content))))
		return (NULL);
	lst = lst->next;
	new_lst = new_elm;
	while (lst)
	{
		if (!(new_elm->next = ft_lstnew(f(lst->content))))
			ft_lstclear(&new_lst, del);
		lst = lst->next;
		new_elm = new_elm->next;
	}
	return (new_lst);
}
