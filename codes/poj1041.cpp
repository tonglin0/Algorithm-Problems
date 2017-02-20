#include<stack>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{int v,no;};
vector<edge> g[50];
bool vis[2000];
int d[50];
edge ar[3000];
stack<int> ss;

void eular(int u)
{
  for (int i=0;i<g[u].size();i++)
    if (!vis[g[u][i].no])
    {
      vis[g[u][i].no]=true;
      //ss.push(g[u][i].no);
      //intf("%d ",g[u][i].no);
      eular(g[u][i].v);
      ss.push(g[u][i].no);
      //printf("%d ",g[u][i].no);
    }/*
  while(!ss.empty())
  {
    printf("%d ",ss.top());
    ss.pop();
  }*/
}

bool cmp(edge a,edge b)
{
  return a.no<b.no;
}

int main()
{
  //freopen("1041.in","r",stdin);
  //freopen("1041.out","w",stdout);
  int n,m,i,j;
  scanf("%d%d",&n,&m);
  for(;;)
  {
    memset(d,0,sizeof(d));
    for (i=0;i<50;i++) g[i].clear();
    int s=min(n,m);
    //int st=0;
    //scanf("%d%d",&n,&m);
    while(!(n==0&&m==0))
    {
      int k;
      scanf("%d",&k);
      edge x;
      //if(!st) st=k;
      x.v=m;
      x.no=k;
      g[n].push_back(x);
      d[n]++;
      x.v=n;
      g[m].push_back(x);
      d[m]++;
      scanf("%d%d",&n,&m);
    }
    //memset(d,0,sizeof(d));
    int k=0;
    memset(vis,0,sizeof(vis));
    for (i=1;i<=44;i++) if (d[i]&1==1) {k=1;break;}
    if (k)
      printf("Round trip does not exist.");
    else
    {
      //vis[st]=true;
      for (i=1;i<=44;i++)
      {

        memset(ar,0,sizeof(ar));
        for (j=0;j<g[i].size();j++)
          {ar[j].v=g[i][j].v;ar[j].no=g[i][j].no;}
        j=g[i].size();
        sort(ar,ar+j,cmp);
        for (j=0;j<g[i].size();j++)
          {g[i][j].v=ar[j].v;g[i][j].no=ar[j].no;}
      }
      eular(s);
      while(!ss.empty())
      {
        printf("%d ",ss.top());
        ss.pop();
      }
    }
    printf("\n");
    scanf("%d%d",&n,&m);
    if (n==0&&m==0) break;
  }
  return 0;
}
