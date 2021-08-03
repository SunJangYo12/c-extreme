// gcc -std=99 makro.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ABC 6
#define CODE \
   printf("xx\n");

#define PRINT(a) printf("%d\n", a);
#define LOOP(v, s, e) for (int v=s; v<=e; v++) {
#define ENDLOOP }

#define LOG_ERROR(format, ...) \
    fprintf(stderr, format, __VA_ARGS__)
#define VERSION "2.3.4"

int main() {
   int x = 5;
   int y = ABC;

   printf("nilai : %d\n", y + x);
   CODE
   LOOP(counter, 1, 10)
     PRINT(counter)
   ENDLOOP
}

int xmain(int argc, char **argv) {
	if (argc < 3) {
	    LOG_ERROR("invalid number of arguments version %s\n", VERSION);
	    exit(1);
    }
    
    if (strcmp(argv[1], "-n") != 0) {
    	LOG_ERROR("%s is a wrong param at index %d for version %s.", argv[1], 1, VERSION);
        exit(1);
    }
    
    return 0;
}
	
	

