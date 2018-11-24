#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;

bool vis[5003];
int c[5003];
int ne[5004];
int pr[5004];

int main()
{
  freopen("10780.in","r",stdin);
  freopen("10780.out","w",stdout);
  int T,n,i,j,k,m,ii;
  scanf("%d",&T);
  memset(vis,0,sizeof(vis));
  int p=0;
  for (i=2;i<=5000;i++)
    if (!vis[i])
    {
      c[++p]=i;
      for (j=i*i;j<=5000;j+=i)
        vis[j]=true;
	}
  for (ii=1;ii<=T;ii++)
  {
    printf("Case %d:\n",ii);
    memset(ne,0,sizeof(ne));
	memset(pr,0,sizeof(pr));
	scanf("%d%d",&m,&n);
    int ans=(int)1e9;
    for (i=1;i<=p;i++)
    {
      while(m%c[i]==0)
      {
        ne[i]++;
        m/=c[i];
	  }
    } 
	for (i=1;i<=p;i++)
	{
	  int tmp=n;
	  while(tmp)
	  {
	    pr[i]+=tmp/c[i];
	    tmp/=c[i];
	  }
	  if (ne[i]!=0)
	    ans=min(ans,pr[i]/ne[i]);
	}
	if (ans==0)
	  printf("Impossible to divide\n");
	else
	  printf("%d\n",ans);
  }
  return 0;
}
