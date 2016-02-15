#define init_2d(array, N, M) \
do { \
	int i, j; \
	for (i = 0; i < N; i++) \
		for (j = 0; j < M; j++) \
			array[i][j] = 0; \
} while(0);
