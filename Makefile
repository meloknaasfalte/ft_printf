NAME = libftprintf.a

LIBFT = libft

COMP = gcc -Wall -Werror -Wextra

HEADERS = headers

SRCS = ft_printf.c unsigned_int.c utils.c hex.c utils2.c pointer.c parser.c

OBJS = $(SRCS:.c=.o)

all: ${NAME}

dev: ${NAME}
	gcc main.c ${NAME} && ./a.out

${NAME}: $(OBJS)
	@make -C ${LIBFT}
	@cp libft/libft.a ./${NAME}
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c
				@gcc -c -o $@ $< -I ${HEADERS}

clean:
	@rm -f ${OBJS} ${HEADER}.gch

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
