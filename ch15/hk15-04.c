/*
寫一個結構紀錄井字遊戲棋盤，
init 將 ttt 指向井字遊戲棋盤清為 0。
play 嘗試在 board[x][y] 由 color 方下一子。
如果可以下，則 board[x][y] 會紀錄為 color，
並且回傳 0。如果 board[x][y] 不可以下，則回傳 -1。
win 檢查 color 方是否已經獲勝。如果是則回傳 1 。否則
回傳 0。

重作作業6.9，由於 play 的函式有檢查的功能，我們不在假設
所有的著手都是正常可下的。如果發現著手有錯誤，則程式會
印出"illegal move"然後馬上結束。
*/
#include <stdio.h>

typedef struct {
	int board[3][3];
} TicTacToe;

void init (TicTacToe *ttt)
{
	int i, j;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			ttt->board[i][j] = 0;
	return ;
}

int play (TicTacToe *ttt, int color, int x, int y)
{
	if (ttt->board[x][y] != 0)
		return -1;
	
	ttt->board[x][y] = color;
	return 0;
}

int win (TicTacToe *ttt, int color)
{
	int i, j;
	int cond1, cond2;
	
	for (i = 0; i < 3; i++) {
		cond1 = 1;
		cond2 = 1;
		for (j = 0; j < 3; j++) {
			cond1 &= (ttt->board[i][j] == color);
			cond2 &= (ttt->board[j][i] == color);
		}
		
		if (cond1 || cond2)
			return 1;
	}
	
	cond1 = 1;
	cond2 = 1;
	for (i = 0; i < 3; i++) {
		cond1 &= (ttt->board[i][i] == color);
		cond2 &= (ttt->board[2-i][i] == color);
	}
	if (cond1 || cond2)
		return 1;
	
	return 0;
}

int main (void)
{
	int i;
	int input;
	int x, y, color = 1;
	TicTacToe ttt;
	init(&ttt);
	
	for (i = 0; i < 9 && !(win(&ttt, color)); i++) {
		scanf("%d", &input);
		x = (input - 1) / 3;
		y = (input - 1) % 3;
		color = (i % 2) + 1;
		if (play(&ttt, color, x, y) == -1) {
			printf("illegal move\n");
			return -1;
		}
	}
	
	printf("%d\n", input);
	return 0;
}
