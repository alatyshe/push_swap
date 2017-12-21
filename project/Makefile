all:
	@make -C libft/
	@make -C check/
	@make -C p_swap/

#------ make clean ------

clean: cleanlib
	@make clean -C libft/
	@make clean -C check/
	@make clean -C p_swap/

#------ make fclean ------
fclean:
	@make fclean -C libft/
	@make fclean -C check/
	@make fclean -C p_swap/

#------ make re ------
re: fclean all
