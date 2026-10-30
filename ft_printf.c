/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 13:14:27 by username         #+#    #+#              */
/*   Updated: 2026/10/11 13:18:35 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
//#include <stdio.h>
//#include <limits.h>

int	ft_printf(const char *c, ...)
{
	int		i;
	va_list	arg;
	int		counter;

	counter = 0;
	va_start(arg, c);
	i = 0;
	while (c[i])
	{
		if (c[i] == '%' && c[i + 1] != '\0')
		{
			counter += data_type(c[i + 1], arg);
			i += 2;
			continue ;
		}
		if (c[i] == '\0')
			break ;
		ft_putchar_fd(c[i], 1);
		counter++;
		i++;
	}
	va_end(arg);
	return (counter);
}

/*
int main(void)
{
int x;
x = 42;
printf("\n========== TEST 1: BASIC ==========\n");
printf("REAL: char=%c str=%s d=%d i=%i\n", 'A', "hello", -42, 42);
ft_printf("MINE: char=%c str=%s d=%d i=%i\n", 'A', "hello", -42, 42);
printf("\n========== TEST 2: INTEGER LIMITS ==========\n");
printf("REAL: %d %d %d %d\n", INT_MIN, INT_MAX, 0, -1);
ft_printf("MINE: %d %d %d %d\n", INT_MIN, INT_MAX, 0, -1);
printf("\n========== TEST 3: UNSIGNED ==========\n");
printf("REAL: %u %u %u %u\n", 0u, 1u, UINT_MAX, (unsigned int)-20);
ft_printf("MINE: %u %u %u %u\n", 0u, 1u, UINT_MAX, (unsigned int)-20);
printf("\n========== TEST 4: HEXADECIMAL ==========\n");
printf("REAL: %x %X %x %X\n", 0u, 0u, UINT_MAX, UINT_MAX);
ft_printf("MINE: %x %X %x %X\n", 0u, 0u, UINT_MAX, UINT_MAX);
printf("\n========== TEST 5: POINTERS ==========\n");
printf("REAL: %p %p %p\n", (void *)0, (void *)&x, (void *)&main);
ft_printf("MINE: %p %p %p\n", (void *)0, (void *)&x, (void *)&main);
printf("\n========== TEST 6: STRINGS ==========\n");
printf("REAL: [%s] [%s] [%s]\n", "", "42 Vienna", (char *)0);
ft_printf("MINE: [%s] [%s] [%s]\n", "", "42 Vienna", (char *)0);
printf("\n========== TEST 7: MIXED ==========\n");
printf("REAL: %c|%s|%d|%i|%u|%x|%X|%p|%%\n",
'Z', "test", INT_MIN, INT_MAX, UINT_MAX, 0xabcdefu,
0xABCDEFu, (void *)&x);
ft_printf("MINE: %c|%s|%d|%i|%u|%x|%X|%p|%%\n",
'Z', "test", INT_MIN, INT_MAX, UINT_MAX, 0xabcdefu,
0xABCDEFu, (void *)&x);
printf("\n========== TEST 8: PERCENTAGES ==========\n");
printf("REAL: %%%% %%%%%%%% %c%%%%%s\n", 'A', "B");
ft_printf("MINE: %%%% %%%%%%%% %c%%%%%s\n", 'A', "B");
printf("\n========== TEST 9: ZERO AND EMPTY VALUES ==========\n");
printf("REAL: [%d][%i][%u][%x][%X][%s]\n", 0, 0, 0u, 0u, 0u, "");
ft_printf("MINE: [%d][%i][%u][%x][%X][%s]\n", 0, 0, 0u, 0u, 0u, "");
return (0);
}
*/
