#include <stdio.h>

void func(int a) {
	a = 5;
}
void func_passbyvalue(int *a) {
	int b = 9;
	*a = 5;
	a = &b;
}

int sum(int a, int b){
	return a + b;
}
int subtrack(int a, int b){
	return a - b;
}

typedef int bool_t;
typedef bool_t (*less_than_func_t)(int, int);
bool_t less_than(int a, int b) {
	return a < b ? 1 : 0;
}
bool_t less_than_modular(int a, int b) {
	return (a % 5) < (b % 5) ? 1 : 0;
}

int main() {
	int x = 3;
	printf("sebelum fungsi dicall: %d\n", x);
	func(x);
	printf("setelah fungsi dicall: %d\n\n", x);
	
	int *xptr = &x;
	printf("sebelum fungsi passbyvalue dicall: %d\n", x);
	printf("sebelum pointer passbyvalue dicall: %p\n", (void*)xptr);
    func_passbyvalue(xptr);
    printf("setelah fungsi passbyvalue dicall: %d\n", x);
    printf("setelah pointer passbyvalue dicall: %p\n\n", (void*)xptr);
    
    /* memanggil fungsi dengan pointer */
    int (*func_ptr)(int, int);
    func_ptr = NULL;
    func_ptr = &sum;
    int result = func_ptr(5, 4);
    printf("Sum: %d\n", result);
    
    func_ptr = &subtrack;
    result = func_ptr(5, 4);
    printf("Subtrack: %d\n\n", result);
    
    /* seperti diatas tapi direkomendasikan */
    less_than_func_t xfunc_ptr = NULL;
    xfunc_ptr = &less_than;
    bool_t xresult = xfunc_ptr(3, 7);
    printf("less: %d\n", xresult);
    
    xfunc_ptr = &less_than_modular;
    xresult = xfunc_ptr(3, 7);
    printf("less_modular: %d\n", xresult);
}