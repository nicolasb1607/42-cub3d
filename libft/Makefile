# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/23 16:20:24 by nburat-d          #+#    #+#              #
#    Updated: 2022/06/24 15:29:16 by nburat-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a
################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -MD

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	ft_atoi.c				\
		ft_bzero.c				\
		ft_calloc.c				\
		ft_isalnum.c			\
		ft_isalpha.c			\
		ft_isascii.c			\
		ft_isdigit.c			\
		ft_isprint.c			\
		ft_containchar.c		\
		ft_memchr.c				\
		ft_memcmp.c				\
		ft_memcpy.c				\
		ft_memset.c				\
		ft_memmove.c			\
		ft_strchr.c				\
		ft_strdup.c				\
		ft_strlcat.c			\
		ft_strlcpy.c			\
		ft_strncpy.c			\
		ft_strlen.c				\
		ft_tablen.c				\
		ft_strcmp.c				\
		ft_strncmp.c			\
		ft_strnstr.c			\
		ft_strrchr.c			\
		ft_tolower.c			\
		ft_toupper.c			\
		ft_substr.c				\
		ft_charjoin.c			\
		ft_strjoin.c			\
		ft_strtrim.c			\
		ft_split.c				\
		ft_itoa.c				\
		ft_striteri.c			\
		ft_strmapi.c			\
		ft_putchar_fd.c			\
		ft_putstr_fd.c			\
		ft_putendl_fd.c			\
		ft_putnbr_fd.c			\
		ft_putchar.c			\
		ft_putstr.c				\
		ft_putnbr.c				\
		ft_lstrev.c				\
		ft_lstnew.c				\
		ft_lstadd_front.c		\
		ft_lstsize.c			\
		ft_lstlast.c			\
		ft_lstadd_back.c		\
		ft_lstdelone.c			\
		ft_lstclear.c			\
		ft_lstiter.c			\
		ft_lstmap.c				\
		ft_is_int.c				\
		ft_dlstadd_back.c		\
		ft_dlstadd_front.c		\
		ft_dlstclear.c			\
		ft_dlstlast.c			\
		ft_dlstnew.c			\
		ft_dlstsize.c			\
		ft_dlstdelone.c			\
		ft_dlstiter.c			\
		get_next_line.c			\
		get_next_line_utils.c	\
		ft_is_white_space.c		\
		free_tab.c				\
	
################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

INCLUDES_PATH = ./
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/

################################################################################
#                               OUTPUT_FILES                              	   #
################################################################################


OBJS = $(addprefix $(OBJ_PATH), ${SRCS:.c=.o})
DEPENDS = $(addprefix $(OBJ_PATH), ${SRCS:.c=.d})

################################################################################
#                                   COLORS                                     #
################################################################################

BLUE		=	\033[0;34m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
NO_COLOR	=	\033[m


################################################################################
#                                   RULES                                      #
################################################################################

all :
	@make compilation
	@make $(NAME)
	@make completed
	
$(NAME) : linking $(OBJS)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c -o $@ $<  -I $(INCLUDES_PATH)

clean : clean_files
	@rm -f $(OBJS)
	@rm -f $(OBJ_PATH)$(DEPENDS)
	@rm -rf $(OBJ_PATH)

fclean : clean clean_exec
	$(clean_exec)
	@rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re

-include $(DEPENDS)

################################################################################
#                                   PRINT_MSG                                  #
################################################################################

compilation :
	@echo "$(NAME) -- Compilation in progress..."
	
completed :
	@echo "$(GREEN)"
	@echo "$(NAME) -- Compilation complete !"
	@echo "$(NO_COLOR)"
	
linking : 
	@echo "$(NAME) Linking in progress..."
	
clean_files : 
	@echo "$(NAME) Cleaning files..."
	
clean_exec : 
	@echo "$(NAME) Cleaning executable..."

