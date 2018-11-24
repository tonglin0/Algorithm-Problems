#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int find(int k)
{
  int ans=0;
  for (int i=1;i<=k;i++)
    if (k%i==0)
      ans++;
  return ans;
}

int main()
{
  freopen("2521.in","r",stdin);
  freopen("2521.out","w",stdout);
  int T,m,n,i,j,k,ans;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&k,&n);
    ans=0;
    m=k;
    for (i=k;i<=n;i++)
    {
      int t=find(i);
      if (t>ans)
      {
        ans=t;
        m=i;
      }
    }
    printf("%d\n",m);
  }
  return 0;
}
