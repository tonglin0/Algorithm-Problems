#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<map>
#include<cctype>
#include<vector>
#include<queue>
#define lint long long
#define INF (int)1e9
#define eps 1e-8
#define MN 16000005
using namespace std;

char st[MN];
bool vis[MN];
int trs[1000];

int main()
{
  freopen("1200.in","r",stdin);
  freopen("1200.out","w",stdout);
  int n,i,j,k,m,ca,ii=0,nc;
  scanf("%d%d",&n,&nc);
  scanf("%s",st);
  int cnt=0;
  memset(vis,0,sizeof(vis));
  memset(trs,-1,sizeof(trs));
  for (i=0;st[i]!='\0';i++)
    if (trs[st[i]]==-1)
      trs[st[i]]=cnt++;
  int ans=0;
  int len=strlen(st);
  for (i=0;i<=len-n;i++)
  {
    int tmp=0;
    for (j=0;j<n;j++)
      tmp=tmp*nc+trs[st[i+j]];    // 可以继续优化，由上一个串的hash值直接推出当前串的hash值 
    if (!vis[tmp])
    {
      vis[tmp]=true;
      ans++;
	}
  }
  printf("%d\n",ans);
  return 0;
}

