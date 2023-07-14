/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:04:04 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/14 15:01:14 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_count_char(char s)
{
	write(1, &s, 1);
	return (1);
}

size_t	print_count_args(char s, va_list args)
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
	size_t	counter;

	va_start (args, s);
	counter = 0;
	while (*s)
	{
		if (*s == '%')
		{
			counter += print_count_args(*++s, args);
			s++;
		}
		else
			counter += print_count_char(*s++);
	}
	va_end (args);
	return (counter);
}
/*
int main()
{
	int count;
	int count2;
	int count3;
	int count4;
	int count5;
	int count6;
	int count7;
	int count8;
	int count9;
	int count10;
	int count11;

	count9 = 123;
	count = ft_printf("Hello World\n");
	printf("%d \n", count);
	count2 = ft_printf("Hello World\n");
	printf("%d \n", count2);
	count3 = ft_printf("%d \n", 12334 );
	printf("%d \n", count3);
	count4 = printf("%d \n", 12334 );
	printf("%d \n", count4);
	count5 = ft_printf("%u \n", 123456789);
	printf("%d \n", count5);
	count6 = printf("%u \n", 123456789);
	printf("%d \n", count6);
	count7 = ft_printf("%u \n", 0xABCDEF);
	printf("%d \n", count7);
	count8 = printf("%u \n", 0xABCDEF);
	printf("%d \n", count8);
	count10 = ft_printf("%p \n", count9);
	printf("%d \n", count10);
	count11 = ft_printf("%p \n", count9);
	printf("%d \n", count11);

}
*/
