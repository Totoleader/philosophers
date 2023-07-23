NAME	:= philo
CFLAGS	:= -Wall -Wextra -Werror -g #-fsanitize=thread

HEADERS	:= -I ./include
LIBFT 	:= ./libft
LIBS 	:= $(LIBFT)/libft.a

SRCS	:= src/main.c \
			src/parse.c \
			src/error.c \
			src/timer.c \
			src/init.c \
			src/init_utils.c \
			src/launch_threads.c \
			src/actions/eat.c \
			src/actions/sleep.c \
			src/actions/think.c \
			src/actions/utils.c \
			src/actions/entry.c \
			src/actions/death.c \

OBJS	:= ${SRCS:.c=.o}

all: lib $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

lib:
	@make -C $(LIBFT) all

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) $(CFLAGS)


clean:
	@rm -f $(OBJS)
	@rm -f $(OBJSLIB)
	@rm -f $(LIBS)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: clean all

.PHONY: all, clean, fclean, re