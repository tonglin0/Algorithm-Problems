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
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
using namespace std;

int ch[1005][5];
char st[1005];
int f[1005][1005];
int val[1005];
int tot;
map<char,int> tras;
int next[1005],last[1005];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
    int c=tras[s[i]];
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
  queue<int> q;
  last[0]=next[0]=0;
  for (int i=0;i<4;i++)
    if (ch[0][i])
    {
      int u=ch[0][i];
      q.push(u);
      last[u]=next[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<4;i++)
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

int main()
{
  freopen("2457.in","r",stdin);
  freopen("2457.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  tras['A']=0;tras['C']=1;tras['G']=2;tras['T']=3;
  while(scanf("%d",&n)==1)
  {
    if (n==0)
      break;
    tot=0;
    printf("Case %d: ",++ii);
    memset(ch[0],0,sizeof(ch[0]));
    memset(val,0,sizeof(val));
    for (i=1;i<=n;i++)
    {
      scanf("%s",st);
      insert(st,i);
	}
	scanf("%s",st);
	int len=strlen(st);
	for (i=0;i<=len+1;i++)
	  for (j=0;j<=tot+1;j++)
	    f[i][j]=INF;
    f[0][0]=0;
	acgetfail();
	for (i=0;i<len;i++)
	  for (j=0;j<=tot;j++)
	    for (k=0;k<4;k++)
	      if ((!val[ch[j][k]])&&(!last[ch[j][k]]))
	        if (tras[st[i]]==k)
	          f[i+1][ch[j][k]]=min(f[i+1][ch[j][k]],f[i][j]);
	        else
	          f[i+1][ch[j][k]]=min(f[i+1][ch[j][k]],f[i][j]+1);
	int ans=INF;
	for (i=0;i<=tot;i++)
	  if (f[len][i]<ans)
	    ans=f[len][i];
	if (ans==INF)
	  printf("-1\n");
	else
	  printf("%d\n",ans);
  }
  return 0;
}

