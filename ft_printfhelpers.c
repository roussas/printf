#include "ft_printf.h"

int	length(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_base(uintptr_t nbr, int flag, char *base)
{
	int		len;
	int		counter;

	counter = 0;
	len = ft_strlen(base);
	if (flag == 1)
	{
		if (nbr == 0)
		{
			counter += write(1, "(nil)", 5);
			return (counter);
		}
		counter += write(1, "0x", 2);
	}
	if (nbr >= (uintptr_t)len)
		counter += ft_putnbr_base(nbr / len, 0, base);
	counter += write(1, &base[nbr % len], 1);
	return (counter);
}

int	cutdata(char c, va_list arg)
{
	char	*s;

	if (c == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), 1);
		return (1);
	}
	if (c == 's')
	{
		s = va_arg(arg, char *);
		if (s == 0)
			return (write(1, "(null)", 6));
		ft_putstr_fd(s, 1);
		return (ft_strlen(s));
	}
	if (c == 'p')
		return (ft_putnbr_base((uintptr_t)va_arg(arg, void *),
				1, "0123456789abcdef"));
	return (0);
}

int	shortdata(char c, va_list arg)
{
	int				i;
	unsigned int	u;

	if (c == 'd' || c == 'i')
	{
		i = va_arg(arg, int);
		ft_putnbr_fd(i, 1);
		return (length(i));
	}
	if (c == 'u')
	{
		u = va_arg(arg, unsigned int);
		return (ft_putnbr_base(u, 0, "0123456789"));
	}
	return (0);
}

int	data_type(char c, va_list arg)
{
	unsigned int	u;

	if (c == 'c' || c == 's' || c == 'p')
		return (cutdata(c, arg));
	if (c == 'd' || c == 'i' || c == 'u')
		return (shortdata(c, arg));
	if (c == 'x' || c == 'X')
	{
		u = va_arg(arg, unsigned int);
		if (c == 'x')
			return (ft_putnbr_base(u, 0, "0123456789abcdef"));
		return (ft_putnbr_base(u, 0, "0123456789ABCDEF"));
	}
	if (c == '%')
		return (write(1, "%", 1));
	return (0);
}
