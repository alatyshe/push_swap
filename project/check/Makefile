# ----- Colors -----
BLACK ="\033[1;30m"
RED ="\033[1;31m"
GREEN ="\033[1;32m"
YELLOW = "\x1b[33m"
BLUE = "\x1b[34m"
MAGENTA = "\x1b[35m"
CYAN ="\033[1;35m"
PURPLE ="\033[1;36m"
WHITE ="\033[1;37m"
EOC ="\033[0;0m"
RESET = "\x1b[0m"
# ==================

LIBRARY = ../libft/libft.a

NAME = ../checker
# HEAD = header/asm.h header/other.h header/func.h

FLAGS = -Wall -Wextra -Werror

#------ path -------
FILES_PATH		= ./files
SRC_PATH		= ./files/src
SWAP_PATH		= ./files/swap
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES			= main
SRC_FILES			= checking create_struct for_free for_print_func get_info other read
SWAP_FILES			= p_func r_func rr_func s_func

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))
SRC_OBJ			= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SRC_FILES)))
SWAP_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SWAP_FILES)))

#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ) $(SRC_OBJ) $(SWAP_OBJ)
	@echo "\n"
	@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ $(LIBRARY)
	@echo $(GREEN) "\tchecker\t\t- has been made\n"$(RESET)


$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(SRC_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(SWAP_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

#------ make clean ------
cleanlib:
	@make clean -C ../libft

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tCHECKER"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(SRC_OBJ)
	@rm -f $(SWAP_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ../libft

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tCHECKER"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(SRC_OBJ)
	@rm -f $(SWAP_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tchecker have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all
