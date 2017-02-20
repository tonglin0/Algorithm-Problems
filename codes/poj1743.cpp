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
#define MN 40005
using namespace std;

int s[MN],b[MN];
int x[MN],y[MN],sa[MN];
int c[MN];
int rank[MN],ht[MN];

void getSA(int n)
{
  int i;
  int m=300;
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
      x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;
    if (p>=n)
      break;
    m=p;
  }
}

void getheight(int n)
{
  int i;
  for (i=1;i<=n;i++)
    rank[sa[i]]=i;
  int k=0,j;
  for (i=0;i<n;i++)
  {
    if (k)
      k--;
    j=sa[rank[i]-1];
    while(s[i+k]==s[j+k])
      k++;
    ht[rank[i]]=k;
  }
}

int main()
{
  freopen("1743.in","r",stdin);
  freopen("1743.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  while(scanf("%d",&n)==1)
  {
    if (n==0)
      break;
    for (i=1;i<=n;i++)
      scanf("%d",&b[i]);
    if (n<=9)
    {
      printf("0\n");
      continue;
    }
    for (i=0;i<n-1;i++)
      s[i]=b[i+2]-b[i+1]+150;
    n--;
    s[n]=s[n+1]=0;
    getSA(n+1);
    getheight(n);
    int l=0,r=n;
    while(l<r)
    {
      int mid=(l+r+1)>>1;
      bool flag=false;
      int ms=sa[0],mi=sa[0];
      for (i=1;i<=n;i++)
        if (ht[i]>=mid)
        {
          ms=max(ms,sa[i]);
          mi=min(mi,sa[i]);
          if (ms-mi>mid)
          {
            flag=true;
            break;
		  }
		}
	    else
	    {
	      ms=mi=sa[i];
		}
	  if (flag)
	    l=mid;
	  else
	    r=mid-1;
	}
	if (l>=4)
	  printf("%d\n",l+1);
	else
	  printf("0\n");
  } 
  return 0;
}

