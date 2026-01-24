# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlnikola <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/23 02:34:49 by vlnikola          #+#    #+#              #
#    Updated: 2025/11/23 02:34:50 by vlnikola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror  #-g3 -fsanitize=address
LIBFT_PATH  = ./libft
LIBFT_NAME  = $(LIBFT_PATH)/libft.a

SRCS        = src/parser.c \
              src/push_swap.c \
              src/utils.c \
              src/cmds/swap.c \
              src/cmds/push.c \
              src/cmds/rotate.c \
              src/cmds/reverse_rotate.c \
			  src/sort_utils.c \
			  src/sort.c

OBJS        = $(SRCS:.c=.o)

INCLUDES    = -I. -I$(LIBFT_PATH)

all: $(LIBFT_NAME) $(NAME)

$(LIBFT_NAME):
	@$(MAKE) bonus -C $(LIBFT_PATH)

$(NAME): $(OBJS) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
