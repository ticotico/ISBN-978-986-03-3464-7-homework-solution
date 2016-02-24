#include <stdio.h>
#include <stdlib.h>

int main (void)
{
	int i, mod, index = 0;
	int base_origin, base_new;
	char c, input_str[80], output_str[80];
	long int input_num;
	
	scanf("%d", &base_origin);
	getchar();
	scanf("%s", input_str);
	scanf("%d", &base_new);
	
	input_num = strtol(input_str, NULL, base_origin);
	if (input_num < 0)  {
		input_num *= -1;
		output_str[index] = '-';
	}
	while (input_num != 0) {
		mod = input_num % base_new;
		if (mod < 10)
			output_str[index++] = mod + '0';
		else
			output_str[index++] = mod - 10 + 'a';
		input_num /= base_new;
	}
	output_str[index] = '\0';
	
	for (i = (output_str[0] == '-'); i < index / 2; i++) {
		c = output_str[i];
		output_str[i] = output_str[index - i - 1];
		output_str[index - i - 1] = c;
	}
	
	printf("%d\n%s\n%d\n", base_origin, input_str, base_new);
	printf("%s\n", output_str);
	return 0;
}
