#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<set>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 400009
using namespace std;

typedef pair<lint,int> pii;
set<pii> heap;
int l[MN],r[MN];
int a[MN];
lint b[MN];

int main()
{
  freopen("1150.in","r",stdin);
  freopen("1150.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  for (i=2;i<=n;i++)
  {
    b[i]=a[i]-a[i-1];
    l[i]=i-1;
    r[i]=i+1;
    heap.insert(pii(b[i],i));
  }
  b[1]=(lint)1e14;
  l[1]=0;r[1]=2;
  heap.insert(pii(b[1],1));
  b[n+1]=(lint)1e14;
  l[n+1]=n;
  heap.insert(pii(b[n+1],n+1));
  lint ans=0;
  while(m--)
  {
    set<pii>::iterator it=heap.begin();
    heap.erase(*it);
    ans+=it->first;
    int p=it->second;
    int ls=l[p],rs=r[p];
    l[p]=l[ls];r[p]=r[rs];
    l[r[rs]]=p;r[l[ls]]=p;
    b[p]=b[ls]+b[rs]-b[p];
    heap.erase(pii(b[ls],ls));
    heap.erase(pii(b[rs],rs));
    heap.insert(pii(b[p],p));
  }
  printf("%lld\n",ans);
  return 0;
}

