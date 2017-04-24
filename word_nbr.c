/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_nbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dburtnja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/24 13:04:54 by dburtnja          #+#    #+#             */
/*   Updated: 2017/04/24 13:05:08 by dburtnja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		word_nbr(char *buf)
{
	int		w_nbr;

	w_nbr = 0;
	while (*buf != 0)
	{
		while (*buf != 0 && *buf == ' ')
			buf++;
		w_nbr++;
		while (*buf != 0 && *buf != ' ')
			buf++;
	}
	return (w_nbr);
}
