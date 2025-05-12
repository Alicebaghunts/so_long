MAKEFLAGS       = --no-print-directory

NAME            = so_long

SRC             = ./srcs

BUILD           = ./build

INCLUDES        = -I../includes -Iminilibx-linux

LIBFT_DIR       = ./libft

MLX_DIR         = ./minilibx-linux

MLX_LIB         = -L$(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

HEADER          = includes/so_long.h

SRCS            = $(SRC)/checking1.c $(SRC)/checking2.c  $(SRC)/clean.c \
					$(SRC)/flood_fill_utils.c $(SRC)/flood_fill.c $(SRC)/init.c \
					$(SRC)/main.c $(SRC)/malloc.c $(SRC)/move_down.c \
					$(SRC)/move_left.c $(SRC)/move_right.c $(SRC)/move_up.c \
					$(SRC)/move.c $(SRC)/player.c $(SRC)/put_imagies.c $(SRC)/utils.c \
					$(SRC)/map.c 

OBJS            = $(patsubst $(SRC)/%.c, $(BUILD)/%.o, $(SRCS))

CC              = cc

CFLAGS          = -Wall -Wextra -Werror $(INCLUDES)

RESET           = \033[0m
GREEN           = \033[0;32m
YELLOW          = \033[1;33m
CYAN            = \033[1;36m
RED             = \033[0;31m

all: $(BUILD) libft mlx $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

libft:
	@echo "${CYAN}Compiling Libft ${RESET}"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${YELLOW}😭 ${RESET}"; \
		sleep 0.3; \
	done
	@echo
	@echo "${CYAN}Libft Compiled ✔️${RESET}"

mlx:
	@echo "${CYAN}Compiling MiniLibX ${RESET}"
	@make -C $(MLX_DIR) > /dev/null 2>&1 & i=0; \
	while ps -p $$! > /dev/null; do \
		printf "${YELLOW}😭 ${RESET}"; \
		sleep 0.3; \
	done
	@echo
	@echo "${CYAN}MiniLibX Compiled ✔️${RESET}"

$(BUILD)/%.o: $(SRC)/%.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo
	@echo "${CYAN}░▒▓███████▓▒░ ░▒▓██████▓▒░▒▓████████▓▒░▒▓████████▓▒░▒▓█▓▒░      ░▒▓████████▓▒░       ░▒▓██████▓▒░░▒▓█▓▒░▒▓████████▓▒░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
	@echo "${CYAN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
	@echo "${CYAN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░   ░▒▓█▓▒░░▒▓█▓▒░ $(RESET)"
	@echo "${CYAN}░▒▓███████▓▒░░▒▓████████▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓██████▓▒░        ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░    ░▒▓██████▓▒░  $(RESET)"
	@echo "${CYAN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░      ░▒▓█▓▒░  ░▒▓█▓▒░      ░▒▓█▓▒░     $(RESET)"
	@echo "${CYAN}░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓█▓▒░      ░▒▓█▓▒░             ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░  ░▒▓█▓▒░      ░▒▓█▓▒░     $(RESET)"
	@echo "${CYAN}░▒▓███████▓▒░░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░      ░▒▓█▓▒░   ░▒▓████████▓▒░▒▓████████▓▒░       ░▒▓██████▓▒░░▒▓█▓▒░  ░▒▓█▓▒░      ░▒▓█▓▒░     $(RESET)"
	@echo                                                                                                                                                                                                                                                        
	@echo "${CYAN}so_long created${RESET}"
	@echo "$(CYAN)----------------------------------------------------------$(RESET)"
	@echo "$(CYAN)| $(CYAN)Usage$(CYAN)         $(CYAN)|$(CYAN) ./so_long <map_file> $(CYAN)                  |$(CYAN)$(RESET)"
	@echo "$(CYAN)----------------------------------------------------------$(RESET)"
	@echo "$(CYAN)| $(CYAN)Help$(CYAN)          $(CYAN)|$(CYAN) make help $(CYAN)                             |$(CYAN) $(RESET)"
	@echo "$(CYAN)----------------------------------------------------------$(RESET)"

clean:
	@rm -rf $(BUILD)
	@make clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@make clean -C $(MLX_DIR) > /dev/null 2>&1
	@echo "${RED}Project cleaned ${RESET}"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "${RED}All files removed${RESET}"

re: fclean all

help:
	@echo "$(CYAN)        $(RESET)"
	@echo "$(CYAN)-------------------------------------------------------$(RESET)"
	@echo "$(CYAN)|$(CYAN) $(GREEN) so_long Info$(GREEN)                                      $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)-------------------------------------------------------$(RESET)"
	@echo "$(CYAN)|$(CYAN)                                                     $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)|$(CYAN) $(GREEN)./so_long <map_file>$(GREEN)                              $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)|$(CYAN) $(GREEN) Example: ./so_long maps/map.ber$(GREEN)                  $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)-------------------------------------------------------$(RESET)"
	@echo "$(CYAN)|$(CYAN)                                                     $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)|$(CYAN) $(GREEN) Use valid map files for testing$(GREEN)                 $(CYAN)|$(CYAN)$(RESET)"
	@echo "$(CYAN)-------------------------------------------------------$(RESET)"

.PHONY: all clean fclean re help libft mlx