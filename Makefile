NAME = pipex

RM = rm -f
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -MMD -MP
LIBFT				= ./libft/libft.a


SRC =	pipex.c \
		env.c \
		exec.c \
		handle_error.c \


OBJS = $(SRC:%.c=%.o)
DEPS = $(OBJS:%.o=%.d)

all : $(NAME)

$(LIBFT): FORCE
					make -C ./libft

FORCE :

%.o : %.c
	$(CC) $(CFLAGS) -O3 -c $< -o $@

-include $(DEPS)

$(NAME) : $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean :
	$(RM) $(OBJS) $(DEPS)
	make clean -C ./libft

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)

re : fclean all

.PHONY : all clean fclean re