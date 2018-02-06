#include <stdio.h>
#include <stdlib.h>

int main(void)
{
/*	int height, width, length, volume, weight;
	
	height = 8;
	length = 12;
	width = 10;
	volume = height * length * width;
	weight = (volume + 165) / 166;

	printf("Dimensions: %dx%dx%d\n",length, width, height);
	printf("Volume (cubic inches): %d\n", volume);
	printf("Dimensional weight (pounds): %d\n", weight);
*/

	char ch;

//	ch = malloc(sizeof(char) * 100);
	
	while ((ch = getchar()) == ' ')	
		;
	
	for (; (ch = getchar()) != 't'; )
		printf("%c\n", getchar());

	return 0;
}
