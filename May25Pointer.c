//slide cpointerarray mapping 
#include <stdio.h>

int main(){
	int j = 3;
	int *pa;
	int a; 
	int b = 0x2F;
	
	printf("Address of j = %p\n", &j);
	printf("Pointer pa %p\n", pa);
	printf("a = %x\n", a);
	printf("j = %x\n", j);
	
	pa = &j; // pa is address of j
	a = *pa; // a = *pa = j
	*pa = b; // *pa = j = 0x2F
	
	printf("Address of j = %p\n", &j);
	printf("Pointer pa %p\n", pa);
	printf("a = %x\n", a);
	printf("j = %x\n", j);
}
