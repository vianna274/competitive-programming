#include <stdio.h>

int main () {
	int i1, i2, i3;
	scanf("%d", &i1);
	scanf("%d", &i2);
	scanf("%d", &i3);
	/* dumb solution, but it works :D */
	if (i1 >= i2) {
		if (i1 >= i3) {
			printf("%d eh o maior\n", i1);
		} else {
			printf("%d eh o maior\n", i3);
		}
	} else if (i2 >= i3) {
		printf("%d eh o maior\n", i2);
	} else {
		printf("%d eh o maior\n", i3);
	}

	return 0;
}
