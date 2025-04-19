SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
		ft_memcpy.c ft_strlcpy.c ft_strlcat.c ft_memmove.c \
		ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
		ft_strnstr.c ft_atoi.c ft_atol.c ft_strrchr.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strcmp.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c ft_lstlast_bonus.c ft_join.c\
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c get_next_line.c error.c\

OBJS = ${SRCS:.c=.o}

NAME = libft.a

LIBC = ar rcs

HEADER = libft.h

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

RESET			= \033[0m
BLUE			= \033[34m
CYAN			= \033[36m
YELLOW			= \033[38;2;255;239;0m
PINK			= \033[38;2;255;105;180m
RED				= \033[31m


%.o : %.c $(HEADER) Makefile
	@echo "${CYAN}🔨 Compiling $<${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@$(LIBC) $(NAME) $(OBJS)
	@echo "${YELLOW}Libft compiled ✨ ${RESET}"

clean:
	@$(RM) $(OBJS)

fclean: clean
	@echo "${RED}🧹 Removing ${NAME} ${RESET}"
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re