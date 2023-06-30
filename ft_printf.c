/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:04:04 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/06/30 17:25:59 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	counter; //to count the printed characters.

	va_star (args, s);
	counter = 0;
	while (*s == '%')
	{

	}
	va_end (args);
	return (counter);
}


/*
    *The printf function will write each character of the intial string,
    one by one, until it finds a %.
    *When it finds a %, it will look at the element in the next index/position.
    It will find the character that will define the type of the first variable
    argument.
    *Depending on what it finds, it will call a method that will display
    the argument of the particular type at output.
        -> if there is a "s" after the %, then you will need a function that displays strings.
        -> if there is a "d" after the %, then you will need a function that displays numbers.
        etc.
    *Once the first variable argument has been written, you go back to step 1,
    until the string is finished (aka, until you find a null character (\0)).
    *Don't forget to count the number of characters printed each time,
    in order to return the final number of characters at the end of the function.
*/
