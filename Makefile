NAME = libftprintf.a

INC = ft_printf.h

SRC = 	ft_printf.c\
		ft_putchar.c\
		ft_puthex_lower.c\
		ft_puthex_upper.c\
		ft_putnbr.c\
		ft_putstr.c\
		ft_putdec.c\
		ft_putadr.c
CFLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INC)
	gcc -c $(CFLAGS) $(SRC) -I $(INC)
	ar -rc $(NAME) $(OBJ)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all