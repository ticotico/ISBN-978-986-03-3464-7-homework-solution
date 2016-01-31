/*
實作函式 average_grade，回傳學生的平均成績。
若學生沒有修任何課，則平均成績為 0.0 分。
*/
#include <stdio.h>

typedef struct {
	int grade[20];
	int count;
}student;

float average_grade(student *std_ptr)
{
	if (std_ptr->count == 0)
		return 0.0;
	
	float sum = 0.0;
	int i;
	
	for (i = 0; i < std_ptr->count; i++)
		sum += (float) std_ptr->grade[i];
	return sum / (float) std_ptr->count;
}

int main (void)
{
	int i;
	student std;
	scanf("%d", &(std.count));
	for (i = 0; i < std.count; i++)
		scanf("%d", &(std.grade[i]));
	printf("%f\n", average_grade(&std));
	return 0;
}
