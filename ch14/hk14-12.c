/*
寫一個程式選數字。程式要從 n 個不同數字選 m 個數字，
其中 e 個必須是偶數，請列出所有的選法。
輸入第一行為 n、m、e。第二行為 n 個待選的不同數字。
輸出為所有的選法。一個選法一行，其中 m 個數字由小到
大排列，如果第一個數字相同，則由第二個數字由小到大
排列，於類推。
參數規範: 0 < n <= 30, 0 < m <= min(n, 8), 0 < w, v <= min(m, 4)
*/

#include <stdio.h>

int prt_array(int n, int m, int e, int array[])
{
	int i;
	static int print_buf[32];
	static int count = 0;
	int cur_count = count;
	static int array_start = 0;
	
	if (m == 0) {
		for (i = 0; i < count; i++)
			printf("%d ", print_buf[i]);
		printf("\n");
		return count;
	}
	
	for (i = array_start; i < n; i++) {
		//place even
		if (array[i] % 2 == 0 && e > 0) {
			print_buf[cur_count] = array[i];
			count = cur_count + 1;
			array_start = i + 1;
			prt_array(n, m - 1, e - 1, array);
		}
		//place odd
		else if (array[i] % 2 == 1 && m - e > 0){
			print_buf[cur_count] = array[i];
			count = cur_count + 1;
			array_start = i + 1;
			prt_array(n, m - 1, e, array);
		}
		
	}
	
	return 0;
}

int main (void)
{
	int n, m, e; //輸入n個數，輸出m個數，其中e個是偶數
	int array[32], tmp[32], temp;
	int i, j;
	
	scanf("%d%d%d", &n, &m, &e);
	for (i = 0; i < n; i++) {
		scanf("%d", array + i);
		tmp[i] = array[i];
	}
		
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (tmp[j] < tmp[i]) {
				temp = tmp[j];
				tmp[j] = tmp[i];
				tmp[i] = temp;
			}
			
	//for (i = 0; i < n; i++)
		//printf("%d\t", tmp[i]);
	//printf("\n");
	
	prt_array(n, m, e, tmp);
	
	return 0;
}
