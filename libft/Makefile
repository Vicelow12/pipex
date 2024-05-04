NAME	=	libft.a

# Directories
SRC_DIR			= src/
OBJ_DIR			= obj/

CC	=	cc
RM	=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -I. -MMD -MP

SRCS	=	$(SRC_DIR)ft_atoi.c \
			$(SRC_DIR)ft_strdup.c  \
			$(SRC_DIR)ft_printf.c \
			$(SRC_DIR)printf_utility.c\
			$(SRC_DIR)ft_bzero.c\
			$(SRC_DIR)ft_calloc.c\
			$(SRC_DIR)ft_isalnum.c\
			$(SRC_DIR)ft_isalpha.c\
			$(SRC_DIR)ft_isascii.c\
			$(SRC_DIR)ft_isdigit.c\
			$(SRC_DIR)ft_isprint.c\
			$(SRC_DIR)ft_itoa.c\
			$(SRC_DIR)ft_memchr.c\
			$(SRC_DIR)ft_memcmp.c\
			$(SRC_DIR)ft_memcpy.c\
			$(SRC_DIR)ft_memmove.c\
			$(SRC_DIR)ft_memset.c\
			$(SRC_DIR)ft_putchar_fd.c\
			$(SRC_DIR)ft_putendl_fd.c\
			$(SRC_DIR)ft_putnbr_fd.c\
			$(SRC_DIR)ft_putstr_fd.c\
			$(SRC_DIR)ft_split.c\
			$(SRC_DIR)ft_strchr.c\
			$(SRC_DIR)ft_striteri.c\
			$(SRC_DIR)ft_strjoin.c\
			$(SRC_DIR)ft_strlcat.c\
			$(SRC_DIR)ft_strlcpy.c\
			$(SRC_DIR)ft_strlen.c\
			$(SRC_DIR)ft_strmapi.c\
			$(SRC_DIR)ft_strncmp.c\
			$(SRC_DIR)ft_strnstr.c\
			$(SRC_DIR)ft_strrchr.c\
			$(SRC_DIR)ft_strtrim.c\
			$(SRC_DIR)ft_substr.c\
			$(SRC_DIR)ft_tolower.c\
			$(SRC_DIR)ft_toupper.c\
			$(SRC_DIR)get_next_line.c\
			$(SRC_DIR)get_next_line_utils.c\
			$(SRC_DIR)ft_join_free_s1.c\

OBJS	= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))
DEPS    =       $(OBJS:.o=.d)

all:	$(NAME)
-include $(DEPS)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				mkdir -p $(@D)
				$(CC) $(CFLAGS) -c $< -o $@

clean:
				$(RM) -r $(OBJ_DIR) $(DEPS)
				$(RM) .cache_exists

fclean:		clean
				$(RM) $(NAME)

re:		fclean $(NAME)

.PHONY:		all clean fclean re bonus
