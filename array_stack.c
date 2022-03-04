#include<stdio.h>
int stack[50],choice,n,top,x,i;

void push()
{
    if(top>=n-1)
    {
        printf("STACK is over flow");
        
    }
    else
    {
        printf("Enter a value to be pushed:");
        scanf("%d",&x);
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if(top<=-1)
    {
        printf("Stack is under flow");
    }
    else
    {
        printf("The popped element is %d",stack[top]);
        top--;
    }
}

void display()
{
    if(top>=0)
    {
        printf("\nThe elements in STACK are:");
        for(i=top; i>=0; i--)
            printf("\t%d",stack[i]);
        printf("\nEnter Next Choice");
    }
    else
    {
        printf("The STACK is empty");
    }  
}
int main()
{
    //clrscr();
    top=-1;
    printf("Enter the size of STACK : ");
    scanf("%d",&n);
    printf("Stack Operations using array are:-\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    do
    {
        printf("\nEnter the choice:");
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
                printf(" EXIT POINT ");
                break;
            }
            default:
            {
                printf ("Please Enter a Valid Choice");
            }                
        }
    }
    while(choice!=4);
    return 0;
}
