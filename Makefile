NAME = push_swap
NAME2 = checker
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -rf
AR = ar
ARFLAGS = -rcs
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft
SRCS = push_swap.c \
	   check_exception.c \
	   get_stack_a.c \
	   get_string_array.c get_int_array.c \
	   sort_stack_a.c \
	   sort_under_thirty.c \
	   sort_over_thirty.c \
	   rough_sort_to_b.c quick_sort_to_a.c sort_three_in_stack_a.c \
	   commands_1.c commands_2.c \
	   control_node_1.c control_node_2.c \
	   ft_atoll.c \
	   check_perfectly_sorted.c check_first_second_node.c check_first_last_node.c \
	   check_max_min_location.c \
	   utils_1.c utils_2.c utils_3.c \
	   free_functions.c
SRCS_BONUS = checker.c \
			 check_exception.c \
			 get_stack_a.c \
			 get_string_array.c get_int_array.c ft_atoll.c \
			 get_command_and_execute.c \
			 commands_1.c commands_3.c \
			 control_node_1.c control_node_2.c \
			 check_perfectly_sorted.c \
			 utils_1.c utils_2.c \
			 free_functions.c
		
OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	TOTAL_NAME = $(NAME) $(NAME2)
else
	TOTAL_NAME = $(NAME)
endif

all : $(TOTAL_NAME)

$(NAME) : $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^ 

$(NAME2) : $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME2) $^

clean : 
	make -C $(LIBFT_DIR) clean
	$(RM) $(RMFLAGS) $(OBJS) $(OBJS_BONUS)

fclean : clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(RMFLAGS) $(NAME) $(NAME2)

re : fclean all

bonus :
	make WITH_BONUS=1

$(LIBFT) : 
	make bonus -C $(LIBFT_DIR) all

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
