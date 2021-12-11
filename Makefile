CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
.PHONY =  all re clean fclean bonus push test main

src = 	ft_printf.c parser.c print_c.c print_s.c print_p.c print_di.c \
		print_u.c print_x.c miscellaneous.c

bonus_src =	 	ft_printf_bonus.c parser_bonus.c print_c_bonus.c \
				print_s_bonus.c print_p_bonus.c print_di_bonus.c \
				print_u_bonus.c print_x_bonus.c miscellaneous_bonus.c

libft_src = $(wildcard libft/*.c)

all: $(NAME)

$(NAME): $(src:.c=.o) $(libft_src:.c=.o)
	ar rcs $(NAME) $?

bonus: $(bonus_src:.c=.o) $(libft_src:.c=.o)
	ar rcs $(NAME) $?

re: fclean all

clean:
	rm -rf *.o
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)

push:
	git status
	git add .
	git commit -m "speedpush"
	git push
	git status

test:
	gcc $(CFLAGS) test.c 
	./a.exe

main:
	gcc $(CFLAGS) -ggdb main.c -L. -lftprintf
	./a.exe