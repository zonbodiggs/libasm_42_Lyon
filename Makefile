#---------------------------------------------------------------------------------------------------------#
ASM = nasm
ARGS = -f
FTM = elf64 -g -F dwarf
OPT = -g

#------------------------------------------------mandatory------------------------------------------------#
SRCS_DIR = libasm/src
SRCS = $(shell find $(SRCS_DIR) -name "*.s")

OBJ_DIR = .obj
OBJS = $(SRCS:$(SRCS_DIR)/%.s=$(OBJ_DIR)/%.o)

NAME = libasm.a

#--------------------------------------------------bonus--------------------------------------------------#
BONUS_DIR = libasm/bonus
BONUS_FILES = $(shell find $(BONUS_DIR) -name "*.s")

OBJ_DIR_BONUS = .obj_bonus
OBJS_BONUS = $(BONUS_FILES:$(BONUS_DIR)/%.s=$(OBJ_DIR_BONUS)/%.o)

NAME_BONUS = libasm_bonus.a
#-------------------------------------------------tester--------------------------------------------------#
CC = cc
CARGS = -g -Wall -Wextra -Werror -Wstring-compare -Itest/microfamework/includes
Clib = -L. -lasm -lasm_bonus
CNAME = pacoasm

CSRCS_DIR = test
CSRCS = $(shell find $(CSRCS_DIR) -name "*.c")

COBJDIR = .cobj
COBJS = $(CSRCS:$(CSRCS_DIR)/%.c=$(COBJDIR)/%.o)

HEADER = $(shell find $(CSRCS_DIR) -name "*.h")

#---------------------------------------------------------------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.s
	@if [ ! -d "$(OBJ_DIR)" ]; then \
		mkdir -p $(@D); \
		echo "creating .obj dir"; \
	fi
	$(ASM) $(ARGS) $(FTM)  $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	@ar rcs $(NAME_BONUS) $(OBJS_BONUS)
	ranlib $(NAME_BONUS)

$(OBJ_DIR_BONUS)/%.o: $(BONUS_DIR)/%.s
	@if [ ! -d "$(OBJ_DIR_BONUS)" ]; then \
		mkdir -p $(@D); \
		echo "creating .obj_bonus dir"; \
	fi
	$(ASM) $(ARGS) $(FTM)  $< -o $@

call: $(CNAME)

$(CNAME): $(COBJS) $(NAME)
	$(CC) $(CARGS) $(COBJS) $(Clib) -o $(CNAME)

$(COBJDIR)/%.o: $(CSRCS_DIR)/%.c $(HEADER)
	@mkdir -p $(@D) 
	$(CC) $(CARGS) -c $< -o $@

exec_test: 
	$(MAKE) all
	$(MAKE) bonus;

	@echo "compile .c files"
	@$(MAKE) call -s

test_mandatory: exec_test
	./$(CNAME) mandatory
	@echo "end of mandatory test"
	@$(MAKE) clean_test -s

test_bonus: exec_test
	./$(CNAME) bonus
	@echo "end of mandatory test"
	@$(MAKE) clean_test -s

test_all: exec_test
	./$(CNAME) all
	@echo "end of mandatory test"
	@$(MAKE) clean_test -s

clean_test:
	@if [ -d "$(COBJDIR)" ]; then \
		rm -rf $(COBJDIR); \
	fi
	@if [ "$(CNAME)" ]; then \
		rm -rf $(CNAME); \
	fi

clean: clean_test
	rm -rf $(OBJ_DIR)
	rm -rf $(OBJ_DIR_BONUS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)
	

re: fclean
	$(MAKE) all

.PHONY: all bonus clean fclean re test_mandatory test_bonus test_all test exec_test clean_test
#---------------------------------------------------------------------------------------------------------#