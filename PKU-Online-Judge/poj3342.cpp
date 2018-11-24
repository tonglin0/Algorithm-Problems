#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

char st[201][101];
int top;
vector<int> g[201];
bool vis[201][2],uni[201][2];
int f[201][2];

int find(int u,int sig)
{
  if (vis[u][sig])
    return f[u][sig];
  vis[u][sig]=true;
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (sig==1)
    {
      f[u][sig]+=find(v,0);
      if (!uni[v][0])
        uni[u][sig]=false;
	}
	else
	{
	  if (find(v,0)>find(v,1))
	  {
	    f[u][sig]+=f[v][0];
	    if (!uni[v][0])
	      uni[u][sig]=false;
	  }
	  else if (f[v][0]<f[v][1])
	  {
	    f[u][sig]+=f[v][1];
	    if (!uni[v][1])
	      uni[u][sig]=false;
	  }
	  else if (f[v][0]==f[v][1])
	  {
	    f[u][sig]+=f[v][0];
	    uni[u][sig]=false;
	  }
	}
  }
  if (sig==1)
    f[u][sig]++;
  return f[u][sig];
}

int get_id(char *s)
{
  for (int i=1;i<=top;i++)
    if (strcmp(st[i],s)==0)
      return i;
  strcpy(st[++top],s);
  return top;
}

int main()
{
  freopen("3342.in","r",stdin);
  freopen("3342.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1&&n)
  {
  	for (i=0;i<=n;i++)
  	  g[i].clear();
    scanf("%s",st[1]);
    top=1;
    for (i=1;i<=n-1;i++)
    {
      char s1[104],s2[104];
      scanf("%s%s",s1,s2);
      int u=get_id(s1);
      int v=get_id(s2);
      g[v].push_back(u);
	}
	memset(f,0,sizeof(f));
	memset(vis,0,sizeof(vis));
	memset(uni,true,sizeof(uni));
	if (find(1,0)>find(1,1))
	{
	  printf("%d ",find(1,0));
	  if (uni[1][0])
	    printf("Yes\n");
	  else
	    printf("No\n");
	}
	else if (find(1,0)==find(1,1))
	{
	  printf("%d No\n",find(1,0));
	}
	else
	{
	  printf("%d ",find(1,1));
	  if (uni[1][1])
	    printf("Yes\n");
	  else
	    printf("No\n");
	}
  }
  return 0;
}
