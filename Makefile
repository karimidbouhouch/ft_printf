NAME = libftprintf.a
SRC = 	ft_printf.c\
		ft_putchar.c\
		ft_puthex_lower.c\
		ft_puthex_upper.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_strlen.c
INC = ft_printf.h
CFLAGS = -Wall -Werror -Wextra
OBJ=$(SRC:%.c=%.o)
all: $(NAME)
$(NAME): $(OBJ)
	gcc -c $(CFLAGS) $(SRC) -I $(INC)
	ar -rc $(NAME) $(SRC)
clean: 
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all