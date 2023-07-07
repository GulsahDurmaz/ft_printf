/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:25:56 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/07 13:46:58 by gdurmaz          ###   ########.fr       */
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

	nbr = (long)nbr;
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

size_t	put_count_unbr_base(unsigned int nbr, char *base)
{
	size_t	counter;
	int		base_len;

	nbr = (long long)nbr;
	base_len = ft_strlen(base);
	if (nbr > base_len)
		counter += put_count_nbr_base(nbr/base_len, base);
	counter += put_count_char(base[nbr % base_len]);
	return (counter);
}

size_t	put_count_ptr(void *ptr,char *base, int flag)
{
	unsigned long long	nbr;
	size_t				base_length;
	size_t				counter;

	nbr = (unsigned long long)ptr;
	base_length = ft_strlen(base);
	counter = 0;
	if (ptr == NULL)
	{
		counter += put_count_str(NIL_DISPLAY);
		return (counter);
	}
	if (flag == 1)
		counter += put_count_str(POINTER_PREFIX);
	if (nbr >= base_length)
		counter += put_count_ptr((void *)(nbr / base_length), base, 0);
	counter += put_count_char(base[nbr % base_length]);
	return (counter);
}
