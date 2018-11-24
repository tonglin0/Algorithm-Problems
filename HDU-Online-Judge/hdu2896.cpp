#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int ch[100005][131];
int val[100005];
int next[100005],last[100005];
int tot;
bool vis[509];
vector<int> anss;

char st[205];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i];
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
	  memset(ch[tot],0,sizeof(ch[tot]));
	  val[tot]=0;
	}
	u=ch[u][c];
  }
  val[u]=k;
}

void acgetfail()
{
  last[0]=next[0]=0;
  queue<int> q;
  for (int i=0;i<129;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      last[u]=next[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<129;i++)
    {
      int u=ch[r][i];
      if (!u)
      {
        ch[r][i]=ch[next[r]][i];
        continue;
	  }
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][i];
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

void PRINT(int j)
{
  if (j)
  {
    vis[val[j]]=true;
    PRINT(last[j]);
  }
}

void acfind(char *s)
{
  int j=0;
  int len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i];
    j=ch[j][c];
    if (val[j])
      PRINT(j);
    else PRINT(last[j]);
  }
}

int main()
{
  freopen("2896.in","r",stdin);
  freopen("2896.out","w",stdout);
  int n,i,j,k,m;
  while(scanf("%d",&n)==1)
  {
    gets(st);
    memset(ch[0],0,sizeof(ch[0]));
    tot=0;
    val[0]=0;
    for (i=1;i<=n;i++)
    {
      gets(st);
      insert(st,i);
    }
    acgetfail();
    int sum=0;
    scanf("%d",&m);
    gets(st);
    for (i=1;i<=m;i++)
    {
      gets(st);
      memset(vis,0,sizeof(vis));
      anss.clear();
      acfind(st);
      for (j=1;j<=n;j++)
        if (vis[j])
          anss.push_back(j);
      if (anss.size()>0)
      {
        sum++;
        printf("web %d:",i);
        for (j=0;j<anss.size();j++)
          printf(" %d",anss[j]);
        printf("\n");
	  }
	}
	printf("total: %d\n",sum);
  }
  return 0;
}
