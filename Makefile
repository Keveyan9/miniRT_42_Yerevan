
# NAME			=	minishell

# CC				=	cc

# LIBFT_DIR		=	libft

# LIBFT			=	$(LIBFT_DIR)/libft.a

# PREFIX			=	$(shell find ${PWD} -type d -name readline_out)

# INC				=	-Iinc -I$(LIBFT_DIR)

# READLINE_DIR	=	readline

# READLINE_OUT	=	"${PWD}/readline_out/"

# READLINE_INC	=	-I$(READLINE_OUT)/include

# READLINE_LIB	=	$(READLINE_OUT)lib

# INCLUDES		=	$(INC) $(READLINE)

# LINKERS			=	-L$(READLINE_LIB) -lreadline -L$(LIBFT_DIR) -lft

# CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address -g

# OBJS_DIR		=	objs

# SRCS			=	$(wildcard src/*.c)

# OBJS			=	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# MKDIR			=	mkdir -p

# RM				=	rm -rf

# .DEFAULT_GOAL	=	all

# $(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
# 	$(CC) $(CFLAGS) $(INCLUDES) $(READLINE_INC) -c $< -o $@

# all: $(NAME)
# $(OBJS_DIR):
# 	$(MKDIR) $(OBJS_DIR)

# $(LIBFT):
# 	$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(LIBFT) $(OBJS) | $(OBJS_DIR)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

# $(READLINE_OUT):
# 	mkdir -p $(READLINE_OUT)

# clean:
# 	$(RM) $(OBJS_DIR)
# 	$(MAKE) clean -C $(LIBFT_DIR)

# fclean: clean
# 	$(RM) $(NAME)
# 	$(MAKE) fclean -C $(LIBFT_DIR)

# re: fclean all

# readline: $(READLINE_OUT)
# 	@cd readline && ./configure --prefix=$(PREFIX) && make clean && make && make install

# .PHONY: all clean fclean re readline


NAME			=	minishell

CC				=	cc

LIBFT_DIR		=	libft

LIBFT			=	$(LIBFT_DIR)/libft.a

PREFIX			=	$(shell find ${HOME} -type d -name readline_out)

INC				=	-Iinc -I$(LIBFT_DIR)

READLINE_DIR	=	readline

READLINE_OUT	=	"${HOME}/readline_out/"

READLINE_INC	=	-I$(READLINE_OUT)/include

READLINE_LIB	=	$(READLINE_OUT)lib

INCLUDES		=	$(INC) $(READLINE)

LINKERS			=	-L$(READLINE_LIB) -lreadline -L$(LIBFT_DIR) -lft

CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address -g

OBJS_DIR		=	objs

SRCS			=	$(wildcard src/*.c)

OBJS			=	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

MKDIR			=	mkdir -p

RM				=	rm -rf

.DEFAULT_GOAL	=	all

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) $(READLINE_INC) -c $< -o $@

all: $(NAME)
$(OBJS_DIR):
	$(MKDIR) $(OBJS_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LINKERS)

$(READLINE_OUT):
	mkdir -p $(READLINE_OUT)

clean:
	$(RM) $(OBJS_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

readline: $(READLINE_OUT)
	@cd readline && ./configure --prefix=$(PREFIX) && make clean && make && make install

.PHONY: all clean fclean re readline