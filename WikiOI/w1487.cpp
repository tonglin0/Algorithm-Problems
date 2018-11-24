#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int a[12];
int main()
{
  memset(a,0,sizeof(a));
  int n,i;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    int j;
    scanf("%d",&j);
    a[j]++;
  }
  int j;
  for (i=1;i<=10;i++)
    for (j=1;j<=a[i];j++)
      printf("%d\n",i);
  //system("pause");
  return 0;
} 
