#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap(int *a, int *b)
{
    int c;
    c=*a;
    *a=*b;
    *b=c;
}
int pivotlist(int *a, int l, int r,int *comp,int *inv)
{
    int i, point;
    point=l;
    for (i=l+1;i<=r;i++)
    {
        if (a[i]<a[l])
        {
            point++;
            swap(&a[point],&a[i]);
            if(point != i)
            {
                (*inv)++;
            }
        }
        (*comp)++;
    }
    swap(&a[l],&a[point]);
    if(l != point)
    {
        (*inv)++;
    }
    return point;
}
void quicksort(int *a, int l, int r, int *comp, int *inv)
{
    int point;
    if(l<r)
    {
        point=pivotlist(a,l,r,&*comp,&*inv);
        quicksort(a,l,point-1,&*comp,&*inv);
        quicksort(a,point+1,r,&*comp,&*inv);
    }
}
int main()
{
    int n, *a, i, comp, inv;
    comp=0;
    inv=0;
    scanf("%d", &n);
    a=(int*) malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
       scanf("%d", &*(a+i));
    }
    quicksort(a,0,n-1,&comp,&inv);
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("число сравнений=%d число перестановок=%d", comp, inv);
    return 0;
}
