//
// Created by Denys Burtnjak on 3/24/17.
//

#include "libft.h"

static int	ft_h(char **buf, int s)
{
	unsigned long long nb;

	nb = 0;
	while (**buf != '\0' && (**buf >= '0' && **buf <= '9'))
	{
		nb = nb * 10 + (**buf - '0');
		(*buf)++;
		if (nb > 9223372036854775807 && s == -1)
			return (0);
		if (nb > 9223372036854775807)
			return (-1);
	}
	nb = nb * s;
	return ((int)nb);
}

int			cheak_nbr(char *temp, int nbr, int size)
{
	char	*buf;
	int		res;

	res = 1;
	buf = ft_itoa(nbr);
	if (ft_strncmp(temp, buf, size) == 0 && size > 0)
		res = 0;
	ft_strdel(&buf);
	return (res);
}

int			ft_atoi_move(char **buf, int *error, int move)
{
	int		s;
	char	*temp;

	temp = *buf;
	s = 1;
	while (**buf == ' ' || **buf == '\t' || **buf == '\v' || **buf == '\r' ||
		   **buf == '\f' || **buf == '\n')
	{
		(*buf)++;
		if (**buf == '\0')
			return (0);
	}
	if (**buf == '-')
	{
		s = -1;
		(*buf)++;
	}
	else if (**buf == '+')
		buf++;
	s = ft_h(buf, s);
	*error = cheak_nbr(temp, s, *buf - temp);
	*buf = move ? *buf : temp;
	return (s);
}
