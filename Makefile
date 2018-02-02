# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile2                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarig <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/16 15:43:44 by asarig            #+#    #+#              #
#    Updated: 2018/02/02 16:47:53 by asarig           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC =	bubble_sort.c \
	create_filepath.c \
	ft_get_rec_nfiles.c \
	ft_get_rights.c \
	ft_ls.c \
	ft_swap_data.c \
	get_data.c \
	get_flags.c \
	get_group.c \
	get_n_links.c \
	get_size.c \
	get_user.c \
	handle_args.c \
	main.c \
	print.c \
	print2.c \
	recursive.c \
	free_data.c \

OBJ	= $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I src/ls.h

LIBFT = src/libft/libft.a

LSH = includes/ls.h

CC	= @gcc

CFLAG	=	-Wall -Werxtra -Werror

all: $(NAME)

$(NAME):	$(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)
$(OBJ): $(LIBFT)
	$(CC) $(FLAGS) -I $(LSH) -c $(SRC_POS)
$(LIBFT): 
	@make -C ./src/libft/

clean:
	@rm -f $(OBJ)
	@make fclean -C ./src/libft/

fclean:
	@make clean
	@rm -f $(NAME)
	@make fclean -C ./src/libft/

re:
	@make fclean
	@make all

