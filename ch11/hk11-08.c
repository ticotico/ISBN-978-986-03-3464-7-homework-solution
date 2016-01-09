/*
重作前一題，且每行皆輸出剛好 m 個字元，如果一行
不足 m 個字元則加空格，且空格必須平均分配。如果
空格無法平均分配，則多的空格必須加在前面的字後面
*/
#include <stdio.h>
#include <string.h>

void print_line(char *temp, int m, int words)
{
	int space_count, total_space;
	int len_out, i, j;
	char out[238] = "\0", space[2] = " \0";
	char *start;
	total_space = m - strlen(temp) + words - 1;
	start = temp;
	start = strtok(start, space);
	for (i = 0; start != NULL; i++) {
		strcat(out, start);
		len_out = strlen(out);
		space_count = total_space / (words - 1) + (i < total_space % (words - 1) ? 1 : 0);
		for (j = 0; j < space_count; j++)
			out[len_out++] = ' ';
		out[len_out] = '\0';
		start = strtok(NULL, space);
	}
	printf("%s\n", out);
	return;
}

int main (void)
{
	char buf_input[34], temp[238] = "\0";
	const char space[2] = " \0";
	int m;
	int words = 0;
	scanf("%d", &m);
	while(scanf("%s", buf_input) != EOF) {
		if (strlen(buf_input) + strlen(temp) + 1 < m) {
			strcat(temp, buf_input);
			strncat(temp, space, 2);
			words++;
		} else {
			print_line(temp, m, words);
			
			strcpy(temp, buf_input);
			strncat(temp, space, 2);
			words = 1;
		}
	}
	print_line(temp, m, words);
	return 0;
}
