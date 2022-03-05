#include <stdio.h>
#include <stdlib.h>
int s[50],top[50],min[50],max[50];
//min = lower bound for a stack and max = upper bound for a stack
//ns is stack number
//size is size of the stack
int ns,size;
//function to initialize starting values of top,min,max and stack
void init(void)
{ 
 int i;
 for(i=0;i<50;++i)
 { 
 s[i]=min[i]=max[i] = 0;
 top[i]=-1;
 }
}
//function to create the stack 
void createstack()
{ 
 int i ;
 min[0]= -1;
 max[0] = size -1;
 top[0]=-1;
 //min and top of 1,2,3,….th stacks 
 for(i=1;i<ns;++i)
 {
  min[i]= min[i-1] + size;
  top[i] = min [i];
 }
 //max of 1,2,3,….th stacks will me min of 2,3,4,….th stack
 for(i=1;i<ns;++i)
 {
  max[i]= min[i+1]; 
 }
}
//function to push element to stack
void push(int ele,int k)
{
 //check for stack overflow
 if(top[k-1]==max[k-1])
 {
  printf("Stack no %d is full i.e overflow\n",k);
  return;
 }
 ++top[k-1];
 s[top[k-1]] = ele;
}
//function to pop an element form stack
void pop(int k)
{ 
 //check for underflow 
 if(top[k-1]==min[k-1])
 { 
  printf("\nStack no %d is empty i.e underflow\n",k);
  return;
 }
 printf("%d from stack %d is deleted\n",s[top[k-1]],k);
 --top[k-1]; 
}
//function to display any stack
void display(int k)
{ 
 int j;
 if(top[k-1]==min[k-1])
 { 
  printf("\nStack no %d is empty\n",k);
  return;
 }
 printf("\nStack %d : ",k);
 
 for(j=min[k-1]+1;j<=top[k-1];++j)
 { 
  printf("%d",s[j] );
 }
 printf("\n");
} 

int main() {
 int ele,ch,skn;
 init();
 printf("\nEnter the number of Stacks: ");
 scanf("%d",&ns); 
 size = 50/ns;
 
 createstack();
 
 printf("Operation are:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
 do{
 printf("_______________________\n");
 printf("\nEnter your choice : ");
 scanf("%d",&ch);
 
 switch(ch)
 { 
  case 1: printf("Enter the stack no : ");
   scanf("%d",&skn);
   printf("Enter the element : ");
   scanf("%d",&ele);
   push(ele,skn);
   break;
 
  case 2 : printf("Enter the stack no to pop : ");
   scanf("%d",&skn);
   pop(skn);
   break;
 
  case 3: printf("Enter the stack no to display : ");
   scanf("%d",&skn);
   display(skn);
   break;
 
  case 4 : printf("Program Terminating");
   break;
 
  default : printf("\nInvalid Option\n");
 }
 } while(ch!=4); 
 return 0;
}
