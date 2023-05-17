NAME			=	minrt

CC				=	cc

LIBFT_DIR		=	libft

HEAD			= 	includes

LIBFT			=	$(LIBFT_DIR)/libft.a

GNL_dir			=	gnl

LIBVECTOR_dir	=	libvector

LIBFECTOR		=	$(LIBVECTOR_dir)/libvector.a

MLX_linux_dir	=	mlx_linuxs

MLX_MAC_dir		=	mlx_mac

CFLAGS			=	-Wall -Wextra -Werror #-fsanitize=address -g

OBJS_DIR		=	objs

MKDIR			=	mkdir -p

RM				=	rm -rf

.DEFAULT_GOAL	=	all





PREFIX			=	$(shell find ${HOME} -type d -name readline_out)

INC				=	-Iinc -I$(LIBFT_DIR)

READLINE_DIR	=	readline

READLINE_OUT	=	"${HOME}/readline_out/"

READLINE_INC	=	-I$(READLINE_OUT)/include

READLINE_LIB	=	$(READLINE_OUT)lib

INCLUDES		=	$(INC) $(READLINE)

LINKERS			=	-L$(READLINE_LIB) -lreadline -L$(LIBFT_DIR) -lft



SRCS			=	$(wildcard src/*.c)

OBJS			=	$(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))




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