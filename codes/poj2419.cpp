#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
using namespace std;

vector<int> g[104];
bool vis[104][104];
vector<int> anss[105];
int top;

bool equ(int x,int y)
{
  if (g[x].size()!=anss[y].size())
    return false;
  for (int i=0;i<g[x].size();i++)
    if (g[x][i]!=anss[y][i])
      return false;
  return true;
}

bool find(int x)
{
  for (int i=1;i<=top;i++)
    if (equ(x,i))
      return true;
  return false;
}

void insert(int x)
{
  top++;
  for (int i=0;i<g[x].size();i++)
    anss[top].push_back(g[x][i]);
}

int main()
{
  freopen("2419.in","r",stdin);
  freopen("2419.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d%d",&n,&m);
  int u,v;
  memset(vis,0,sizeof(vis));
  for (i=0;i<104;i++)
    g[i].clear();
  for(i=0;i<105;i++)
    anss[i].clear();
  while(scanf("%d%d",&u,&v)==2)
  {
    if (!vis[u][v])
	{
	  g[u].push_back(v);
	  vis[u][v]=true;  
    }
  }
  top=0;
  for (i=1;i<=n;i++)
    sort(g[i].begin(),g[i].end());
  int ans=0;
  for (i=1;i<=n;i++)
    if (!find(i))
    {
      insert(i);
      ans++;
	}
  printf("%d\n",ans);
  return 0;
}

