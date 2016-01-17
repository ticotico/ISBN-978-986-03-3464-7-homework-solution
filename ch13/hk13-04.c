/*
寫一個程式模擬書架。假設你有 255 本書和一個可容納 8 本書的書架。 255 本書
有一個由 1 到 255 的號碼，且一開始都在書櫃裡。8 本書的書架在桌上，且一開始
是空的。當我們想看一本書的時候，我們會先在書架上找，如果找到我們就取出來看
，看完之後就塞回書架的最右邊。如果書架上找不到，我們就從書櫃裡找出來看，
看完之後一樣塞回書架的最右邊但此時書假可能已經有8本書了，此時我們要將書架
最左邊的書放回書櫃，將書架上的書向左挪，空出最右邊放我們剛看完的書。請
模擬一段時間之後書架的情形。
由於一本書的號碼最大到 255，我們可以用 8 個位元來表示。同時一個
long long int 有八個位元組，剛好可以模擬 8 本書的書架。
輸入為一介於 1 到 255 的整數序列，代表我們看書的順序。程式必須處理
所有的輸入直到 EOF。輸出為 8 個整數，代表由左到右最後書架中書的編碼，
如果書架該位置沒有書則輸出 0 。
*/

#include <stdio.h>
void print_books (unsigned long long int lli)
{
	int i;
	for (i = 7; i >= 0; i--)
		printf("%lld ", ((lli & ((unsigned long long int) 255 << (i * 8))) >> (i * 8)));
	printf("\n");
	return ;
}

int find_book(unsigned long long int book_series, unsigned long long int book_id)
{
	int i = 0;
	while (book_series % (unsigned long long int) 256 != book_id && i < 8) {
		i++;
		book_series /= 256;
	}
	return i;
}

unsigned long long int shift_ith_book (unsigned long long int book_series, int i)
{
	unsigned long long int mask[9] = {0};
	unsigned long long int not_shift_shild;
	unsigned long long int shift_shild;
	int j;
	
	mask[0] = 255;
	for (j = 1; j < 8; j++)
		mask[j] = mask[0] << (j * 8);
	
	not_shift_shild = (unsigned long long int) 0;
	for (j = i + 1; j < 8; j++)
		not_shift_shild = not_shift_shild | mask[j];
	not_shift_shild = book_series & not_shift_shild;
	shift_shild = (unsigned long long int) 0;
	for (j = 0; j < i; j++)
		shift_shild = shift_shild | mask[j];
	shift_shild = shift_shild & book_series;
	shift_shild = shift_shild << 8;
			
	book_series = (unsigned long long int) 0;
	book_series = book_series | not_shift_shild;
	book_series = book_series | shift_shild;
	
	return book_series;
}

int main (void)
{
	unsigned long long int book_series = 0;
	unsigned long long int mask[9] = {0};
	unsigned long long int new_book_id;
	unsigned long long int take_out_shild;
	int i, j;
	
	//creat mask
	mask[0] = 255;
	for (j = 1; j < 8; j++)
		mask[j] = mask[0] << (j * 8);
	
	while (scanf("%lld", &new_book_id) != EOF) {
		//find book if in babinet
		i = find_book(book_series, new_book_id); 
		//return ith book if the new book in cabinet else return 8

		//take out the book
		if (i != 8)	{
			take_out_shild = (unsigned long long int) 0;
			for (j = 0; j < 8; j++)
				if (j != i)
					take_out_shild = take_out_shild | mask[j];
			book_series = book_series & take_out_shild;
		}
				
		//shift books in cabinet
		if (i == 8) // don't need take out old book, shift directly
			book_series = book_series << 8;
		else {
			book_series = shift_ith_book(book_series, i);
		}
		//place new book at right most
		book_series = book_series | new_book_id;
	}
	print_books(book_series);
	return 0;
}
