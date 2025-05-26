/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:13:42 by alejogogi         #+#    #+#             */
/*   Updated: 2025/03/28 15:26:46 by alejogogi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_cases(va_list args, char c)
{
	int	b;

	b = 0;
	if (c == 'c')
		b += ft_putchar(va_arg(args, int));
	else if (c == 's')
		b += ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		b += ft_putpointer(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		b += ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		b += ft_putunbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		b += ft_puthex(va_arg(args, unsigned int), c);
	else if (c == '%')
		b += ft_putchar('%');
	return (b);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		ln;

	i = 0;
	ln = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ln += ft_cases(args, str[i + 1]);
			i++;
		}
		else
			ln += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ln);
}

/* int main()
{
	char	*c;
	int	s;
	int	a;
	char	b;
	int	f;
	char	p;
	int	k;
	int	ln;

	c = "hola";
	s = 22;
	b = 'a';
	f = 456251;
	p = 'a';
	k = -45236;
	ln = 0;
	
	ln += ft_printf("esto imprime %s\n num %d char %%\n", c, s);
	ln += ft_printf("base hexadecimal %x\n", f);
	ln += ft_printf("puntero %p\n", p);
	ln += ft_printf("negativo %i\n", k);
	ft_printf("longitud %d", ln);
	return(0);
} */