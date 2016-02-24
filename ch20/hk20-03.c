#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#

int comp(const void *data1, const void *data2)
{
	if (*(char *)data1 < *(char *)data2)
		return -1;
	if (*(char *)data1 > *(char *)data2)
		return 1;
	return 0;
}

int add_alpha(char c, char *alpha, int alpha_count)
{
	int i;
	if (!isupper(c))
		return alpha_count;
	if (isupper(c))
		for (i = 0; i < alpha_count; i++)
			if (c == alpha[i]) return alpha_count;
	alpha[alpha_count++] = c;
	return alpha_count;
}
void replace_alpha (const char *num, const char *alpha,
	char *b, const char *a)
{
	int i, j;
	for (i = 0; i < 5; i++) {
		if (isdigit(a[i]))
			b[i] = a[i];
		if (isupper(a[i]))
			for (j = 0; j < 15 && alpha[j] != a[i]; j++);
		b[i] = num[j];
	}
	b[5] = '\0';
}

int main (void)
{
	char num[15], alpha[15] = {0};
	char a1[6], a2[6], a3[6];
	char b1[6], b2[6], b3[6];
	char c;
	int i, j, alpha_count = 0;
	int seed = 1, temp;
	
	scanf("%s%s%s", a1, a2, a3);
	
	for (i = 0; i < 5; i++) {
		c = a1[i];
		alpha_count =add_alpha(c, alpha, alpha_count);
		c = a2[i];
		alpha_count =add_alpha(c, alpha, alpha_count);
		c = a3[i];
		alpha_count =add_alpha(c, alpha, alpha_count);
	}
	qsort(alpha, alpha_count, sizeof(char), comp);
	
	for (i = 0; i < alpha_count; i++)
		seed *= 10;
	for (i = 0; i < seed; i++) {
		temp = i;
		for (j = 0; j < alpha_count; j++) {
			num[j] = temp % 10 + '0';
			temp /= 10;
		}
		
		replace_alpha(num, alpha, b1, a1);
		replace_alpha(num, alpha, b2, a2);
		replace_alpha(num, alpha, b3, a3);
		printf("%d + %d = %d\n", atoi(b1), atoi(b2), atoi(b3));
		printf("%s + %s = %s\n", b1, b2, b3);
		if (atoi(b1) + atoi(b2) == atoi(b3))
			for (j = 0; j < alpha_count; j++)
				printf("%c = %d, ", alpha[j], num[j] - '0');
		putchar('\n');
		
	}
	return 0;
}
