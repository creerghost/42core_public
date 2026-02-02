# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlnikola <vlnikola@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/26 22:52:41 by vlnikola          #+#    #+#              #
#    Updated: 2025/11/13 01:50:32 by vlnikola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCES = ft_is_group.c \
	ft_print_group.c \
	ft_atoi_itoa.c \
	ft_fniteri.c \
	ft_mallocated_1.c \
	ft_mallocated_2.c \
	ft_strings_1.c \
	ft_strings_2.c \
	ft_mem_group_1.c \
	ft_mem_group_2.c \
	ft_to_upper_lower.c \
	ft_split.c \

OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

BONUS = ft_1_bonus.c \
	ft_2_bonus.c \

BONUS_OBJECTS = $(BONUS:.c=.o)

PRINTF_PATH = ft_printf/

PRINTF_NAME = $(PRINTF_PATH)libftprintf.a

all: $(NAME)

$(NAME): $(OBJECTS)

	$(MAKE) -C $(PRINTF_PATH)
	cp $(PRINTF_NAME) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	rm -f $(BONUS_OBJECTS)
	$(MAKE) -C $(PRINTF_PATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF_PATH) fclean

re: fclean all

bonus: $(OBJECTS) $(BONUS_OBJECTS)
	$(MAKE) -C $(PRINTF_PATH)
	cp $(PRINTF_NAME) $(NAME)
	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)


.PHONY: all clean fclean re bonus
