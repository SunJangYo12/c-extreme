#include <stdio.h>
#include <stdlib.h> // malloc and free second create_an_integer function

/* kegunaan pointer generik */
void print_byte(void *data, size_t length) {
	char delim = ' ';
	unsigned char *ptr = data;
	
	for (size_t i=0; i<length; i++) {
		printf("%c 0x%x", delim, *ptr);
		delim = ',';
		ptr++;
	}
	printf("\n");
}

/*int *create_an_integer(int default_value) {
	int var = default_value;
	return &var;
}*/
int *create_an_integer(int default_value) {
	int *var_ptr = (int*)malloc(sizeof(int)); // merubah var_ptr dari lokal ke heap dan bisa diakses diluar fungsi
	*var_ptr = default_value;
	
	return var_ptr;
}

int main() {
	int var = 100;
	int *ptr = 0;
	ptr = &var;
	//*ptr = 200;
	printf("basic: %d\n\n", *ptr);
	
	int varx = 1;
	int *int_ptr = NULL;
	int_ptr = &varx;
	
	char *char_ptr = NULL;
	char_ptr = (char*) &varx;
	
	printf("sebelum++\n");
	printf("int_ptr:%u\n", (unsigned int) int_ptr);
	printf("char_ptr:%u\n\n", (unsigned int) char_ptr);
	
	int_ptr++;
	char_ptr++;
	
	printf("setelah++\n");
	printf("int_ptr:%u\n", (unsigned int) int_ptr);
	printf("char_ptr:%u\n\n", (unsigned int) char_ptr);
	
	int arr[5];
	for (int i=0; i<5; i++) {
		arr[i] = i;
	}
	int *xptr = &arr[0];
	for (;;) {
		printf("%d\n", *xptr);
		if (xptr == &arr[5 - 1]) {
			break;
	    }
	    xptr++;
	}
	
	// generik pointer
	int avar = 9;
	int *aptr = &avar;
	void *agptr = aptr;
	printf("pointer generik: %d\n\n", agptr);
	
	int a = 9;
	double b = 18.9;
	print_byte(&a, sizeof(int));
	print_byte(&b, sizeof(double));
	
	// dangling pointer
	int *dptr = NULL;
	dptr = create_an_integer(10);
	printf("\n\ndangling pointer: %d\n\n", *dptr);
	free(dptr); // second create_an_integer function
}