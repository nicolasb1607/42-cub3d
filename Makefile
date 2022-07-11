NAME = cub3d

################################################################################
#                           COMPILATION SETTING                        	       #
################################################################################

CC		= gcc
CFLAGS	= -Wall -Wextra -g3 -MD
LDFLAGS	= -Wall -Wextra -Werror
SILENT	= --no-print-directory

################################################################################
#                               SOURCE FILES                              	   #
################################################################################

SRCS =	main.c						\
		launch_prgm.c				\
		free.c						\
		debug.c						\
		init.c						\
		parsing/check.c				\
		parsing/check_closed_map.c	\
		parsing/set_parameters.c	\
		parsing/set_texture.c		\
		parsing/set_map.c			\
		parsing/color.c				\
		bresenham/bresenham.c		\
		bresenham/bresenham_utils.c	\
		bresenham/put_pixel.c		\
		render/rendering.c			\
		render/wall_render.c		\
		render/wall_render_utils.c	\
		render/minimap.c	\
		exit.c						\
		player.c					\
		glide.c						\
		key_control.c				\
		raycasting/raycast.c		\
		raycasting/raycast_utils.c	\
		raycasting/ray_orientation.c		
		

################################################################################
#                               INCLUDES                             	       #
################################################################################

INC				=	-I ./includes/		\
					-I ./libft/

LIBINC			=	-L $(PATH_TO_LIBFT)	\
					-L $(PATH_TO_MLX)	\

################################################################################
#                               PATH_TO_FILES                              	   #
################################################################################

SRC_PATH		=	./srcs/
OBJ_PATH		=	./objs/
PATH_TO_LIBFT	=	./libft/
PATH_TO_MLX		=	./minilibx-linux/

################################################################################
#                               OUTPUT_FILES                              	   #
################################################################################


OBJS			=	$(addprefix $(OBJ_PATH), ${SRCS:.c=.o})
DEPENDS			=	$(addprefix $(OBJ_PATH), ${SRCS:.c=.d})

################################################################################
#                                   COLORS                                     #
################################################################################

BLUE			=	\033[0;34m
RED				=	\033[0;31m
GREEN			=	\033[0;32m
NO_COLOR		=	\033[m

################################################################################
#                                   RULES                                      #
################################################################################

all : MAKEMLX MAKELIBFT 
	@make compilation
	@make $(NAME)
	@make completed

$(NAME) : linking $(OBJS)
	@$(CC) $(LDFLAGS) $(LIBINC) -o $@ $(OBJS) $(INC) -lft -lmlx_Linux -lX11 -lXext -lm
	

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC)  $(CFLAGS) $(LIBINC) -c -o $@ $<  $(INC) -lft -lmlx_Linux -lX11 -lXext  -lm

MAKEMLX :
	@make -C $(PATH_TO_MLX) $(SILENT)

MAKELIBFT :
	@make -C $(PATH_TO_LIBFT) $(SILENT)

clean : clean_files
	make clean -C $(PATH_TO_LIBFT) $(SILENT)
	make clean -C $(PATH_TO_MLX) $(SILENT)
	@rm -f $(OBJS)
	@rm -f $(OBJ_PATH)$(DEPENDS)
	@rm -rf $(OBJ_PATH)

fclean : clean clean_exec
	make fclean -C $(PATH_TO_LIBFT) $(SILENT)
	@rm -f $(NAME)

re : fclean 
			make all $(SILENT)

test_right : all
	./$(NAME) maps/test.cub

test_wrong : all
	./$(NAME) maps/testwrong.cub

vtest : all
	valgrind --leak-check=full ./$(NAME) maps/test.cub

.PHONY : all clean fclean re compilation completed linking clean_files clean_exec test_right test_wrong vtest

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
