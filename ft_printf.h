/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdurmaz <gdurmaz@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:52:06 by gdurmaz           #+#    #+#             */
/*   Updated: 2023/07/14 15:04:27 by gdurmaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define NULL_DISPLAY "(null)"
# define DEC_BASE "0123456789"
# define HEX_BASE_LOW "0123456789abcdef"
# define HEX_BASE_UP "0123456789ABCDEF"
# define POINTER_PREFIX "0x"
# define NIL_DISPLAY "(nil)"

int		ft_printf(const char *s, ...);
size_t	put_count_char(int s);
size_t	put_count_str(char *s);
size_t	put_count_nbr_base(int nbr, char *base);
size_t	put_count_unbr_base(unsigned int nbr, char *base);
size_t	put_count_ptr(void *ptr, char *base, int flag);
size_t	ft_strlen(const char *str);

#endif
