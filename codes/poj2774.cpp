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
#define MN 400005
#define maxn MN
#define rk rank
#define ht height
using namespace std;

char sta[MN],s[MN];
int x[MN],y[MN],sa[MN],ht[MN],rk[MN];
int c[203];

void getSA(int n)
{
  s[n]=0;
  memset(y,-1,sizeof(y));
  memset(x,-1,sizeof(x));
  int m=200;
  int i;
  for (i=0;i<m;i++) c[i]=0;
  for (i=0;i<n;i++) c[x[i]=s[i]]++;
  for (i=1;i<m;i++) c[i]+=c[i-1];
  for (i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
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
      x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
    if (p>=n) break;
    m=p;
  }
}

void getheight(int n)
{
  int i,j,k=0;
  for (i=1;i<=n;i++)
    rk[sa[i]]=i;
  for (i=0;i<n;i++)
  {
    if (k) k--;
    j=sa[rk[i]-1];
    while(s[i+k]==s[j+k])
      k++;
    ht[rk[i]]=k;
  }
}

int main()
{
  freopen("2774.in","r",stdin);
  freopen("2774.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%s",s);
  int len=strlen(s);
  s[len]='@';
  scanf("%s",sta);
  int len2=strlen(sta);
  for (i=0;i<len2;i++)
    s[len+i+1]=sta[i];
  s[len+len2+1]=0;
  n=strlen(s);
  getSA(n+1);
  getheight(n);
  int ms=0;
  for (i=1;i<=n;i++)
    if (min(sa[i-1],sa[i])<len&&max(sa[i-1],sa[i])>len)
      ms=max(ms,ht[i]);
  printf("%d\n",ms);
  return 0;
}

