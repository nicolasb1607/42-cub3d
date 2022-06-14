EXEC = libft.a
################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CC = gcc
CFLAGS = -Wall -Wextra -Werror -MD

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS = main.c 

################################################################################
#                               INCLUDES                             	       #
################################################################################

INC = -I ./libft/        \
	-I ./includes/

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

all : compilation $(EXEC) completed

$(EXEC) : linking $(OBJS)
	@$(CC) $(LDFLAGS) -o $@ $(OBJS)
	@echo "done."

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) -c -o $@ $<  -L $(PATH_TO_LIBFT) $(INC) -lft


MAKELIBFT :
	make -C $(PATH_TO_LIBFT)

clean : clean_files
	make clean -C $(PATH_TO_LIBFT)
	@rm -f $(OBJS)
	@rm -f $(OBJ_PATH)$(DEPENDS)
	@rm -rf $(OBJ_PATH)
	@echo "done."

fclean : clean clean_exec
	make fclean -C $(PATH_TO_LIBFT)
	@rm -f $(EXEC)
	@echo "done."

re : fclean 
			make all 

test: $(EXEC) 
		./$(EXEC) #+ arguments if needed

.PHONY : all clean fclean re compilation completed linking clean_files clean_exec 

.SILENT:

-include $(DEPENDS)

################################################################################
#                                 PRINT_MSG                                    #
################################################################################

compilation :
	@echo "Compilation in progress..."
	
completed :
	@echo "$(GREEN)"
	@echo "Compilation complete !"
	@echo "$(NO_COLOR)"
	
linking : 
	@echo "Linking in progress..."
	
clean_files : 
	@echo "Cleaning files..."
	
clean_exec : 
	@echo "Cleaning executable..."