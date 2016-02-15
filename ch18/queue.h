typedef int Datatype;
struct listnode {
	Datatype data;
	struct listnode *next;
};
typedef struct listnode Listnode;

struct queue {
	Listnode *front;
	Listnode *rear;
};
typedef struct queue Queue;

void init (Queue *s);
int empty (Queue *s);
void enqueue (Queue *s, Datatype data);
Datatype dequeue(Queue *s);
