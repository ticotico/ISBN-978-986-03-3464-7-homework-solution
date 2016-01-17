/*
使用整數類別重作前題。由於四個位元剛好可以合併
近一個整數int，使用int存一個ip似乎很方便，請實際驗證。
*/

#include <stdio.h>

int main(void)
{
	int input;
	int subnet_mask = 0;
	int A = 0;
	int input_ip = 0;
	int i, count = 0;
	for (i = 0; i < 4; i++) {
		subnet_mask = subnet_mask << 8;
		scanf("%d", &input);
		subnet_mask |= input;
	}
	
	for (i = 0; i < 4; i++) {
		A = A << 8;
		scanf("%d", &input);
		A |= input;
	}
	
	for (i = 0; scanf("%d", &input) != EOF; i++) {
		input_ip = input_ip << 8;
		input_ip |= input;
		if (i % 4 == 3) {
			if ((subnet_mask & A) == (subnet_mask & input_ip))
				count++;
			input_ip = 0;
		}
	}
	
	printf("%d\n", count);
	return 0;
}
