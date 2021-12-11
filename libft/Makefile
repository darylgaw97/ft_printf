mandatory =	ft_atoi.c ft_bzero.c ft_calloc.c \
			ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
			ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strdup.c ft_strtrim.c \
			ft_strncmp.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
			ft_tolower.c ft_toupper.c \
			ft_itoa.c ft_split.c ft_striteri.c \
			ft_strjoin.c ft_strmapi.c ft_substr.c \
			ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c

bonus = ft_lstadd_back.c ft_lstadd_front.c \
		ft_lstlast.c ft_lstnew.c ft_lstsize.c \
		ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstmap.c

mine = ft_putchar.c ft_putstr.c

.PHONY: all fclean clean re push

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(mandatory:.c=.o)
	ar rcs libft.a $?

bonus: $(bonus:.c=.o)
	ar rcs libft.a $?

mine: $(mine:.c=.o)
	ar rcs libft.a $?

re: fclean all

clean:
	rm -rf *.o

fclean: clean
	rm -rf *.o libft.a

push: fclean
	git status
	git add .
	git commit -m "speedpush"
	git push
	git status