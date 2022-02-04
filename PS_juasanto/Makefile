# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juasanto <juasanto>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/09 10:44:34 by juasanto          #+#    #+#              #
#   Updated: 2022/01/10 11:40:21 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean re fclean test norm git_push

NAME 		=	push_swap
LIBFT 		= 	libft.a
LIB_DIR		=	Libft/
OBJ_DIR		=	obj/
SRCS_DIR	=	sources/
SRCS		=	push_swap.c \
				ps_chk_ab.c \
				ps_chk_args.c \
				ps_mv_ab_1.c \
				ps_utils_1.c \
				ps_short_1.c \
				ps_short_max.c

OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

NOW			=	$(shell date +"%d-%m-%y %H:%M")

LFLAGS = -I includes/
CFLAGS = #-Wall -Wextra -Werror
DEBUGGING = -ggdb
OPTIMIZING = -O3
CC = clang
RM = rm -rf
AR = ar rc
RANLIB = ranlib
NORM = /usr/bin/norminette

RESET = \033[0m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
CYAN = \033[36m



all: $(NAME)

$(OBJ_DIR)%.o : $(SRCS_DIR)%.c
		@echo Create: $(NAME) Object directory
		@mkdir -p $(OBJ_DIR)
		$(CC) -c $(CFLAGS) $(DEBUGGING) $(LFLAGS) $< -o $@

$(NAME): $(OBJS)
		@echo "$(CYAN)=========== Compilando LIBFT.A ==========="
		make -C $(LIB_DIR)
		@echo "=========== DONE ==========$(RESET)"

		@echo "$(YELLOW)=========== Compilando $(NAME) ==========="
		$(CC)$(CFLAGS) $(OBJS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME)
#		$(CC)$(CFLAGS) $(LFLAGS) $(LIB_DIR)$(LIBFT) -o $(NAME) $(OBJS)
		@echo "=========== DONE ==========$(RESET)"
clean:
		@echo "$(PINK)========== CLEAN =========="
		$(RM) $(OBJ_DIR)
		$(RM) $(OBJS)
		make -C $(LIB_DIR) clean
		@echo "$(PINK)=========== DONE ===========$(RESET)"
fclean: clean
		@echo "$(RED)========== FCLEAN =========="
		$(RM) $(NAME)
		make -C $(LIB_DIR) fclean
		@echo "$(RED)=========== DONE ===========$(RESET)"
git_push: fclean
		@echo "$(RED)========== GIT_PUSH =========="
		git add *
		git commit -m "Push_Swap - $(NOW)"
		git push 
		@echo "$(RED)=========== DONE ===========$(RESET)"
bonus: all
re: fclean all
norm: all
		$(NORM) $(SRC);

