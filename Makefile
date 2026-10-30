NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror
CC = cc

LIBFT = libft/libft.a

SRCS = ft_printf.c ft_printfhelpers.c
OBJS = ft_printf.o ft_printfhelpers.o

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(CFLAGS) -I libft -c $< -o $@

clean :
	rm -f $(OBJS)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean
	make all

.PHONY : all clean fclean re 
