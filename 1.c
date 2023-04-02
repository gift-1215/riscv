// description: a = a / b
#include <stdio.h>
int main ()
{
	int a, b;
	FILE *input = fopen("../input/1.txt","r");
	fscanf(input, "%d %d", &a, &b);
	fclose(input);
	//a = a / b;
	asm volatile(
		"mov %[A], %%eax\n\t"
		"mov %[B], %%ebx\n\t"
		"xor %%edx, %%edx\n\t"

		"idiv %%ebx\n\t"
		"mov %%eax, %[A]\n\t"

		:[A] "+r"(a)
		:[B] "r"(b)
		:"eax","ebx","edx"
			
	);
	printf("%d\n", a);
	return 0;
}
