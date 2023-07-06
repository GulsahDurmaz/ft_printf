/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:25:56 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/06 16:43:17 by gdurmaz          ###   ########.fr       */
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
