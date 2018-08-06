# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cterblan <cterblan@student.wethinkcode>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/17 11:24:40 by cterblan          #+#    #+#              #
#    Updated: 2018/08/06 14:22:58 by jpirzent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#								FILE NAME
################################################################################
NAME := libftprintf.a
#OUTPUT FILE NAME ^^^
################################################################################
#								DIRECTORIES
################################################################################
INC_DIR := ./includes
#INCLUDES DIRECTORY ^^^
SRC_DIR := ./sources/
#SOURCES DIRECTORY ^^^
OBJ_DIR := ./objects
#OBJECTS DIRECTORY ^^^
################################################################################
#								FILES
################################################################################
#SRC:= ft_function.c
SRC :=	ft_printf.c\
		pr_cprint.c\
		pr_functions.c\
		pr_functions1.c\
		pr_handle.c\
		pr_print.c\
		pr_wchars.c\
#ADD SOURCE FILES HERE ^^^
OBJ := $(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))
################################################################################
#								COMPILER
################################################################################
CFLAGS := -Wall -Werror -Wextra
#ADD ADDITIONAL FLAGS HERE ^^^
CC := gcc $(CFLAGS)
################################################################################
#								RULES
################################################################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[35m\t\t[COMPILING] $@\033"
#COMPILE EXECUTABLE vvv
	#$(CC) -o $@ -I $(INC_DIR) $(OBJ)
#COMPILE LIBRARY vvv
	ar rcs $(NAME) $(OBJ)
	@echo "\033[32m[COMPILED SUCCESSFULLY]\033"
	@echo "\007"
	#DON'T TOUCH ^^^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "\033[36m\t\t[Building]\033[0m $@"
	@mkdir -p $(OBJ_DIR)
	@$(CC) -I $(INC_DIR) -o $@ -c $<
	@echo "\033[33m\t\t[SUCCESS]\033[0m"
	#DON'T TOUCH ^^^

clean:
	@echo "\033[31m\t\t[CLEANING]\t$(OBJ_DIR)\033[0m"
	@rm -rf $(OBJ_DIR)
	#DON'T TOUCH ^^^

fclean: clean
	@echo "\033[31m\t\t[FCLEAN]\t$(NAME)\033[0m"
	@rm -f $(NAME)
	#ADD ADDITIONAL NAME FILES HERE ^^^

re: fclean all
################################################################################
#								SPECIAL
################################################################################

.PHONEY := all clean fclean re
#ADD PHONEY HERE ^^^

.SILENT:
#DON'T TOUCH ^^^

.PRECIOUS := author
#ADD PRECIOUS HERE ^^^
