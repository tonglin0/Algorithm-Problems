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
#define MN 40005
using namespace std;

int s[MN],x[MN],y[MN],sa[MN],ht[MN],rk[MN];
int c[1000004];

void getSA(int n)
{
  int i;
  int m=1000002;
  memset(y,-1,sizeof(y));
  memset(x,-1,sizeof(x));
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
  for (int i=1;i<=n;i++) 
    rk[sa[i]]=i;
  int i,j,k=0;
  for (i=0;i<n;i++)
  {
    if (k)
      k--;
    j=sa[rk[i]-1];
    while(s[i+k]==s[j+k])
      k++;
    ht[rk[i]]=k;
  }
}

int main()
{
  freopen("3261.in","r",stdin);
  freopen("3261.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d%d",&n,&m);
  for (i=0;i<n;i++)
    scanf("%d",&s[i]);
  s[n]=s[n+1]=0;
  getSA(n+1);
  getheight(n);
  int l=1,r=n;
  while(l<r)
  {
    int mid=(l+r+1)>>1;
    int sum=1;
    bool flag=false;
	for (i=2;i<=n;i++)
      if (ht[i]>=mid)
      {
	    sum++;
	    if (sum>=m)
	    {
	      flag=true;
	      break;
		}
	  }
      else
        sum=1;
    if (flag)
      l=mid;
    else 
      r=mid-1;
  }
  printf("%d\n",l);
  return 0;
}

