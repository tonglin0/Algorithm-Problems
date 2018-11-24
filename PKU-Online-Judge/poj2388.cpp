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
#define MN 1000003
using namespace std;

int a[MN],bk[MN];
int ct[11];
int tens[]={1,1,10,100,1000,10000,100000,1000000,10000000,100000000};

int dig(int x,int k)
{
  return x/tens[k]%10;
}

int main()
{
  freopen("2388.in","r",stdin);
  freopen("2388.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  int d=7;
  for (k=1;k<=d;k++)
  {
    memset(ct,0,sizeof(ct));
    for (i=1;i<=n;i++)
      ct[dig(a[i],k)]++;
    for (i=1;i<=9;i++)
      ct[i]+=ct[i-1];
    for (i=n;i>=1;i--)
      bk[ct[dig(a[i],k)]--]=a[i];
    for (i=1;i<=n;i++)
      a[i]=bk[i];
  }
  printf("%d\n",a[(n>>1)+1]);
  return 0;
}

