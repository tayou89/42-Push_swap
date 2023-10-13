NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMFLAGS = -f
AR = ar
ARFLAGS = rcs
SRCS_PART1 = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			 ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strlen.c ft_strncmp.c \
			 ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c \
			 ft_strlcpy.c ft_strnstr.c ft_strlcat.c ft_atoi.c \
			 ft_calloc.c ft_strdup.c
SRCS_PART2 = ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			 ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			 ft_putendl_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
			 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			 ft_lstiter.c ft_lstmap.c 
SRCS_PRINTF = ft_printf.c ft_various.c \
			  ft_print_character.c ft_print_string.c \
			  ft_print_decimal.c ft_print_unsigned.c ft_print_hexa.c \
			  ft_print_address.c ft_print_percent.c 
SRCS_GNL = get_next_line.c

OBJS_PART1 = $(SRCS_PART1:.c=.o)
OBJS_PART2 = $(SRCS_PART2:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS_PRINTF = $(SRCS_PRINTF:.c=.o)
OBJS_GNL = $(SRCS_GNL:.c=.o)

ifdef WITH_BONUS
	TOTAL_OBJS = $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS) $(OBJS_PRINTF) $(OBJS_GNL)
else
	TOTAL_OBJS = $(OBJS_PART1) $(OBJS_PART2) $(OBJS_PRINTF) $(OBJS_GNL)
endif

all : $(NAME)

clean : 
	$(RM) $(RMFLAGS) $(OBJS_PART1) $(OBJS_PART2) $(OBJS_BONUS) $(OBJS_PRINTF) $(OBJS_GNL)

fclean : clean
	$(RM) $(RMFLAGS) $(NAME)

re : fclean all

bonus :
	make WITH_BONUS=1

$(NAME) : $(TOTAL_OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	$(CC) $(CFLAGS) -c $^

.PHONY: all clean fclean re bonus
