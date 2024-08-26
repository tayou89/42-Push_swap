NAME = push_swap
NAME2 = checker

# Commands for Compliing
GCC = gcc
GCC_FLAGS = -Wall -Wextra -Werror
RM = rm
RM_FLAGS = -rf

# Exterior Library
LIBFT = ./libft/libft.a

# Paths
LIBFT_PATH = libft/
SOURCE_PATH = sources/
OBJECT_PATH = objects/
HEADER_PATH = headers/
MANDATORY_PATH = mandatory/
BONUS_PATH = bonus/

# Source Names
MANDATORY_NAMES = push_swap \
				  check_exception \
				  get_stack_a \
				  get_string_array \
				  get_int_array \
				  sort_stack_a \
			   	  sort_under_thirty sort_over_thirty \
			   	  rough_sort_to_b sort_to_stack_a rotate_to_top \
			   	  commands_1 commands_2 \
			   	  control_node_1 control_node_2 \
			   	  check_perfectly_sorted check_first_second_node check_first_last_node \
			   	  check_max_min_location \
			   	  utils_1 utils_2 utils_3 \
			   	  free_functions 

BONUS_NAMES = checker \
			  check_exception \
			  get_stack_a \
			  get_string_array get_int_array \
			  get_command_and_execute \
			  commands_1 commands_2 \
			  control_node_1 control_node_2 \
			  check_perfectly_sorted \
			  utils_1 utils_2 \
			  free_functions

# Sources
MANDATORY_SOURCES = $(addprefix $(SOURCE_PATH)$(MANDATORY_PATH), $(addsuffix .c, $(MANDATORY_NAMES)))
BONUS_SOURCES = $(addprefix $(SOURCE_PATH)$(BONUS_PATH), $(addsuffix _bonus.c, $(BONUS_NAMES)))

# Objects
MANDATORY_OBJECTS = $(addprefix $(OBJECT_PATH)$(MANDATORY_PATH), $(addsuffix .o, $(MANDATORY_NAMES)))
BONUS_OBJECTS = $(addprefix $(OBJECT_PATH)$(BONUS_PATH), $(addsuffix _bonus.o, $(BONUS_NAMES)))

# Make Commands
all : $(NAME)

bonus : $(NAME) $(NAME2)

$(NAME) : $(LIBFT) $(MANDATORY_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(NAME) $^

$(NAME2) : $(LIBFT) $(BONUS_OBJECTS)
	$(GCC) $(GCC_FLAGS) -o $(NAME2) $^

clean : 
	make -C $(LIBFT_PATH) clean
	$(RM) $(RM_FLAGS) $(OBJECT_PATH)

fclean : clean
	make -C $(LIBFT_PATH) fclean
	$(RM) $(RM_FLAGS) $(NAME) $(NAME2)

re : fclean all

$(LIBFT) : 
	make bonus -C $(LIBFT_PATH) all

$(OBJECT_PATH)$(MANDATORY_PATH)%.o: $(SOURCE_PATH)$(MANDATORY_PATH)%.c
	@mkdir -p $(dir $@)
	$(GCC) $(GCC_FLAGS) -I$(HEADER_PATH) -o $@ -c $<

$(OBJECT_PATH)$(BONUS_PATH)%.o : $(SOURCE_PATH)$(BONUS_PATH)%.c
	@mkdir -p $(dir $@)
	$(GCC) $(GCC_FLAGS) -I$(HEADER_PATH) -o $@ -c $<

.PHONY: all clean fclean re bonus libft
