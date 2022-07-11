/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkabzins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 17:54:32 by rkabzins          #+#    #+#             */
/*   Updated: 2022/04/14 17:54:58 by rkabzins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	check_var(va_list args, const char type, int *output)
{
	if (type == 'c')
		ft_printf_char(va_arg(args, int), output);
	else if (type == 's')
		ft_printf_string(va_arg(args, char *), output);
	else if (type == 'p')
		ft_printf_numformat(va_arg(args, unsigned long), 17, output, false);
	else if (type == 'd' || type == 'i')
		ft_printf_int(va_arg(args, int), output);
	else if (type == 'u')
		ft_printf_numformat(va_arg(args, unsigned int), 10, output, false);
	else if (type == 'x')
		ft_printf_numformat(va_arg(args, unsigned int), 16, output, false);
	else if (type == 'X')
		ft_printf_numformat(va_arg(args, unsigned int), 16, output, true);
	else if (type == '%')
		ft_printf_char('%', output);
	else if (type != '\0')
		ft_printf_char(type, output);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		output;
	va_list	args;

	i = 0;
	output = 0;
	if (format == 0)
		return (0);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != 0)
		{
			i++;
			check_var(args, format[i], &output);
		}
		else if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else
			ft_printf_char(format[i], &output);
		i++;
	}
	va_end(args);
	return (output);
}
