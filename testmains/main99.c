/*
(cd .. && make re) && make m
*/

/*
int	main(void)
{
	char c_test1 = 'A'; 														// 1
	char c_test2 = '9'; 														// 1
	char s_test1[] = "Goodmorning"; 											// 11
	char s_test2[] = "wower43s4t3y794t3"; 										// 17
	int i_test1 = 123;															// 3
	int i_test2 = 9876543211111;												// 9
	unsigned int u_test1 = 123;													// 3
	unsigned int u_test2 = 0;													// 10 // 4294967295
	unsigned int x_test1 = 123;													// 3
	unsigned int x_test2 = 747824379242479212121111;							// 
	unsigned int X_test1 = 123;													// 3
	unsigned int X_test2 = 747824379242479212121111;							// 
	unsigned int *p_test1 = x_test1;											// 3
	unsigned int *p_test2 = x_test2;

	int c_count_own;
	int c_count_old;
	printf("\nargument --> c \n");
	c_count_own = ft_printf("%c %c\n", c_test1, c_test2);
	c_count_old = printf("%c %c\n", c_test1, c_test2);
	printf("Own: %d\n", c_count_own);
	printf("Old: %d\n", c_count_old);

	int s_count_own;
	int s_count_old;
	printf("\nargument --> s \n");
	s_count_own = ft_printf("%s %s\n", s_test1, s_test2);
	s_count_old = printf("%s %s\n", s_test1, s_test2);
	printf("Own: %d\n", s_count_own);
	printf("Old: %d\n", s_count_old);

	int i_count_own;
	int i_count_old;
	printf("\nargument --> i \n");
	i_count_own = ft_printf("%i %i\n", i_test1, i_test2);
	i_count_old = printf("%i %i\n", i_test1, i_test2);
	printf("Own: %d\n", i_count_own);
	printf("Old: %d\n", i_count_old);

	int u_count_own;
	int u_count_old;
	printf("\nargument --> u \n");
	u_count_own = ft_printf("%u %u\n", u_test1, u_test2);
	u_count_old = printf("%u %u\n", u_test1, u_test2);
	printf("Own: %d\n", u_count_own);
	printf("Old: %d\n", u_count_old);
	
	int x_count_own;
	int x_count_old;
	printf("\nargument --> x \n");
	x_count_own = ft_printf("%x %x\n", x_test1, x_test2);
	x_count_old = printf("%x %x\n", x_test1, x_test2);
	printf("Own: %d\n", x_count_own);
	printf("Old: %d\n", x_count_old);
	
	int X_count_own;
	int X_count_old;
	printf("\nargument --> X \n");
	X_count_own = ft_printf("%X %X\n", X_test1, X_test2);
	X_count_old = printf("%X %X\n", X_test1, X_test2);
	printf("Own: %d\n", X_count_own);
	printf("Old: %d\n", X_count_old);

	int p_count_own;
	int p_count_old;
	printf("\nargument --> p \n");
	p_count_own = ft_printf("%p %p\n", p_test1, p_test2);
	p_count_old = printf("%p %p\n", p_test1, p_test2);
	printf("Own: %d\n", p_count_own);
	printf("Old: %d\n", p_count_old);

	printf("\n=======================\n");
}
*/