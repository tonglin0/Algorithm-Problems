#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 200100
#define lint long long
using namespace std;

lint a[MN],c2[MN],c1[MN];
char ch[30];
int n;

int low(int x){return x&(-x);}

void add(lint *c,int x,lint d)
{
  int i=x;
  while(i<=n)
  {
    c[i]+=d;
    i+=low(i);
  }
}

lint find(lint *c,int x)
{
  lint ans=0;int i=x;
  while(i>0)
  {
    ans+=c[i];
    i-=low(i);
  }
  return ans;
}

int main()
{
  freopen("3155.in","r",stdin);
  freopen("3155.out","w",stdout);
  int i,j,k,m;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%lld",&a[i]);
  memset(c1,0,sizeof(c1));
  memset(c2,0,sizeof(c2));
  for (i=1;i<=n;i++)
    add(c1,i,a[i]);
  for (i=1;i<=n;i++)
    add(c2,i,i*a[i]);
  while(m--)
  {
    scanf("%s",ch);
    if (ch[0]=='Q')
    {
      scanf("%d",&k);
      printf("%lld\n",(k+1)*find(c1,k)-find(c2,k));
    }
    else
    {
      scanf("%d%d",&i,&k);
      add(c1,i,k-a[i]);
      add(c2,i,i*(k-a[i]));
      a[i]=k;
    }
  }
  return 0;
}
