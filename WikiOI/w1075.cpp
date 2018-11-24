#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[103];
bool v[1003];
int main()
{
  int n,i,j,s;
  memset(v,0,sizeof(v));
  memset(a,0,sizeof(a));
  scanf("%d",&n);
  for (i=1;i<=n;i++)
  {
    scanf("%d",&s);
    v[s]=true;
  }
  s=0;
  for (i=1;i<=1000;i++)
    if (v[i]) a[++s]=i;
  sort(a+1,a+s+1);
  printf("%d\n",s);
  for (i=1;i<=s;i++)
    printf("%d ",a[i]);
  //system("pause");
  return 0;
} 
