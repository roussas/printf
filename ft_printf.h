#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdint.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *c, ...);
int	cutdata(char c, va_list arg);
int	shortdata(char c, va_list arg);
int	data_type(char c, va_list arg);
int	ft_putnbr_base(uintptr_t nbr, int flag, char *base);
int	length(int n);

#endif
