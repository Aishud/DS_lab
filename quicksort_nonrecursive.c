#include <stdio.h>
  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
  
int partition(int arr[], int l, int r)
{
    int x = arr[r];
    int i = (l - 1);
  
    for (int j = l; j <=r - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[r]);
    return (i + 1);
}
  
void quickSortIterative(int arr[], int l, int r)
{
    // Create an auxiliary stack
    int stack[r - l + 1];
    int top = -1;
  
    // push initial values of l and r to stack
    stack[++top] = l;
    stack[++top] = r;
  
    while (top >= 0) {
        r = stack[top--];
        l = stack[top--];
  
        int p = partition(arr, l, r);
  
        if (p - 1 > l) {
            stack[++top] = l;
            stack[++top] = p - 1;
        }
  
        if (p + 1 < r) {
            stack[++top] = p + 1;
            stack[++top] = r;
        }
    }
}
  

int main()
{
    int a[50], n , i ;
    printf("Enter the total no of elements:  ");
    scanf("%d",&n);
    printf("Enter the elements : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }      
    quickSortIterative(a, 0, n - 1);
    printf("The sorted array is :  ");
    for(i=0;i<n;i++){
        printf("%d",a[i]);
        if(i!=n-1)
            printf(" , ");
    }
    return 0;
}
