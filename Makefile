NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
AR = ar
ARFLAGS = -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = push_swap.c \
	   check_exception.c initialize_stack_a.c \
	   commands.c \
	   control_node.c \
	   sort_until_sorted.c \
	   put_everynode_to_stack_a.c \
	   get_string_array.c get_int_array.c get_stack_a.c ft_atoll.c \
	   check_perfertly_sorted.c check_first_second_node.c check_first_last_node.c \
	   check_if_sorted_stack_b.c check_max_min_location.c \
	   utils_1.c utils_2.c \
	   free_functions.c
		
OBJS = $(SRCS:.c=.o)

all : $(NAME) 

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
