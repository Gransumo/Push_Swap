CC		= gcc
CFLAGS	= -Wall -Werror -Wextra #-fsanitize=address -g
RM		= rm -f
NAME	= push_swap

AR		= ar rc

SRCS_A	= push_swap.c error.c parse.c utils.c moves.c init.c exceptions.c
SRCS	= $(addprefix src/, $(SRCS_A))

LIBFT_DIR	= ./libft/
LIBFT_A		= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

PRINTF_PATH	= ./libft/Printf/
PRINTF_A	= printf.a
PRINTF		= $(addprefix $(PRINTF_PATH), $(PRINTF_A))

OBJS	= ${SRCS:.c=.o}

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	${RM} ${OBJS} ${OBJS_B}
	$(MAKE) -C $(LIBFT_DIR) clean
fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY:	all clean fclean re bonus
