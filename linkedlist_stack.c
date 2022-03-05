#include <stdio.h>  
#include <stdlib.h>  
struct node   
{  
int data;  
struct node *next;  
};  
struct node *head; 
struct node *current;

void push ()  
{  
     
    current = (struct node*)malloc(sizeof(struct node));   
    if(current == NULL)  
    {  
        printf("Not able to push the element");   
    }  
    else   
    {   
        int x;
        printf("Enter the value:");  
        scanf("%d",&x);  
        if(head==NULL)  
        {         
            current->data = x;  
            current -> next = NULL;  
            head=current;  
        }   
        else   
        {  
            current->data = x;  
            current->next = head;  
            head=current;  
               
        }  
        printf("Item pushed");  
          
    }  
}   
void pop()  
{  
    int x;  
      
    if (head == NULL)  
    {  
        printf("Underflow");  
    }  
    else  
    {  
        x = head->data;  
        current = head;  
        head = head->next;  
        free(current);
        current=NULL;
        printf("%d popped",x);  
          
    }  
}  
  
void display()  
{  
    int i;  
    current=head;  
    if(current == NULL)  
    {  
        printf("Stack is empty\n");  
    }  
    else  
    {   
        printf("Stack elements: ");  
        while(current!=NULL)  
        {  
            printf(" %d  ",current->data);  
            current = current->next;  
        }  
    }  
}    

  
void main ()  
{  
    int choice=0;   
    printf("Stack operations:\n1.Push\n2.Pop\n3.Display\n4.Exit");
    while(choice != 4)  
    {  
        printf("\n_______________________");
        printf("\nEnter your choice: ");        
        scanf("%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            {   
                push();  
                break;  
            }  
            case 2:  
            {  
                pop();  
                break;  
            }  
            case 3:  
            {  
                display();  
                break;  
            }  
            case 4:   
            {  
                printf("Exiting....");  
                break;   
            }  
            default:  
            {  
                printf("Please Enter valid choice ");  
            }   
        }  
    };  
}  
