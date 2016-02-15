#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

int main (void)
{
	int n_city, n_road;
	int *road1, *road2;
	int *d_city;
	int i;
	int cur_distance, cur_city;
	Queue q1, q2;
	Queue *city_stack = &q1, *visited = &q2;
	
	scanf("%d%d", &n_city, &n_road);
	
	road1 = (int *) malloc (n_road * sizeof(int));
	assert(road1 != NULL);
	road2 = (int *) malloc (n_road * sizeof(int));
	assert(road2 != NULL);
	d_city = (int *) malloc (n_city * sizeof(int));
	assert(d_city != NULL);
	
	for (i = 0; i < n_road; i++) {
		scanf("%d%d", &(road1[i]), &(road2[i]));
		assert (road1[i] >= 0 && road2[i] >= 0);
		assert (road1[i] < n_city && road2[i] < n_city);
	}
	
	init(city_stack);
	init(visited);
	for (i = 0; i < n_city; i++) d_city[i] = -1;
	
	d_city[0] = 0;
	enqueue(city_stack, 0);
	while (!empty(city_stack)) {
		cur_city = dequeue(city_stack);
		cur_distance = d_city[cur_city];
		for (i = 0; i < n_road; i++) {
			if (road1[i] == cur_city && d_city[(road2[i])] == -1) {
				enqueue(city_stack, road2[i]);
				d_city[(road2[i])] = cur_distance + 1;
			}
			if (road2[i] == cur_city && d_city[(road1[i])] == -1) {
				enqueue(city_stack, road1[i]);
				d_city[(road1[i])] = cur_distance + 1;
			}
		}
		
	}
	
	for (i = 1; i < n_city; i++) {
		if (d_city[i] == -1) printf("infinity\n");
		else printf("%d\n", d_city[i]);
	}
	
	
	free(road1);
	free(road2);
	free(d_city);
	return 0;
}
