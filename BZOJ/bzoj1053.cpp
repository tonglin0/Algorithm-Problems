#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#define lint long long
#define INF (int)1e9
using namespace std;

bool vis[55];
int p[20];
int c=0;
lint ans;
lint anscnt;
lint n;

void dfs(int k,lint cnt,lint s,int limit)
{
  if (cnt>anscnt)
  {
    ans=s;
    anscnt=cnt;
  }
  else if (cnt==anscnt&&s<ans)
    ans=s;
  lint tmps=s;
  for (int i=1;i<=limit;i++)
  {
    tmps=tmps*p[k];
    if (tmps>n)
      return ;
    dfs(k+1,cnt*(i+1),tmps,i);
  }
}

int main()
{
  freopen("1053.in","r",stdin);
  freopen("1053.out","w",stdout);
  int ca,m,i,j,k;
  cin>>n;
  memset(vis,0,sizeof(vis));
  for (i=2;i<=37;i++)
    if (!vis[i])
    {
      p[++c]=i;
      for (j=i*i;j<=37;j+=i)
        vis[j]=true;
	}
  ans=-INF;anscnt=-1;
  dfs(1,1,1,32);
  cout<<ans<<endl;
  return 0;
}

