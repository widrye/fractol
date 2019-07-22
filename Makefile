# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: widrye <widrye@student.le-101.fr>          +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/11/29 07:11:21 by widrye       #+#   ##    ##    #+#        #
#    Updated: 2019/06/27 22:43:06 by widrye      ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME     = fractol

########## Source & Obj  ##########

SRCS     = $(shell ls srcs | cut -d "." -f 1)
SRCS_FDF = $(addprefix $(DIR_SRC), $(addsuffix .c, $(SRCS)))
OBJ = $(addprefix $(DIR_OBJ), $(addsuffix .o, $(SRCS)))

##########     Header    ##########

INC      = fractol.h

##########    Compiler   ##########

CC       = gcc
CCFLAGS += -Wall -Wextra -Werror -g -fsanitize=address

##########    MiniLibX   ##########

MLX		 = ./miniLibX/
MLX_LIB	 = $(addprefix $(MLX),libmlx.a)
MLX_INC	 = -I ./miniLibX
MLX_LINK = -L ./miniLibX -lmlx -framework OpenGL -framework AppKit

##########  Directories  ##########

DIR_OBJ  = ./objects/
DIR_SRC  = ./srcs/
DIR_INC  = ./includes/

all: obj $(MLX_LIB) $(NAME)

$(NAME): $(OBJ) $(addprefix $(DIR_INC),$(INC))
	@$(CC) $(CCFLAGS) $(MLX_LINK) $(OBJ) -lm -o $(NAME)

obj:
	@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)%.o:$(DIR_SRC)%.c
	$(CC) $(CCFLAGS) $(MLX_INC) -I $(DIR_INC) -o $@ -c $< 

$(MLX_LIB):
	@make -C $(MLX)

clean:
	rm -rf $(DIR_OBJ)
	make -C $(MLX) clean

fclean: clean
	rm -f $(NAME)

re: fclean all