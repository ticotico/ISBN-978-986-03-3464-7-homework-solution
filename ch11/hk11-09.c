/*
編寫一個程式來預處理 c 程式，為求簡單起見我們只需
處理 #define 即可。一個 #define 將一個字串 A 定義為
另一個字串 B。意思就是我們看到程式中出現 A 就要代換
為 B，不管 A 在哪裡出現。
為了方便起見，我們假定所有的 #define 都會先定義再使用
。A是一個以字母開頭並只包含字母和數字的字串，B是另一個
字串。A 與 B 長度至多為 n 。
一行程式只會出現一個 #define。 #define 的數量最多為 m 。
只要找到字串 #define 就可以認為是一個有效的 #define。
意即 #define 不會出現在註解或另一個字串中。注意一般的
#define 會避開字串常數的內容不做代換，為求簡單起見，你的
程式只要看到 A 就代換為 B，不管字串 A 在何處出現。
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[128] = "\0", temp_buf[128] , c;
	char newline[2] = "\n\0", space[2] = " \0";
	char A[101][51], B[101][51];
	char output[2048] = "\0";
	char *start;
	int i = 0, j;
	int def_count = 0;
	while(scanf("%c", &c) != EOF) {
		if (c != '\n')
			buf[i++] = c;
		else {
			buf[i] = '\0';
			i = 0;
			//printf("%s\n", buf);
			//check #define
			if (strncmp(buf, "#define", 7) == 0) {
				start = buf;
				start = strtok(start, space);
				start = strtok(NULL, space);
				if (start != NULL)
					strcpy(A[def_count], start);
				start = strtok(NULL, space);
				if (start != NULL) {
					strcpy(B[def_count], start);
					def_count++;
				}
			}
			else {
			//check replace token
				for (j = 0; j < def_count; j++)
					while((start = strstr(buf, A[j])) != NULL) {
					//replace A to B in buf
						strcpy(temp_buf, buf);
						temp_buf[start - buf] = '\0';
						strcat(temp_buf, B[j]);
						strcat(temp_buf, start + strlen(A[j]));
						strcpy(buf, temp_buf);
						//printf("temp_buf = %s\n", temp_buf);
					}
			//strcat buf to opuput
				strcat(output, buf);
				strcat(output, newline);
			}

		}
	}
	printf("\nbelow is out put:\n");
	printf("%s\n", output);
	return 0;
}
