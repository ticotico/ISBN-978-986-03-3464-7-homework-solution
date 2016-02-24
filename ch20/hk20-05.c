#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int comp(const void *data1, const void *data2)
{
	return *(char *)data1 - *(char *)data2;
}

int main (void)
{
	int i, j, k, n;
	int alpha_count = 0;
	int max_nth = 1, cur_nth;
	char c;
	char old_s[3][6] = {0};
	char new_s[3][6] = {0};
	char convert[2][8] = {0};
	
	scanf("%s%s%s", old_s[0], old_s[1], old_s[2]);
	
	for (i = 0; i < 3; i++)
		for (j = 0; j < 6; j++)
			if(isupper(old_s[i][j])) {
				for (k = 0; k < alpha_count && convert[0][k] != old_s[i][j]; k++);
				if (k == alpha_count)
					convert[0][alpha_count++] = old_s[i][j];
			}
	convert[0][alpha_count] = '\0';
	qsort(convert[0], alpha_count, sizeof(char), comp);
	
	for (i = 0; i < alpha_count; i++)
		max_nth *= 10;
	
	for (i = 0; i < max_nth; i++) {
		cur_nth = i;
		for (j = 0; j < alpha_count; j++) {
			c = cur_nth%10 + '0';
			cur_nth /= 10;
			convert[1][j] = c;
		}
		convert[1][j] = '\0';
		
		for (j = 0; j < 3; j++)
			for (k = 0; k < 6; k++) {
				if (isdigit(old_s[j][k]))
					new_s[j][k] = old_s[j][k];
				if (isupper(old_s[j][k])) {
					for (n = 0; n < alpha_count; n++)
						if (old_s[j][k] == convert[0][n])
							new_s[j][k] = convert[1][n];
				}
			}
		
		if(atoi(new_s[0]) + atoi(new_s[1]) == atoi(new_s[2])) {
			for (j = 0; j < alpha_count; j++)
				printf("%c = %c ", convert[0][j], convert[1][j]);
			putchar('\n');
		}
	}
	return 0;
}
