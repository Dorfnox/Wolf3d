# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bpierce <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/25 10:27:14 by bpierce           #+#    #+#              #
#    Updated: 2017/09/05 16:45:22 by bpierce          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

FILES = main \
		initialize \
		free \
		images \
		map_handling \
		display_screens \
		raycasting \
		movement_fb \
		movement_rl \
		rotation \
		move_rot_speed \
		hook_loop \
		hooks \
		hookarrays \
		hooks_esc \
		mousemovehook \
		keyhooks1 \
		keyhooks2 \
		keyhooks3 \
		keyhooks4 \
		keyhooks5 \
		keyhooks6

C_LOC = src/
C_NAM = $(addsuffix .c, $(FILES))
C_SRC = $(addprefix $(C_LOC), $(C_NAM))

O_LOC = obj/
O_NAM = $(addsuffix .o, $(FILES))
O_SRC = $(addprefix $(O_LOC), $(O_NAM))

LIB_LOC = libft/
LIB_NAM = libft.a
LIB_SRC = $(addprefix $(LIB_LOC), $(LIB_NAM))

H_LOCS = -I inc -I libft/inc -I minilibx
HEADERS = inc/$(addsuffix .h, $(NAME)) inc/wolf3d_macros.h

C_FLAGS = -Wall -Wextra -Werror

MLBX = minilibx/libmlx.a

MLBX_FLAGS = -L minilibx -lmlx -framework OpenGL -framework Appkit -g

TEST_MAIN = main_for_testing.c

RED = [31m
GREEN = [32m
BLUE = [34m
YELLOW = [33m
MAGENTA = [35m
GREY = [37m
GREEN_LIGHT = [92m
YELLOW_LIGHT = [93m
YELLOW_BOLD = [1;33m
YELLOW_LIGHT_BOLD = [1;93m
MAGENTA_LIGHT = [95m
BLINK = [5m
GREEN_LIGHT_BLINK = [5;92m
END_COLOUR = \033[0m

all: $(NAME)

$(NAME): $(O_SRC) $(LIB_SRC) $(MLBX)
	@echo "$(YELLOW_BOLD)Compiling executable... $@$(END_COLOUR)"
	@gcc $(C_FLAGS) $(MLBX_FLAGS) -lpthread $^ -o $@
	@echo
	@echo "$(GREEN_LIGHT)     xxXXXXXXXXxx     $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)  xXX------------XXx  $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)xXX---$(END_COLOUR) $(GREEN_LIGHT_BLINK)COMPLETE$(END_COLOUR) $(GREEN_LIGHT)---XXx$(END_COLOUR)"
	@echo "$(GREEN_LIGHT)xXX----$(END_COLOUR) $(GREEN_LIGHT_BLINK)YIPPEE$(END_COLOUR) $(GREEN_LIGHT)----XXx$(END_COLOUR)"
	@echo "$(GREEN_LIGHT)  xXX------------XXx  $(END_COLOUR)"
	@echo "$(GREEN_LIGHT)     XXxxxxxxxxXX     $(END_COLOUR)"
	@echo

$(O_LOC)%.o: $(C_LOC)%.c $(HEADERS)
	@echo "$(GREY)Re-compiling src file... $(END_COLOUR)$(YELLOW)$<$(END_COLOUR)"
	@gcc $(C_FLAGS) $(H_LOCS) -c $< -o $@

$(LIB_SRC): force
	@echo "$(YELLOW)\n----------- Checking $@ Library -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C $(LIB_LOC)
	@echo "$(YELLOW)----------- $@ Check Complete -----------\n$(END_COLOUR)"

$(MLBX): force
	@echo "$(YELLOW)\n----------- Checking $@ Library -----------$(END_COLOUR)"
	@printf "$(YELLOW_LIGHT)$@ re-compile status: $(END_COLOUR)"
	@make -C minilibx
	@echo "$(YELLOW)----------- $@ Check Complete -----------\n$(END_COLOUR)"

force:
	@true

clean:
	@/bin/rm -rf $(O_SRC)
	@make clean -C $(LIB_LOC)
	@make clean -C minilibx
	@echo "$(GREEN)clean complete!$(END_COLOUR)"

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIB_LOC)
	@echo "$(GREEN)fclean complete!$(END_COLOUR)"

re: fclean all

test: $(NAME)
	@./$(NAME) maps/default.map

.PHONY: all test force clean fclean re
