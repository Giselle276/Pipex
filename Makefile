NAME = pipex
SRC = pipex.c \
		pipex_utils.c\
		errors.c\
		ft_memcpy.c\
		ft_putstr.c\
		ft_split.c\
		ft_strjoin.c\
		ft_strlcpy.c\
		ft_strlen.c\
		ft_strncmp.c\



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
