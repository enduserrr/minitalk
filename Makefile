NAME		= client
NAME_S		= server
LIBFT		= incs/libft/libft.a
SRC_DIR		= src
OBJ_DIR		= obj

SRCS_C		= $(addprefix $(SRC_DIR)/, client.c)
SRCS_S		= $(addprefix $(SRC_DIR)/, server.c)
OBJ_C		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS_C:.c=.o))
OBJ_S		= $(subst $(SRC_DIR), $(OBJ_DIR), $(SRCS_S:.c=.o))

INC			= -I incs -I incs/libft/incs
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f


$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(dir $@)
				@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME) $(NAME_S)

$(NAME): 	$(OBJ_C)
			@make -C incs/libft
			@$(CC) $(OBJ_C) $(LIBFT) -o $(NAME)

$(NAME_S):	$(OBJ_S)
			$(CC) $(OBJ_S) $(LIBFT) -o $(NAME_S)
			@echo "Made."

clean:
			$(RM) $(OBJ_C)
			$(RM) $(OBJ_S)
			$(RM) -r $(OBJ_DIR)
			@make clean -C incs/libft

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(NAME_S)
			@make fclean -C incs/libft

re:			fclean all

.PHONY: all clean fclean re