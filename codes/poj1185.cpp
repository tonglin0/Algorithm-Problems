#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int st[62];
int pre[105];
int num[64];
char ch[14];
int dp[103][63][63];

bool ok(int x)
{
  if (x&(x<<1)) return false;
  if (x&(x<<2)) return false;
  return true;
}

bool fit(int s,int i)
{
  if (s&pre[i])
    return false;
  return true;
}

int get_num(int x)
{
  int s=0;
  while(x)
  {
    if (x&1)
      s++;
    x>>=1;
  }
  return s;
}

int main()
{
  freopen("1185.in","r",stdin);
  freopen("1185.out","w",stdout);
  int n,i,j,k,m;
  int top=0;
  scanf("%d%d",&n,&m);
  for (i=0;i<(1<<m);i++)
    if (ok(i))
      st[++top]=i;
  memset(num,0,sizeof(num));
  for (i=1;i<=top;i++)
    num[i]=get_num(st[i]);
  for (i=1;i<=n;i++)
  {
    scanf("%s",(ch+1));
    pre[i]=0;
    for (j=1;j<=m;j++)
      if (ch[j]=='H')
        pre[i]|=(1<<(m-j));
  }
  memset(dp,0,sizeof(dp));
  for (i=1;i<=top;i++)
    if (fit(st[i],1))
      dp[1][i][1]=num[i];
  for (i=2;i<=n;i++)
    for (j=1;j<=top;j++)
      if (fit(st[j],i))
        for (k=1;k<=top;k++)
          if (fit(st[k],i-1)&&(!(st[k]&st[j])))
            for (int ii=1;ii<=top;ii++)
              if (!(st[j]&st[ii]))
                dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][ii]+num[j]);
  int ans=0;
  for (i=1;i<=top;i++)
    for (j=1;j<=top;j++)
      if (dp[n][i][j]>ans)
        ans=dp[n][i][j];
  printf("%d\n",ans);
  return 0;
}
