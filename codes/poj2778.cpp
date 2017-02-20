#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<algorithm>
#define MOD 100000
#define lint long long
using namespace std;

int ch[104][5];
int val[105];
int tot;
int next[105],last[105];
map<char,int> trs;

struct mat{
	int h,w;
	lint s[105][105];
	mat(){memset(s,0,sizeof(s));};
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

void insert(char *s,int k)
{
  int len=strlen(s),u=0;
  for (int i=0;i<len;i++)
  {
    int c=trs[s[i]];
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
  next[0]=last[0]=0;
  queue<int> q;
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

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=0;i<=a.h;i++)
    for (int j=0;j<=b.w;j++)
      for (int k=0;k<=a.w;k++)
        c.s[i][j]=(c.s[i][j]+a.s[i][k]*b.s[k][j])%MOD;
  return c;
}

mat mat_pow(mat a,int b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=0;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    b>>=1;
    t=cheng(t,t);
  }
  return ans;
}

void build_mat(mat &t)
{
  for (int i=0;i<=tot;i++)
  {
    for (int j=0;j<4;j++)
    {
      t.s[ch[i][j]][i]++;
	}
  }
  for (int i=0;i<=tot;i++)
    if (val[i]||val[last[i]])
    {
      for (int j=0;j<=tot;j++)
      {
        t.s[i][j]=0;
        t.s[j][i]=0;
	  }
	}
}

int main()
{
  freopen("2778.in","r",stdin);
  freopen("2778.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d%d",&n,&m);
  tot=0;
  trs['A']=0;trs['C']=1;trs['G']=2;trs['T']=3;
  memset(ch[0],0,sizeof(ch[0]));
  val[0]=0;
  for (i=1;i<=n;i++)
  {
    char s[12];
    scanf("%s",s);
    insert(s,i);
  }
  acgetfail();
  mat t(tot,tot);
  build_mat(t);
  t=mat_pow(t,m);
  int ans=0;
  for (i=0;i<=tot;i++)
    ans=(ans+t.s[i][0])%MOD;
  printf("%d\n",(ans+MOD)%MOD);
  return 0;
}
