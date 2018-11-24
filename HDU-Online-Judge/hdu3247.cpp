#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
using namespace std;

struct node{
	int v,w;
};
vector<node> g[60050];
int tot;
int ch[60009][3];
int val[650009];
char ss[12][1004];
char st[50009];
int pos[13];
int last[60009],next[60009];
bool vis[60009];
int map[13][13];
int dis[60009];
int n;
int f[14][1050];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'0';
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      memset(ch[tot],0,sizeof(ch[tot]));
      val[tot]=0;
	}
	u=ch[u][c];
  }
  val[u]=k;
  if (k>0)
    pos[k-1]=u;
}

void acgetfail()
{
  queue<int> q;
  last[0]=next[0]=0;
  node t;
  for (int i=0;i<2;i++)
    if (ch[0][i])
	{
      int u=ch[0][i];
      q.push(u);
      t.v=u;t.w=1;
	  //if (t.v!=0)
	    g[0].push_back(t);
      last[u]=next[u]=0;
    }
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<2;i++)
    {
      int u=ch[r][i];
      if (!u)
      {
        ch[r][i]=ch[next[r]][i];
        t.v=ch[r][i];
        t.w=1;
        //if (t.v!=0)
		  g[r].push_back(t);
		continue;
	  }
	  t.v=u;t.w=1;
	  q.push(u);
	  g[r].push_back(t);
	  int v=next[r];
	  next[u]=ch[v][i];
	  //t.v=next[u];t.w=0;
	  //if (t.v!=0)
	    //g[u].push_back(t);
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

bool check(int j)
{
  if (val[j]<0)
    return false;
  if (last[j])
    return check(last[j]);
  else
    return true;
}

void bfs(int x)
{
  memset(vis,0,sizeof(vis));
  for (int i=0;i<=tot;i++)
    dis[i]=INF;
  dis[pos[x]]=0;
  vis[pos[x]]=true;
  queue<int> q;
  q.push(pos[x]);
  while(!q.empty())
  {
    int u=q.front();q.pop();
    for (int i=0;i<g[u].size();i++)
    {
      int v=g[u][i].v;
      if ((!vis[v])&&check(v))
      {
        vis[v]=true;
        dis[v]=dis[u]+g[u][i].w;
        q.push(v);
	  }
	}
  }
  for (int i=0;i<n;i++)
    map[x][i]=dis[pos[i]];
}

int main()
{
  freopen("3247.in","r",stdin);
  freopen("3247.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  while(scanf("%d%d",&n,&m)==2)
  {
    if (n+m==0)
      break;
    for (i=0;i<60050;i++)
      g[i].clear();
    memset(ch[0],0,sizeof(ch[0]));
    val[0]=0;
    tot=0;
    for (i=1;i<=n;i++)
    {
      scanf("%s",ss[i]);
      insert(ss[i],i);
	}
	for (i=1;i<=m;i++)
	{
	  scanf("%s",st);
	  insert(st,-1);
	}
	acgetfail();
	for (i=0;i<n;i++)
	  bfs(i);
	int full=(1<<n)-1;
	for (i=0;i<=n;i++)
	  for (j=0;j<=full;j++)
	    f[i][j]=INF;
	for (i=0;i<n;i++)
	  f[i][1<<i]=strlen(ss[i+1]);
	for (int s=1;s<=full;s++)
	  for (i=0;i<n;i++)
	    if (((1<<i)&s)&&f[i][s]<INF)
	      for (j=0;j<n;j++)
	        if ((!(s&(1<<j)))&&map[i][j]!=INF)
	          f[j][s|(1<<j)]=min(f[j][s|(1<<j)],f[i][s]+map[i][j]);
	int ans=INF;
	for (i=0;i<n;i++)
	  ans=min(ans,f[i][full]);
	printf("%d\n",ans);
  }
  return 0;
}

