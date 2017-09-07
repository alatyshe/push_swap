PUSH_SWAP_NAME = push_swap
CHECKER_NAME = checker

FLAGS = -Wall -Wextra -Werror

LIBRARY = libft/libft.a

CHECKER_C = main src/get_info src/other src/checking src/create_struct\
		src/for_free src/for_print_func src/read\
		\
		swap/s_func swap/p_func swap/r_func swap/rr_func

PUSH_C = main swap/p_func swap/r_func swap/rr_func swap/s_func\
	other/checking other/create_struct other/find_pivot other/for_free\
	other/for_print_func other/get_info other/other \
	sort/sort_elems_rev_a_2 sort/sort_elems_rev_a sort/sort_elems_rev_b_2 sort/sort_elems_rev_b\
	sort/sort_three_elem_a sort/sort_three_elem_b\
	recurssion/stack_a_recurssion recurssion/stack_a_sort_rev recurssion/stack_a_sort\
	recurssion/stack_b_sort_rev recurssion/stack_b_sort

PUSH_SWAP_DIR = Push_Swap/
CHECKER_DIR = Checker/

OBJ_PUSH_SWAP = $(addprefix $(PUSH_SWAP_DIR),$(addsuffix .o,$(PUSH_C)))
OBJ_CHECKER = $(addprefix $(CHECKER_DIR),$(addsuffix .o,$(CHECKER_C)))


FLAGS = -Wall -Wextra -Werror

all: lib checker push_swap

lib:
	make -C ./libft

push_swap: $(OBJ_PUSH_SWAP)
	gcc -o $(PUSH_SWAP_NAME) $(FLAGS) $(OBJ_PUSH_SWAP) $(LIBRARY) 
	@echo "\x1b[32m"push_swap has been made "\x1b[0m"

checker: $(OBJ_CHECKER)
	gcc -o $(CHECKER_NAME) $(FLAGS) $(OBJ_CHECKER) $(LIBRARY)
	@echo "\x1b[32m"checker has been made "\x1b[0m"
	

%.o: %.c
	gcc $(FLAGS) -c -o $@ $< 


clean:
	find . -name "*.o" -type f -delete

fclean: clean
	@rm -f checker push_swap $(LIBRARY)

re: fclean all
