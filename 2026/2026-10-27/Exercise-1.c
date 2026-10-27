#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));

	int a;
	int b;
	int sum;
	int k;


	printf("Turns: ");
	scanf("%d", &k);

	for (int i=0; i<k; i++) {
		printf("\nTURN: %d\n", i+1);

		a = rand() % 11;
		printf("a: %d\n", a);

		if (a==0) {
			b = rand() % 10 + 1;
		} else {
			b = rand() % 11;
		}
		printf("b: %d\n", b);

		sum = a + b - i;
		printf("sum: %d\n", sum);

		if (sum==0) {
			printf("\nYou WON!\n");
			break;
		}
	}
	
	return 0;
}
