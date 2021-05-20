/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taemkim <taemkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 00:47:49 by taemkim           #+#    #+#             */
/*   Updated: 2021/05/20 06:39:16 by taemkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Checks if base is valid.
*/

static int	ft_check_base(char *base)
{
	int i;
	int j;

	i = -1;
	while (base[++i])
	{
		j = i;
		if (('*' <= base[i] && base[i] <= '/') || base[i] == 37)
			return (0);
		if (!(base[i] && (33 <= base[i] && base[i] <= 126)))
			return (0);
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	if (i < 2)
		return (0);
	return (i);
}

int			ft_putnbr_base_int(int nbr, char *base,
	ssize_t (*my_write)(int, const void *, size_t))
{
	int base_type;
	int count;

	count = 0;
	if (!((base_type = ft_check_base(base))))
		return (0);
	if (nbr == -2147483648)
	{
		count += ft_putnbr_base_int(-214748364, base, (*my_write));
		return (count + my_write(1, &base[8], 1));
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		count += my_write(1, "-", 1);
	}
	if (nbr < base_type)
		count += my_write(1, &base[nbr], 1);
	else
	{
		count += ft_putnbr_base_int(nbr / base_type, base, (*my_write));
		count += ft_putnbr_base_int(nbr % base_type, base, (*my_write));
	}
	return (count);
}

int			ft_putnbr_base_u(size_t nbr, char *base,
	ssize_t (*my_write)(int, const void *, size_t))
{
	size_t	base_type;
	int		count;

	count = 0;
	if (!(base_type = ft_check_base(base)))
		return (0);
	if (nbr == (size_t)-2147483648)
	{
		count += ft_putnbr_base_u((size_t)-214748364, base, (*my_write));
		count += my_write(1, &base[8], 1) + 1;
	}
	if (nbr < base_type)
		count += my_write(1, &base[nbr], 1);
	else
	{
		count += ft_putnbr_base_u(nbr / base_type, base, (*my_write));
		count += ft_putnbr_base_u(nbr % base_type, base, (*my_write));
	}
	return (count);
}
