#include <stdio.h>

int main () {
	int i1, i2, i3;

	scanf("%d", &i1);
	scanf("%d", &i2);
	scanf("%d", &i3);

	if ( (i1 + i2) == i3) {
		printf("S\n");
		return 0;
	}
	if ( (i1 + i3) == i2) {
		printf("S\n");
		return 0;
	}
	if ( (i3 + i2) == i1) {
		printf("S\n");
		return 0;
	}
	if (i1 == i2 || i2 == i3 || i1 == i3) {
		printf("S\n");
		return 0;
	}
	printf ("N\n");
	return 0;
}
