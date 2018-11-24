#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

struct node{
	int v,w;
};
node s[13][103];
int f[13][10003];

int main()
{
  freopen("3033.in","r",stdin);
  freopen("3033.out","w",stdout);
  int n,i,j,k,m,c;
  while(scanf("%d%d%d",&n,&m,&c)==3)
  {
  	memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
    {
      int a,b;
      scanf("%d%d%d",&a,&b,&k);
      s[a][0].v++;
      s[a][s[a][0].v].v=b;
      s[a][s[a][0].v].w=k;
	}
	for (i=0;i<=c;i++)
	  for (j=0;j<=m;j++)
	    f[i][j]=-(int)1e9;
	//memset(f,-1,sizeof(f));
	f[0][0]=0;
	for (i=1;i<=c;i++)
	  for (k=1;k<=s[i][0].v;k++)
	    for (j=m;j>=s[i][k].v;j--)
	      f[i][j]=max(f[i][j],max(f[i-1][j-s[i][k].v]+s[i][k].w,f[i][j-s[i][k].v]+s[i][k].w));
	int ans=-1;
	for (i=0;i<=m;i++)
	  ans=max(ans,f[c][i]);
	if (ans==-1)
	  printf("Impossible\n");
	else
	  printf("%d\n",ans);
  }
  return 0;
}
