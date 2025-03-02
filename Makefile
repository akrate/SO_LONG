NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRC = cheking_map.c cheking_body.c ft_free.c main.c \
read_arg.c get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)