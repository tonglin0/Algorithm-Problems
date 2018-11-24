#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<vector>
#include<string>
#include<queue>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
using namespace std;

int ch[2006][28];
int val[2006],next[2006],last[2006];
int a[209];
char st[205][35];
int tot;
string p[55][1005];
int f[105][2005];
int pre[105][2005][2];

void insert(char *s,int k)
{
  int u=0,len=strlen(s);
  for (int i=0;i<len;i++)
  {
  	int c=s[i]-'a';
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
  for (int c=0;c<26;c++)
    if (ch[0][c])
    {
      int u=ch[0][c];
      q.push(u);
      last[u]=next[u]=0;
	}
  while(!q.empty())
  {
    int r=q.front();q.pop();
    for (int i=0;i<26;i++)
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

void PRINT(int j,int &t)
{
  if (j)
  {
    t+=val[j];
    if (last[j])
	  PRINT(last[j],t);
  }
}

int main()
{
  freopen("2296.in","r",stdin);
  freopen("2296.out","w",stdout);
  int ca,n,i,j,k,m;
  scanf("%d",&ca);
  while(ca--)
  {
  	int l;
    scanf("%d%d",&l,&n);
    for (i=1;i<=n;i++)
    {
	  scanf("%s",st[i]);
	  int len=strlen(st[i]);
	}
	memset(ch[0],0,sizeof(ch[0]));
	memset(val,0,sizeof(val));
    tot=0;
	for (i=1;i<=n;i++)
      scanf("%d",&a[i]);
    for (i=1;i<=n;i++)
      insert(st[i],a[i]);
    acgetfail();
    memset(pre,0,sizeof(pre));
    for (i=0;i<=tot+1;i++)
      for (j=0;j<=l+1;j++)
	    f[j][i]=-INF;
	for (i=0;i<=tot+1;i++)
	  for (j=0;j<=l+1;j++)
	    p[j][i]="";
    f[0][0]=0;
    for (i=0;i<l;i++)
      for (j=0;j<=tot;j++)
        for (k=0;k<26;k++)
        {
          int t=0;
          PRINT(ch[j][k],t);
          if (f[i][j]+t>f[i+1][ch[j][k]])
          {
		    f[i+1][ch[j][k]]=f[i][j]+t;
		    p[i+1][ch[j][k]]=p[i][j]+(char)('a'+k);
		  }
		  else if (f[i][j]+t==f[i+1][ch[j][k]]&&p[i][j].length()+1<=p[i+1][ch[j][k]].length()&&(p[i][j]+(char)('a'+k)<p[i+1][ch[j][k]]))
		    p[i+1][ch[j][k]]=p[i][j]+(char)('a'+k);
        }
    int ans=-1;
    int ml=0;
    string anss="";
    for (i=0;i<=l;i++)
      for (j=0;j<=tot;j++)
        if (f[i][j]>ans||(f[i][j]==ans&&i<=ml&&p[i][j]<anss))
        {
          ans=f[i][j];
          anss=p[i][j];
          ml=anss.length();
		}
	printf("%s\n",anss.c_str());
  }
  return 0;
}

