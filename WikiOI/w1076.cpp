#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define mn 100003
int a[mn];

void qs(int h,int t)
{
  int i=h,j=t,tt,x;
  tt=rand()%(t-h)+h;
  x=a[tt];
  a[tt]=a[h];
  a[h]=x;
  while(i<j)
  {
    while(i<j&&a[j]>=x)
      j--;
     a[i]=a[j];
    while(i<j&&a[i]<=x)
      i++;
     a[j]=a[i];          
  } 
  a[i]=x;
  if (i-1>h) qs(h,i-1);
  if (j+1<t) qs(j+1,t);
}
int main()
{
    memset(a,0,sizeof(a));
    int n,i,j;
    scanf("%d\n",&n);
    for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    srand(time(NULL));
    qs(1,n);
    for (i=1;i<=n-1;i++)
      printf("%d ",a[i]);
    printf("%d\n",a[n]);
    //system("pause");
    return 0;
}
