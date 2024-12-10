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
	  ft_putstr.c \
	  errors.c\


NAME = pipex

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

OUTFILE = outfile

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OUTFILE)
fclean: clean
	rm -f $(NAME)
re: fclean all

.PHONY: clean fclean all re
