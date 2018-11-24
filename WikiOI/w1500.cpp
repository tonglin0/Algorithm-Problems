#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 15009
using namespace std;

char s[MN];
int x[MN],y[MN],sa[MN];
int c[MN];

void getSA(int n)
{
  memset(y,-1,sizeof(y));
  int m=227;
  int i;
  for (i=0;i<m;i++) c[i]=0;
  for (i=0;i<n;i++) 
    c[x[i]=s[i]]++;
  for (i=1;i<m;i++) 
    c[i]+=c[i-1];
  for (i=n-1;i>=0;i--) 
    sa[--c[x[i]]]=i;
  for (int k=1;k<=n;k<<=1)
  {
    int p=0;
    for (i=n-k;i<n;i++) y[p++]=i;
    for (i=0;i<n;i++) if (sa[i]>=k) y[p++]=sa[i]-k;
    for (i=0;i<m;i++) c[i]=0;
    for (i=0;i<n;i++) c[x[y[i]]]++;
    for (i=1;i<m;i++) c[i]+=c[i-1];
    for (i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];
    for (i=0;i<n;i++) swap(x[i],y[i]);
	p=1;x[sa[0]]=0;
    for (i=1;i<n;i++)
      x[sa[i]]=(y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k])?p-1:p++;
    if (p>=n)
      break;
    m=p;
  }
}

int main()
{
  freopen("1500.in","r",stdin);
  freopen("1500.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  scanf("%d",&n);
  scanf("%s",s);
  for (i=0;i<n;i++)
    s[i]-='a';
  getSA(n);
  for (i=0;i<n;i++)
    printf("%d\n",1+sa[i]);
  return 0;
}

