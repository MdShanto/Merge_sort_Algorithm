#include <stdio.h>
#include <time.h>//new header file for count time
#include <stdlib.h>

int b[60000];//globally declared array

void combine(int a[],int low,int mid,int high)
{
  int i,j,k;
  i=low;   //array a[]
  j=mid+1;//array a[]
  k=low; //array b[]
  while(i<=mid&&j<=high)//first while condition
  {
      if(a[i]<=a[j])
      {
          b[k++]=a[i++];
      }                      //"loop will continue when the first while condition is true".
      else
      {
          b[k++]=a[j++];
      }
  }
  while(i<=mid)//if first while condition is false
  {
      b[k++]=a[i++];
  }
  while(j<=high)//if second while condition is false
  {
      b[k++]=a[j++];
  }
  for(k=low;k<=high;k++)
  {
      a[k]=b[k];
  }
}


void divide(int a[],int low,int high)
{
    int mid;
    if(low>=high)
    {
        return;
    }
    mid=(low+high)/2;
    divide(a,low,mid);
    divide(a,mid+1,high);
    combine(a,low,mid,high);
}


int main()
{
    int i,a[60000],n;
    clock_t st,et;
    double ts;
    printf("please enter the number of digit you want to merge sort:\n");
    scanf("%d",&n);
    printf("\n");
    printf("unsorted array are:\n");
    for(i=1;i<=n;i++)
    {
        a[i]=rand();
        printf("%d\t",a[i]);//taking array index value randomly by machine
    }
    st=clock();
    divide(a,1,n);//calling function
    et=clock();
    ts=(double)(et-st)/CLOCKS_PER_SEC;//measuring total time
    printf("\n\nsorted array:\n\n");
    for(i=1;i<=n;i++)
    {
       printf("%d\t",a[i]);//printing new sorted array
    }
    printf("\nThe total time need to merge the array: %lf\n",ts);
    return 0;
}
