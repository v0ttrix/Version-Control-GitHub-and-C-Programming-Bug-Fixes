#include <stdio.h>

void printWelcomeMenu();
void printOptions();
void add();
void subtract();


void main()

{

	printWelcomeMenu();

	printOptions();

	int inputNum;

	printf("Enter operation number: ");
	scanf("%d", &inputNum);

	switch (inputNum)
	{
	case 1:
		add();
	case 2:
		subtract();
	}

}

void printWelcomeMenu() {
	printf(" **********************\n");
	printf("**   Welcome to the   **\n");
	printf("**   BCS Calculator   **\n");
	printf(" **********************\n");
}

void printOptions() {
	printf("1. Add\n");
	printf("2. Subtract\n");
}

void add()
{
	double num1, num2, result;
	printf("Enter the first value:");
	scanf("%lf", &num1);
	printf("Enter the second value:");
	scanf("%lf", &num2);
	result = num1 + num2;
	printf("%lf + %lf = %lf\n", num1, num2, result);
}

void subtract()
{
	int num1, num2, result;
	printf("Enter the first value:");
	scanf("%d", &num1);
	printf("Enter the second value:");
	scanf("%d", &num2);
	result = num1 - num2;
	printf("%d - %d = %d\n", num1, num2, result);
}

