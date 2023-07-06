/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:04:04 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/06 16:42:40 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_count_char(char s)
{
	write(1, &s, 1);
	return (1);
}

size_t	print_count_args(char *s, va_list args)
{
	size_t	counter;

	counter = 0;
	if (s == 'c')
		counter = put_count_char(va_arg(args, int));
	else if (s == 's')
		counter = put_count_str(va_arg(args, char *));
	else if (s == 'p')
		counter = put_count_ptr(va_arg(args, void *), HEX_BASE_LOW, 1);
	else if (s == 'd' || s == 'i')
		counter = put_count_nbr_base(va_arg(args, int), DEC_BASE);
	else if (s == 'u')
		counter = put_count_unbr_base(va_arg(args, unsigned int), DEC_BASE);
	else if (s == 'x')
		counter = put_count_unbr_base(va_arg(args, unsigned int),
				HEX_BASE_LOW);
	else if (s == 'X')
		counter = put_count_unbr_base(va_arg(args, unsigned int),
				HEX_BASE_UP);
	else if (s == '%')
		counter = put_count_char('%');
	return (counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	counter; //to count the printed characters.

	va_start (args, s);
	counter = 0;
	while (*s)
	{
		if (*s == '%')
		{
			counter += print_count_args(*++s, args);// to write the args.
			s++;
		}
		else
			counter += print_count_char(*s++);// print and count the characters.

	}
	va_end (args);
	return (counter);
}

int main()
{
	int count;
	int count2;

	count = ft_printf("Hello World");
	printf("%d \n", count);
	count2 = ft_printf("Hello World");
	printf("%d \n", count2);

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
