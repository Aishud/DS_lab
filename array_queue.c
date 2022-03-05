#include <stdio.h>
#define MAX 100
int queue[MAX], head = -1, tail = -1;

void push(int data)
{
    if (tail == MAX - 1)
        printf("\nQueue overflow");
    else if(tail == -1)
    {
    	head = 0;
    	tail  = 0;
    	queue[tail] = data;
    }
    else
		queue[++tail] = data;
}

void pop()
{
    int del;
    if (head == -1)
        printf("\nQueue is empty");
    else if(head == tail)
    {
    	printf("\n%d popped", queue[head]);
    	head = -1;
    	tail  = -1;
    }
    else
    {
        del = queue[head++];
        printf("\n%d popped", del);
    }
}

void display()
{
    if (head== -1)
        printf("\nQueue is empty");
    else
    {
        printf("Queue elements: ");
        for (int i = head; i <= tail; i++)
        {
            printf("%d  ", queue[i]);
        }
    }
}

int main()
{
    int ch, element;
    printf("\nOperations are:-");
    printf("\n1.Push");
    printf("\n2.Pop");
    printf("\n3.Display queue elements");
    printf("\n4.Exit");
    do
    {
        printf("\n____________________\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &element);
            push(element);
            printf("Value pushed");
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            break;
        }
    } while (ch !=4);

    return 0;
}
