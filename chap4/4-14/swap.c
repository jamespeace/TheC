#include <stdio.h>
#define swap(t, x, y) {\
	t = x;\
	x = y;\
	y = t;\
}

int main(void)
{
	int x = 1;
	int y = 2;
	int t;
	printf("x = %d, y = %d\n", x, y);
	swap(t, x, y);
	printf("x = %d, y = %d\n", x, y);
	return 0;
}
