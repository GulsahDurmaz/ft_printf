/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:25:56 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/06 19:50:50 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	put_count_char(int s)
{
	write(1, &s, 1);
	return (1);
}

size_t	put_count_str(char *s)
{
	size_t	counter;

	if (s == NULL)
	{
		write(1, NULL_DISPLAY, ft_strlen(NULL_DISPLAY));
		return (ft_strlen(NULL_DISPLAY));
	}
	counter = 0;
	while (*s)
	{
		write(1, s++, 1);
		counter++;
	}
	return (counter);
}

size_t	put_count_nbr_base(int nbr, char *base)
{
	size_t	counter;
	int	base_len;

	nbr = (long long)nbr;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		counter += put_count_char('-');
		nbr *= -1;
	}
	if (nbr > base_len)
		counter += put_count_nbr_base(nbr/base_len, base);
	counter += put_count_char(base[nbr % base_len]);
	return (counter);
}
