/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:11:40 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:11:44 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	list_del(t_list *del)
{
	ft_memdel(&((del)->content));
	ft_memdel((void**)&del);
}

t_list	*remove_from_lst(t_list **head, t_list *rem)
{
	t_list	*p;

	p = *head;
	if (*head == rem)
		*head = (*head)->next;
	else if (p)
	{
		while (p->next && p->next != rem)
			p = p->next;
		if (p->next == rem)
			p->next = rem->next;
	}
	rem->next = NULL;
	return (rem);
}

void	rooms_add_back(t_rooms **alst, t_rooms *new)
{
	t_rooms	*p;

	p = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	room_add(t_rooms **alst, t_rooms *new)
{
	new->next = *alst;
	*alst = new;
}

t_rooms	*new_room(void)
{
	t_rooms *buf;

	buf = (t_rooms*)ft_memalloc(sizeof(t_rooms));
	if (buf == NULL)
		error(-1);
	return (buf);
}
