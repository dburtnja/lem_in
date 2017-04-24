/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:13:33 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:13:34 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_str	*new_str_lst(char *str)
{
	t_str	*p;

	p = (t_str*)ft_memalloc(sizeof(t_str));
	p->str = str;
	p->next = NULL;
	return (p);
}

void	str_lst_add_back(t_str **head, t_str *new)
{
	t_str	*p;

	p = *head;
	if (p == NULL)
		*head = new;
	else
	{
		while (p->next)
			p = p->next;
		p->next = new;
	}
}

void	str_lst_add(t_str **head, t_str *new)
{
	if (*head == NULL)
		*head = new;
	else
	{
		new->next = *head;
		*head = new;
	}
}

void	print_and_dell_str_lst(t_str *head)
{
	t_str	*p;
	t_str	*temp;

	p = head;
	while (p)
	{
		ft_printf("%s\n", p->str);
		temp = p;
		p = p->next;
		ft_strdel(&(temp->str));
		ft_memdel((void**)&temp);
	}
	ft_putendl("");
}
