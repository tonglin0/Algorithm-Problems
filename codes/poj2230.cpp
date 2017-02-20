#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;

typedef pair<int,bool> pii;
vector<pii> g[10010];
stack<int> s;

void eular(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!g[u][i].second)
    {
      g[u][i].second=true;
      eular(g[u][i].first);
      s.push(g[u][i].first);
    }
}

int main()
{
  freopen("2230.in","r",stdin);
  freopen("2230.out","w",stdout);
  int n,i,j,m;
  scanf("%d%d",&n,&m);
  for (i=0;i<=10009;i++) g[i].clear();
  for (i=1;i<=m;i++)
  {
    int u,v;
    scanf("%d%d",&u,&v);
    pii x;
    x.first=v;
    x.second=false;
    g[u].push_back(x);
    x.first=u;
    g[v].push_back(x);
  }
  eular(1);
  printf("%d\n",1);
  while(!s.empty())
  {
    printf("%d\n",s.top());
    s.pop();
  }
  return 0;
}
