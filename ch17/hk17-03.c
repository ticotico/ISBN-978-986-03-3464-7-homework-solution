#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<ctype.h>

//#define DEBUG

double add_ (double a, double b)
{
	return a + b;
}

double sub_ (double a, double b)
{
	return a - b;
}

double mut_ (double a, double b)
{
	return a * b;
}

double div_ (double a, double b)
{
	if (b != 0.0)
		return a / b;
	printf("div 0 error\n");
	exit(-1);
}

typedef double (*do_op)(double, double);

do_op char_to_opptr(char c)
{
	switch (c) {
		case '+':
			return add_;
		case '-':
			return sub_;
		case '*':
			return mut_;
		case '/':
			return div_;
		case '(': case ')':
			return NULL;
		default:
			printf("line: %d: unknown op %c\n", __LINE__, c);
			exit(-1);
	}
}

typedef struct oplist{
	char op;
	struct oplist *next;
}OpList;

OpList *push_Op(OpList *old_head, char op)
{
	OpList *new_head = (OpList *) malloc (sizeof(OpList));
	assert(new_head != NULL);
	new_head->op = op;
	new_head->next = old_head;
	return new_head;
}

OpList *pop_Op(OpList *old_head, char *op)
{
	if (old_head == NULL) {
		printf("empty of op stack\n");
		exit(-1);
	}
	OpList *new_head = old_head->next;
	*op = old_head->op;
	free(old_head);
	return new_head;
}

int char_to_op_lv(char c)
{
	switch (c){
		case '(': case ')':
		return 0;
		case '+':
		return 1;
		case '-':
		return 2;
		case '*':
		return 3;
		case '/':
		return 4;
		default:
		printf("nuknown char %c\n", c);
		exit(-1);
	}
}

typedef struct numlist{
	double num;
	struct numlist *next;
}NumList;

NumList *push_Num(NumList *old_head, double num)
{
	NumList *new_head = (NumList *) malloc (sizeof(NumList));
	assert(new_head != NULL);
	new_head->num = num;
	new_head->next = old_head;
	return new_head;
}

NumList *pop_Num(NumList *old_head, double *num)
{
	if (old_head == NULL) {
		printf("empty of stack number\n");
		exit(-1);
	}
	NumList *new_head = old_head->next;
	*num = old_head->num;
	free(old_head);
	return new_head;
}

int is_num(char *s)
{
	if (s[0] == '*' || s[0] == '/' || s[0] == '(' || s[0] == ')')
		return 0;
	else if (s[0] == '+' || s[0] == '-') {
		if(isdigit(s[1]))
			return 1;
		else
			return 0;
	}
	else if (isdigit(s[0]))
		return 1;
	printf("line: %d nuknown str %s\n", __LINE__, s);
	exit(-1);
}

void do_op_once (NumList **num_stack, OpList **op_stack)
{
	double num1, num2, num_result;
	do_op fptr;
	char op;
	*num_stack = pop_Num(*num_stack, &num2);
	*num_stack = pop_Num(*num_stack, &num1);
	*op_stack = pop_Op(*op_stack, &op);
	fptr = char_to_opptr(op);
	num_result = fptr(num1, num2);
#ifdef DEBUG
printf("%f %f %f\n", num1, num2, num_result);
#endif
	*num_stack = push_Num(*num_stack, num_result);
}

int main (void)
{
	char cur_op_lv, last_op_lv;
	char str[20];
	int cur_num_count = 0;
	int cur_str_is_num = 0;
	double num_result = 0.0;
	NumList *num_stack = NULL;
	OpList *op_stack = NULL;
	
	while (scanf("%10s", str) != EOF) {
		cur_str_is_num = is_num(str);
		if (!cur_str_is_num && str[0] != '(' && str[0] != ')') {
			cur_op_lv = char_to_op_lv(str[0]);
		}
		if (cur_str_is_num) {
			num_stack = push_Num(num_stack, atof(str));
			cur_num_count++;
			continue;
		}
		else if (str[0] == '(') {
			op_stack = push_Op(op_stack, str[0]);
			continue;
		}
		else if (str[0] == ')') {
			assert(op_stack != NULL);
			while(op_stack->op != '(') {
				do_op_once(&num_stack, &op_stack);
				cur_num_count--;
			}
			op_stack = pop_Op(op_stack, &str[0]);
			continue;
		}
		else if (str[0] == '+' || str[0] == '-' 
				|| str[0] == '*' || str[0] == '/') {
				cur_op_lv = char_to_op_lv(str[0]);
				if(op_stack == NULL || op_stack->op == '(')
					last_op_lv = 0;
				else
					last_op_lv = char_to_op_lv(op_stack->op);
			while(cur_op_lv < last_op_lv) {
				do_op_once(&num_stack, &op_stack);
				cur_num_count--;
				if(op_stack == NULL || op_stack->op == '(')
					last_op_lv = 0;
				else
					last_op_lv = char_to_op_lv(op_stack->op);
			}
			op_stack = push_Op(op_stack, str[0]);
		}
		else {
			printf("line %d input error: %s\n", __LINE__,str);
			exit(-1);
		}
	}
	
	while (cur_num_count > 1) {
		do_op_once(&num_stack, &op_stack);
		cur_num_count--;
	}
	num_stack = pop_Num(num_stack, &num_result);
	printf("%f\n", num_result);
	return 0;
}
