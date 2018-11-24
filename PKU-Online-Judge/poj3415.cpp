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
#define MN 2000005
#define llu unsigned long long
using namespace std;

char s[MN];
int x[MN],y[MN],sa[MN],ht[MN],rk[MN];
int c[MN];
struct node{
	int h,na,nb;
};
node st[MN];

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
	  x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p-1:p++;
	if (p>=n)
	  break;
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
  freopen("3415.in","r",stdin);
  freopen("3415.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  while(scanf("%d",&m)==1)
  {
    if (m==0)
      break;
    scanf("%s",s);
    int len1=strlen(s);
    s[len1]='|';
    scanf("%s",s+len1+1);
    n=strlen(s);
    s[n]=s[n+1]=0;
    getSA(n+1);
    getheight(n);
    lint ans=0;
    int top=0;
    lint suma=0,sumb=0;
    i=1;
    while(i<=n)
    {
      j=i;
      while(j+1<=n&&ht[j+1]>=m)
        j++;
      top=0;
      suma=0;sumb=0;
      for (k=i+1;k<=j;k++)
      {
        node tmp;
        tmp.h=ht[k]-m+1;tmp.na=tmp.nb=0;
        if (sa[k-1]<len1)
          tmp.na++;
        else if (sa[k-1]>len1)
          tmp.nb++;
        while(top>0&&st[top].h>tmp.h)
        {
          tmp.na+=st[top].na;
          tmp.nb+=st[top].nb;
          suma-=(lint)st[top].h*(lint)st[top].na;
          sumb-=(lint)st[top].h*(lint)st[top].nb;
          top--;
		}
		suma+=(lint)tmp.na*(lint)tmp.h;
		sumb+=(lint)tmp.nb*(lint)tmp.h;
		st[++top]=tmp;
		if (sa[k]<len1)
		  ans+=sumb;
		else if (sa[k]>len1)
		  ans+=suma;
	  }
	  i=j+1;
	}/*       注释掉的做法也是对的 
    for (i=1;i<=n;i++)
      ht[i]-=(m-1);
    for (i=2;i<=n;i++)
      if (ht[i]<0)
      {
        suma=sumb=top=0;
	  }
	  else
	  {
	    st[++top].h=ht[i];
	    if (sa[i-1]<len1)
	    {
	      st[top].na=1;st[top].nb=0;
	      suma+=st[top].h;
		}
		else if (sa[i-1]>len1)
		{
		  st[top].nb=1;st[top].na=0;
		  sumb+=st[top].h;
		}
		while(top>1&&st[top].h<=st[top-1].h)
		{
		  suma=suma-(lint)st[top-1].h*(lint)st[top-1].na+(lint)st[top].h*(lint)st[top-1].na;
		  sumb=sumb-(lint)st[top-1].h*(lint)st[top-1].nb+(lint)st[top].h*(lint)st[top-1].nb;
		  st[top-1].na+=st[top].na;
		  st[top-1].nb+=st[top].nb;
		  st[top-1].h=st[top].h;
		  top--;
		}
		if (sa[i]<len1)
		  ans+=sumb;
		else if (sa[i]>len1)
		  ans+=suma;
	  }*/
	printf("%lld\n",ans);
  }
  return 0;
}

