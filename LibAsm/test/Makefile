#---------------------------------------------------------------------------------------------------------#
ASM = nasm
ARGS = -f
FTM = elf64 -g -F dwarf
OPT = -g
NAME = libasm
#---------------------------------------------------------------------------------------------------------#
SRCS_DIR = src
SRCS = $(shell find $(SRCS_DIR) -name "*.s")

OBJ_DIR = .obj
OBJS = $(SRCS:$(SRCS_DIR)/%.s=$(OBJ_DIR)/%.o)
#---------------------------------------------------------------------------------------------------------#

all: $(NAME)

$(NAME): $(OBJS)
	ld  $(OBJS) -g -o $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.s
	mkdir -p $(@D)
	$(ASM) $(ARGS) $(FTM)  $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean
	$(MAKE) all

PHONY: all clean fclean re 