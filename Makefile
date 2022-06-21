NAME = cub3d
################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -MD
LDFLAGS = -Wall -Wextra -Werror
SILENT = --no-print-directory

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	main.c				\
		launch_prgm.c		\
		free.c				\
		debug.c				\
		parsing/init.c		\
		parsing/check.c		\
		parsing/set_parameters.c
		parsing/set_texture.c \
		parsing/set_map.c \


################################################################################
#                               INCLUDES                             	       #
################################################################################

INC = -I ./includes/	\
	-I ./libft/

################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
PATH_TO_LIBFT = ./libft/

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
NO_COLOR =	\033[m

################################################################################
#                                   RULES                                      #
################################################################################

all : MAKELIBFT 
	@make compilation
	@make $(NAME)
	@make completed

$(NAME) : linking $(OBJS)
	@$(CC) $(LDFLAGS) -L $(PATH_TO_LIBFT) -o $@ $(OBJS) $(INC) -lft
	

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -L $(PATH_TO_LIBFT) -c -o $@ $<  $(INC) -lft


MAKELIBFT :
	@make -C $(PATH_TO_LIBFT) $(SILENT)

clean : clean_files
	make clean -C $(PATH_TO_LIBFT) $(SILENT)
	@rm -f $(OBJS)
	@rm -f $(OBJ_PATH)$(DEPENDS)
	@rm -rf $(OBJ_PATH)

fclean : clean clean_exec
	make fclean -C $(PATH_TO_LIBFT) $(SILENT)
	@rm -f $(NAME)

re : fclean 
			make all $(SILENT)

test : all
	./$(NAME)


.PHONY : all clean fclean re compilation completed linking clean_files clean_exec 

-include $(DEPENDS)

################################################################################
#                                 PRINT_MSG                                    #
################################################################################

compilation :
	@echo "$(NAME) Compilation in progress..."
	
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