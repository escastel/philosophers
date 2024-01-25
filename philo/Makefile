NAME = philo

PHILO = philo.a

FILES = philo.c \
utils.c \
check_and_save.c \

OBJECTS = $(FILES:.c=.o)

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME):			$(OBJECTS)
						@ ar rcs $(PHILO) $(OBJECTS)
						@ gcc $(FLAGS) $(PHILO) -o $(NAME)

$(OBJECTS):			%.o : %.c 
						@ gcc $(FLAGS) -c $< -o $@

all: 				$(NAME)

clean:
						@ rm -f $(OBJECTS)

fclean:
						@ rm -f $(NAME) $(OBJECTS) $(PHILO)

re: fclean all

.PHONY: all re clean fclean
