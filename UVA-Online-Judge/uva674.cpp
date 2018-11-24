#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int f[7500];
int v[]={0,1,5,10,25,50};

int main()
{
  freopen("674.in","r",stdin);
  freopen("674.out","w",stdout);
  int n,i,j,k,m;
  memset(f,0,sizeof(f));
  f[0]=1;
  for (i=1;i<=5;i++)
    for (j=v[i];j<=7489;j++)
      f[j]+=f[j-v[i]];
  while(scanf("%d",&n)==1)
    printf("%d\n",f[n]);
  return 0;
}
