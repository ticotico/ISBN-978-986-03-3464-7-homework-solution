/*
網路IP位址共有32個位元，一般為了表示方便起見都寫成
四個位元組，例如192.168.61.82。再決定兩個網路IP是否
在同一個(subnet)時，會使用一個子網路遮罩(subnet mask)
。子網路遮罩是一個高位元為1，低位元為0的IP位址。例如
26個高位元為1，6個低位元為0，則子網路遮罩就會是255.255.255.192
。如果兩個網路IP和子網路遮罩做and運算，就是擷取一定數目的高位元
，這些高位元就巷子網路的註標，相同住標代表相同子網域。
現給定子網路遮罩，請決定兩個IP是否在同一個子網域。
輸入的第一行為四個整數的子網路遮罩，第二行為網路IP位址A，
第三行開始為任意的IP位址。輸出為任意網路IP中有幾個與A位於
相同的子網域。
城市必須處理所有的輸入直到EOF
參數規範: 如果IP位址的任一部份為N，則0 <= n < 255
*/

#include <stdio.h>

int main (void)
{
	unsigned char subnet_mask[4];
	unsigned char A[4];
	unsigned char input_ip[4];
	int count = 0, flag;
	int i, j;
	for (i = 0; i < 4; i++)
		scanf("%d", &(subnet_mask[i]));
	for (i = 0; i < 4; i++)
		scanf("%d", &(A[i]));
	i = 0;
	
	while(scanf("%d", &(input_ip[i % 4])) != EOF) {
		if (i % 4 == 3) {
			flag = 0;
			for (j = 0; j < 4; j++)
				if ((subnet_mask[j] & input_ip[j]) == (subnet_mask[j] & A[j]))
					flag++;
			if (flag == 4)
				count++;
		}
		i++;
	}
	printf("%d\n", count);
	return 0;
}
