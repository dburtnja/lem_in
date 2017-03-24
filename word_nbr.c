//
// Created by Denys Burtnjak on 3/24/17.
//

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