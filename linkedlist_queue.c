#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};
struct node *head = NULL, *tail = NULL;
struct node *newNode;
struct node* temp;

struct node* createNode(int data)
{
    newNode = (struct node*)malloc((sizeof(struct node)));
    if(newNode == NULL)
    {
        printf("error");
        exit(0);
    }
    newNode->next = NULL;
    newNode->data = data;
    return(newNode);
}

void push(int data)
{
    newNode = createNode(data);
    if(tail == NULL)
    {
		head = newNode;
		tail  = newNode;
    }
    else
    {
		head->next = newNode;
		tail = newNode;
    }
    printf("%d pushed", data);
}

void pop()
{
    if(head == NULL)
    {
        printf("\n Queue Empty");
    }
    else
    {
    	printf("%d popped", head->data);
    	temp = head;
    	head = head->next;
    	free(temp);
    	if(head == NULL)
    		tail = NULL;
    }
}

void display()  
{  
    int i;  
    temp=head;  
    if(temp == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {   
        printf("Stack elements: ");  
        while(temp!=NULL)  
        {  
            printf(" %d  ",temp->data);  
            temp = temp->next;  
        }  
    }  
}    

int main()
{
    int choice;
    int data;
    printf("Operations :-\n1: Push\n2: Pop\n3: Display\n4: Exit");  
        
    do
    {
        printf("\n____________________\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid Choice\n");
                break;
        };
    }while(choice != 4);
    return 0;
}
