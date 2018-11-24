#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

const int p[]={1,2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

LL ans,m,n;

void dfs(LL s,LL t,int k,int limit)
{
  if (t>m)
  {
    m=t;
    ans=s;
  }
  if (t==m&&s<ans)
    ans=s;
  LL temp=s;
  for (int i=1;i<=limit;i++)
  {
    temp*=p[k];
    if (temp>n) return ;
    dfs(temp,t*(i+1),k+1,i);
  }
}

int main()
{
  freopen("2562.in","r",stdin);
  freopen("2562.out","w",stdout);
  while(scanf("%lld",&n)==1)
  {
    ans=n;
    m=0;
    dfs(1,1,1,50);
    printf("%lld\n",ans);
  }
  return 0;
}
