# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adjelili <adjelili@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/27 09:41:00 by adjelili          #+#    #+#              #
#    Updated: 2026/02/11 11:47:20 by adjelili         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC_DIR = src/
SRC_BONUS_DIR = src_bonus/
BONUS_CHECKER = .bonus

SRC = $(SRC_DIR)check.c \
      $(SRC_DIR)childs.c \
	  $(SRC_DIR)ft_strtrim.c \
	  $(SRC_DIR)initialize_data.c \
	  $(SRC_DIR)libft.c \
	  $(SRC_DIR)main.c \
	  $(SRC_DIR)mask_for_quote.c \
	  $(SRC_DIR)paths_and_args.c \
	  $(SRC_DIR)processes.c \
	  $(SRC_DIR)split.c \
	  $(SRC_DIR)utils.c
SRC_BONUS = $(SRC_BONUS_DIR)check_bonus.c \
      $(SRC_BONUS_DIR)childs_bonus.c \
	  $(SRC_BONUS_DIR)ft_strtrim_bonus.c \
	  $(SRC_BONUS_DIR)initialize_data_bonus.c \
	  $(SRC_BONUS_DIR)libft.c \
	  $(SRC_BONUS_DIR)main.c \
	  $(SRC_BONUS_DIR)mask_for_quote_bonus.c \
	  $(SRC_BONUS_DIR)paths_and_args_bonus.c \
	  $(SRC_BONUS_DIR)processes_bonus.c \
	  $(SRC_BONUS_DIR)split.c \
	  $(SRC_BONUS_DIR)utils_bonus.c
	  
OBJ = ${SRC:.c=.o}
OBJ_BONUS = ${SRC_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@rm -f $(BONUS_CHECKER)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus: $(BONUS_CHECKER)

$(BONUS_CHECKER): $(OBJ_BONUS)
	@rm -f $(NAME)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)
	@touch $(BONUS_CHECKER)

clean:
	rm -f $(BONUS_CHECKER)
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	
re: fclean all

.PHONY: all clean fclean re