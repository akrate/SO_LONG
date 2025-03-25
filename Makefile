NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror
MFLAGS = -L/usr/include/minilibx-linux/ -lmlx_Linux -lXext -lX11
RM = rm -rf
# SRC = test_event.c
SRC = cheking_map.c cheking_body.c ft_free.c main.c \
read_arg.c get_next_line/get_next_line_utils.c  get_next_line/get_next_line.c \
flood_fill.c use_elments_in_map.c movement.c chek_move.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(MFLAGS) -o $(NAME)

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)