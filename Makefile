NAME = philo

SRC_FILES = philo.c \
			philo_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all:$(NAME)
	@echo "make    ✅"

$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)
	@echo "clean   🌪️"

fclean: clean
	rm -f $(NAME)
	@echo "fclean  🔥"

re: fclean all

.SILENT:

.PHONY: all name clean fclean re