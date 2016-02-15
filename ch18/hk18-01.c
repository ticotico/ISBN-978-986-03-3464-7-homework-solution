#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "queue.h"

void init (Queue *s)
{
	s->rear = NULL;
	s->front = NULL;
}
int empty (Queue *s)
{
	return (s->rear == NULL && s->front == NULL);
}
void enqueue (Queue *s, Datatype data)
{
	Listnode *current = (Listnode *) malloc (sizeof(Listnode));
	assert(current != NULL);
	current->data = data;
	
	if (empty(s)) {
		current->next = NULL;
		s->rear = current;
		s->front = current;
		return;
	}
	//if s is not epty
	current->next = s->rear;
	s->rear = current;
	return;
}
Datatype dequeue(Queue *s)
{
	Datatype data;
	Listnode *current;
	if (empty(s)) {
		printf("Queoe is empty.\n");
		exit(0);
	}
	data = s->front->data;
	//only one data-> after dequeue, queue is empty
	if (s->rear == s->front) {
		current = s->front;
		s->rear = NULL;
		s->front = NULL;
		free(current);
		return data;
	}
	//shift current to new front
	for (current = s->rear; 
		current->next != s->front && current->next != NULL;
		current = current->next);
	current->next = NULL;
	free(s->front);
	s->front = current;
	return data;
}
