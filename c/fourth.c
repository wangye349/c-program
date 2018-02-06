#include <stdio.h>

#define MAX(x,y) (x >= y ? x : y)
#define MIN(x,y) (x <= y ? x : y)

#define N 2
#undef N                                           //to delete N.

#define DEBUG 1                                    //**change to**"#define DEBUG"
#define DEBUG_NEW 1

#define PRINT(x) (printf("%d\n", x))

int main(void){
	
	int a = 1, b = 2;
	
#if DEBUG                                          //**change to**"#if defined DEBUG"

	PRINT(MAX(a,b));

#elif DEBUG_NEW

	PRINT(MIN(a,b));

#endif

/**************************************************************************************
 * "#if defined DEBUG" is equal to "#ifdef DEBUG"                                     *
 * "#if !defined DEBUG" is equal to "#ifndef DEBUG"                                   *
 * ***********************************************************************************/















	return 0;
}
