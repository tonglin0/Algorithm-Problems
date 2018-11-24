#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#define lint long long
#define llu unsigned long long
using namespace std;

int ch[35][28];
int val[35];
char st[100];
int tot;
int next[35],last[35];

struct mat{
	int h,w;
	llu s[70][70];
	mat(){}
	mat(int h,int w):h(h),w(w){memset(s,0,sizeof(s));}
};

mat cheng(mat a,mat b)
{
  mat c(a.h,b.w);
  for (int i=0;i<=a.h;i++)
    for (int j=0;j<=b.w;j++)
      for (int k=0;k<=a.w;k++)
        c.s[i][j]+=a.s[i][k]*b.s[k][j];
  return c;
}

mat mat_pow(mat a,lint b)
{
  mat t;t=a;
  mat ans(a.h,a.w);
  for (int i=0;i<=a.h;i++)
    ans.s[i][i]=1;
  while(b)
  {
    if (b&1)
      ans=cheng(ans,t);
    t=cheng(t,t);
    b>>=1;
  }
  return ans;
}

llu pow_mod(llu a,lint b)
{
  llu ans=1,t=a;
  while(b)
  {
    if (b&1)
      ans=ans*t;
    b>>=1;
    t=t*t;
  }
  return ans;
}

llu getnum(lint n)
{
  if (n==1)
    return 26;
  else if (n&1)
  {
    llu tmp=getnum(n/2);
	return tmp+pow_mod(26,n/2)*tmp+pow_mod(26,n);
  }
  else
  {
    llu tmp=getnum(n/2);
    return tmp+pow_mod(26,n/2)*tmp;
  }
}

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
  queue<int> q;
  last[0]=next[0]=0;
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
    for (int c=0;c<26;c++)
    {
      int u=ch[r][c];
      if (!u)
      {
        ch[r][c]=ch[next[r]][c];
        continue;
	  }
	  q.push(u);
	  int v=next[r];
	  next[u]=ch[v][c];
	  last[u]=val[next[u]]?next[u]:last[next[u]];
	}
  }
}

int main()
{
  freopen("2243.in","r",stdin);
  freopen("2243.out","w",stdout);
  int n,i,j,k;
  lint m;
  while(scanf("%d%I64d",&n,&m)==2)
  {
    val[0]=0;
	memset(ch[0],0,sizeof(ch[0]));
    tot=0;
    for (i=1;i<=n;i++)
    {
      scanf("%s",st);
      insert(st,i);
	}
	acgetfail();
	llu sum=getnum(m);
	mat t((tot<<1)+1,(tot<<1)+1);
	for (i=0;i<=tot;i++)
	  for (j=0;j<26;j++)
	    t.s[ch[i][j]][i]++;
	for (i=0;i<=tot;i++)
	  if (val[i]||val[last[i]])
	    for (j=0;j<=tot;j++)
	      t.s[i][j]=t.s[j][i]=0;
	for (i=0;i<=tot;i++)
	  t.s[i][i+tot+1]=1;
	for (i=tot+1;i<=tot+tot+1;i++)
	  t.s[i][i]=1;
	t=mat_pow(t,m+1);
	llu ans=0;
	for (i=0;i<=tot;i++)
	  ans+=t.s[i][tot+1];
	ans--;
	ans=sum-ans;
	printf("%I64u\n",ans);
  }
  return 0;
}
