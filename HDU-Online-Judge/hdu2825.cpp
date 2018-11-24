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
#define MOD 20090717
using namespace std;

int f[27][104][1028];
int ch[105][28];
int val[105];
int next[105],last[105];
int tot;
int pre[1045];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=s[i]-'a';
    if (!ch[u][c])
    {
      ch[u][c]=++tot;
      val[tot]=0;
      memset(ch[tot],0,sizeof(ch[tot]));
	}
	u=ch[u][c];
  }
  val[u]=k;
}

void acgetfail()
{
  next[0]=last[0]=0;
  queue<int> q;
  for (int i=0;i<26;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      next[u]=last[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int c=0;c<26;c++)
    {
      if (!ch[r][c])
      {
        ch[r][c]=ch[next[r]][c];
        continue;
	  }
	  int u=ch[r][c];
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][c];
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

void PRINT(int j,int &t)
{
  if (j)
  {
    t|=(1<<(val[j]-1));
    PRINT(last[j],t);
  }
}

int main()
{
  freopen("2825.in","r",stdin);
  freopen("2825.out","w",stdout);
  int n,i,j,k,m;
  pre[0]=0;
  for (i=1;i<=(1<<10);i++)
    pre[i]=pre[i>>1]+(i&1);
  while(scanf("%d%d%d",&n,&m,&k)==3&&(n+m+k))
  {
    for (i=0;i<=n;i++)
      for (j=0;j<=101;j++)
        for (int ii=0;ii<=(1<<m);ii++)
          f[i][j][ii]=0;
    memset(ch[0],0,sizeof(ch[0]));
    memset(val,0,sizeof(val));
    tot=0;
    for (i=1;i<=m;i++)
    {
      char st[14];
      scanf("%s",st);
      insert(st,i);
	}
    acgetfail();
    f[0][0][0]=1;
    int full=(1<<m)-1;
    for (i=0;i<n;i++)
      for (j=0;j<=tot;j++)
        for (int ii=0;ii<=full;ii++)
          if (f[i][j][ii])
            for (int c=0;c<26;c++)
            {
              int tmp=0;
              if (val[ch[j][c]])
                PRINT(ch[j][c],tmp);
              else
                PRINT(last[ch[j][c]],tmp);
              f[i+1][ch[j][c]][ii|tmp]=(f[i+1][ch[j][c]][ii|tmp]+f[i][j][ii])%MOD;
			}
	int ans=0;
	for (i=0;i<=full;i++)
	  if (pre[i]>=k)
	    for (j=0;j<=tot;j++)
	      ans=(ans+f[n][j][i])%MOD;
	printf("%d\n",ans);
  }
  return 0;
}

