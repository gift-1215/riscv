// description: matrix muliply with two-level for loop
#include<stdio.h>
int main()
{
int f,i=0;
int h[9]={0}, x[3]={0}, y[3]={0};
FILE *input = fopen("../input/3.txt","r");
for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
fclose(input);
int *p_x = &x[0] ;
int *p_h = &h[0] ;
int *p_y = &y[0] ;
for (i = 0 ; i < 3; i++)
{
	p_x = &x[0] ;
	for (f = 0 ; f < 3; f++)
		asm volatile(
			"mul %[T],%[H],%[X]\n\t"
			"add %[Y],%[Y],%[T]\n\t"
			"addi %[A],%[A],4\n\t"
			"addi %[C],%[C],4\n\t"
			"li %[T], 2\n\t"
			"bne %[F],%[T], label\n\t"
			"addi %[B],%[B],4\n\t"
			"label:\n\t"
			:[Y] "+r"(*p_y),[A] "+r"(p_x),[C] "+r"(p_h),[B] "+r"(p_y)
			:[T] "r"(0),[H] "r"(*p_h),[X] "r"(*p_x),[F] "r"(f)
			:

				);
}
p_y = &y[0];
for(i = 0; i<3; i++)
printf("%d \n", *p_y++);
return(0) ;
}
