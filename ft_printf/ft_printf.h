/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 07:54:34 by yousong           #+#    #+#             */
/*   Updated: 2023/11/10 07:57:04 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		ft_format(va_list ap, const char specifier);
int		ft_printchar(int c);
int		ft_printstr(char *str);
void	ft_putstr(char *str);
int		ft_printnbr(int n);
int		ft_printperc(void);
int		ft_printptr(unsigned long ptr);
void	ft_hexptr(unsigned long ptr);
int		ft_ptrlen(unsigned long ptr);
int		ft_printunsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_num_len(unsigned int n);
int		ft_printhex(unsigned int num, const char specifier);
void	ft_put_hex(unsigned int num, const char specifier);
int		ft_hex_len(unsigned int num);

#endif
