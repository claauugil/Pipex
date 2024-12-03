SRC = pipex.c \
	  pipex_utils.c \
	  ft_bzero.c \
	  ft_split.c \
	  ft_strdup.c \
	  ft_strjoin.c \
	  ft_calloc.c \
	  ft_strlcpy.c \
	  ft_strlen.c \
	  ft_substr.c \
	  ft_strncmp.c \

NAME = pipex

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re
