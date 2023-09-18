CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -glldb
RM		= rm -f
NAME	= push_swap
SRCS	= push_swap.c error.c
OBJS	= ${SRCS:.c=.o}

AR		= ar rc

LIBFT_DIR	= ../libft/
LIBFT_A		= libft.a
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

all:	${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
	$(MAKE) -C $(LIBFT_DIR) bonus
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean: 
	${RM} ${OBJS} ${OBJS_B}
fclean:	clean
	${RM} ${NAME}
	$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY:	all clean fclean re bonus
