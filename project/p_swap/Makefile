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

NAME = ../push_swap
# HEAD = header/asm.h header/other.h header/func.h

FLAGS = -Wall -Wextra -Werror

#------ path -------
FILES_PATH		= ./files
OTHER_PATH		= ./files/other
SORT_PATH		= ./files/sort
RECURSSION_PATH	= ./files/recurssion
SWAP_PATH		= ./files/swap
OBJECTS_PATH	= ./objects


#------ files ------
FILES_FILES			= main
OTHER_FILES			= checking create_struct find_pivot for_free for_print_func get_info other
RECURSSION_FILES	= stack_a_recurssion stack_a_sort_rev stack_a_sort stack_b_sort_rev stack_b_sort
SORT_FILES			= sort_elems_rev_a_2 sort_elems_rev_a sort_elems_rev_b_2 sort_elems_rev_b sort_three_elem_a sort_three_elem_b
SWAP_FILES			= p_func r_func rr_func s_func

#------ other ------
FILES_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(FILES_FILES)))
OTHER_OBJ 		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(OTHER_FILES)))
RECURSSION_OBJ	= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(RECURSSION_FILES)))
SORT_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SORT_FILES)))
SWAP_OBJ		= $(addprefix $(OBJECTS_PATH)/, $(addsuffix .o, $(SWAP_FILES)))

#------ make ------
all: $(NAME)

$(NAME): $(FILES_OBJ) $(OTHER_OBJ) $(RECURSSION_OBJ) $(SWAP_OBJ) $(SORT_OBJ)
	@echo "\n"
	@make -C ../libft/
	@echo $(CYAN) "\tCompiling $@"$(RESET)
	@gcc $(FLAGS) -o $@ $^ $(LIBRARY)
	@echo $(GREEN) "\tpush_swap\t\t- has been made\n"$(RESET)

$(OBJECTS_PATH)/%.o: $(SWAP_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(FILES_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(OTHER_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(RECURSSION_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

$(OBJECTS_PATH)/%.o: $(SORT_PATH)/%.c
	@echo $(PURPLE) "\tCompiling $<"$(RESET)
	@mkdir $(OBJECTS_PATH) 2> /dev/null || true
	@gcc $(FLAGS) -o $@ -c $<

#------ make clean ------
cleanlib:
	@make clean -C ../libft

clean: cleanlib
	@echo $(YELLOW)"\t\t\t\tPUSH_SWAP"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBJ)
	@rm -f $(RECURSSION_OBJ)
	@rm -f $(SORT_OBJ)
	@rm -f $(SWAP_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)

#------ make fclean ------
fcleanlib:
	@make fclean -C ../libft

fclean: fcleanlib
	@echo $(YELLOW)"\t\t\t\tPUSH_SWAP"$(RESET)
	@rm -f $(FILES_OBJ)
	@rm -f $(OTHER_OBJ)
	@rm -f $(RECURSSION_OBJ)
	@rm -f $(SORT_OBJ)
	@rm -f $(SWAP_OBJ)
	@echo $(RED) "\t.o files have been cleaned."$(RESET)
	@rm -rf $(OBJECTS_PATH)
	@echo $(RED) "\t./objects path have been cleaned."$(RESET)
	@rm -f $(NAME)
	@echo $(RED) "\tpush_swap have been cleaned.\n"$(RESET)

#------ make re ------
re: fclean all
