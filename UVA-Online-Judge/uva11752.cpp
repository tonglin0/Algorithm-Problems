#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define lint unsigned long long
using namespace std;

lint c[1000000];
bool vis[109];

int main()
{
  freopen("11752.out","w",stdout);
  lint p=0,n,i,j,k,m;
  lint s1=1<<16;
  memset(vis,0,sizeof(vis));
  for (i=2;i<=10;i++)
    if (!vis[i])
      for (j=i*i;j<=100;j+=i)
        vis[j]=true;
  for (i=2;i<s1;i++)
  {
    lint s;
    s=i*i*i*i;
    c[++p]=s;
    k=ceil(64*log(2)/log(i))-1;
    for (j=5;j<=k;j++)
    {
      s=s*i;
      if (vis[j])
        c[++p]=s;
	}
  }
  sort(c+1,c+p+1);
  printf("1\n");
  printf("%llu\n",c[1]);
  for (i=2;i<=p;i++)
    if (c[i]!=c[i-1])
      printf("%llu\n",c[i]);
  return 0;
}
