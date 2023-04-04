// description: matrix muliply without for loop
#include<stdio.h>
int main()
{
int i=0;
int h[9]={0}, x[3]={0}, y[3]={0};
FILE *input = fopen("../input/4.txt","r");
for(i = 0; i<9; i++) fscanf(input, "%d", &h[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &x[i]);
for(i = 0; i<3; i++) fscanf(input, "%d", &y[i]);
fclose(input);
int *p_x = &x[0] ;
int *p_h = &h[0] ;
int *p_y = &y[0] ;

asm volatile(
			"li %[I], 0\n\t"
			
			"loop1:\n\t"
			"li %[F], 0\n\t"
			"li %[Y], 0\n\t"

			"loop2:\n\t"

			"lw %[X],0(%[A])\n\t"
			"lw %[H],0(%[C])\n\t"

			"mul %[T],%[H],%[X]\n\t"
			"add %[Y],%[Y],%[T]\n\t"	
			"addi %[A],%[A],4\n\t"
			"addi %[C],%[C],4\n\t"	
			
			"addi %[F],%[F],1\n\t"
			"li %[T], 3\n\t"
			"bne %[F],%[T], loop2\n\t"
			
			//end of loop2
			"sw %[Y],0(%[B])\n\t"
			
			"addi %[A],%[A],-12\n\t"
			"addi %[B],%[B],4\n\t"
			
			"addi %[I],%[I],1\n\t"
			"li %[T], 3\n\t"
			"bne %[I],%[T], loop1\n\t"
			
			//end of loop1
			
			//"li %[T],1\n\t"
			//"sw %[T],0(%[B])\n\t"


			:[A] "+r"(p_x),[C] "+r"(p_h),[B] "+r"(p_y)
			:[I] "r"(0),[F] "r"(0),[T] "r"(0),[H] "r"(0),[X] "r"(0),[Y] "r"(0)
			:

		);

p_y = &y[0];
for(i = 0; i<3; i++)
printf("%d \n", *p_y++);
return(0) ;
}
