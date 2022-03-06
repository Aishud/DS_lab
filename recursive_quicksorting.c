#include<stdio.h>

int swap(int *p, int *q)
{   int t ;
    t = *p;
    *p = * q;
    *q= t ;
}

int part(int a[],int l, int r)
{
    int key = a[l];
    int i =(l+1);
    int j = r ;
    do
    {
        while(a[i]<key && (i<j))
            i++;
        while(a[j]>key && (j>l)) 
            j--;
        if(i<j)
            swap(&a[i],&a[j]);
    }while(i<j);
    swap(&a[l],&a[j]);
    return (j);
}

void quicksort(int a[], int l, int r)
{
    if(l<r)
    {
        int pos = part(a, l, r);
        quicksort(a,l,(pos-1));
        quicksort(a,(pos+1),r);
    }
}

    
void main()
{
    int n , i , a[10];
    printf("Enter total no: of elemnts :");
    scanf("%d",&n);
    printf("Enter the elements to be sorted :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    quicksort(a,0,(n-1));
    printf("Sorted array is :");
    for(i=0;i<n;i++){
        printf("  %d  ",a[i]);
        if(i!=n-1)
            printf(",");
    }
}
