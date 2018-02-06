#include <stdio.h>

#define N 10

void
max_min(int *a, int n, int *max, int *min);

void
max_min_test(int *a, int n, int *max, int *min);

void
test(int *a, int n, int *max);

int main(void){
	
	int b[N], i, big, small;
	
	printf("Enter %d numbers: \n", N);
	for (i = 0; i < N; i++){
		scanf("%d", &b[i]);
	}
	

//	test(b, 1, &big);
	max_min_test(b, N, &big, &small);

	printf("Largest: %d\n", big);
	printf("Smallest: %d\n", small);

	return 0;
}

void max_min(int *a, int n, int *max, int *min){

	int i;

	max = min = a;

//	printf("this is the first element of b: %d\n", *max);

	for (i = 1; i < n; i++){
		if (*(a + i) > *max) {
			
			max = a + i;
			
//			printf("fir %d\n", *max);

		}
		else if (*(a + i) < *min){

			min = a + i;
			
//			printf("sec %d\n", *min);
		}
	}

	printf("Largest: %d\n", *max);

	printf("Smallest: %d\n", *min);

}

void max_min_test(int a[], int n, int *max, int *min){
	int i; 

	*min = *a;
	*max = *a;

	for (i = 0; i < n; i++){
		if (*max < *(a+i))
			*max = *(a + i);
		else if (*min > *(a + i))
			*min = *(a + i);
	}
	
	printf("Largest: %d\n", *max);

	printf("Smallest: %d\n", *min);

}

void test(int *a, int n, int *max){

	int i;

	max = a;
	
	for (i = 0; i < 10; i++){

		printf("%d\n", *(max + i));

	}
}

/******************************************************************************************************************
 * To better understand this, why max_min_test can do the right things while the max_min cannot.                  *
 * cause max_min_test function means the pointer max is point to big, in order to keep the change outside,        *
 * the pointer to this point is not allowed to change, if the pointer change, then it's not point to the "big",   *
 * it points to somewhere else, thus the wrong answer comes.                                                      *
 * ****************************************************************************************************************/
