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
#define MN 80009
using namespace std;

int st[MN];

int main()
{
  freopen("3250.in","r",stdin);
  freopen("3250.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  lint ans=0;
  scanf("%d",&n);
  int top=0;
  for (i=1;i<=n;i++)
  {
    int num;
    scanf("%d",&num);
    while(top>0&&st[top]<=num)
      top--;
    ans+=top;
    st[++top]=num;
  }
  printf("%lld\n",ans);
  return 0;
}

