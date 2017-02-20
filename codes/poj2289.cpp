#include<cstdlib>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int p[504][1004];
bool vis[1004];
int mid,n;
vector<int> g[1004];

bool find(int u)
{
  for (int i=0;i<g[u].size();i++)
  {
    int v=g[u][i];
    if (!vis[v])
    {
      vis[v]=true;
      if (p[v][0]<mid)
      {
        p[v][++p[v][0]]=u;
        return true;                
      }
      else
        for (int j=1;j<=mid;j++)
          if (find(p[v][j]))
          {
            p[v][j]=u;
            return true;
          }
    }
  }
  return false;
}

bool match()
{
  for (int i=1;i<=n;i++)
  {
    memset(vis,0,sizeof(vis));
    if (!find(i))
      return false;
  }
  return true;
}

int main()
{
  int i,k,j,m;
  //freopen("2289.in","r",stdin);
  //freopen("2289.out","w",stdout);
  scanf("%d%d",&n,&m);
  while(!(n==0&&m==0))
  {
    for (i=0;i<1004;i++) g[i].clear();
    char s[100];
    for (i=1;i<=n;i++)
    {
      scanf("%s",s);
      char ch=' ';
      while(ch==' '||isdigit(ch))
      {
        while (ch==' ') ch=getchar();
        if (!isdigit(ch)) break;
        int d=0;
        //d=ch-'0';
        while(isdigit(ch))
        {
          d=d*10+ch-'0';
          ch=getchar();
        }
        g[i].push_back(d);
      }
    }
    int l=1,r=n;
    while(l<r)
    {
      memset(p,0,sizeof(p));
      mid=l+((r-l)>>1);
      if (match())
        r=mid;
      else
        l=mid+1;
    }
    printf("%d\n",l);
    scanf("%d%d",&n,&m);
  }
}
