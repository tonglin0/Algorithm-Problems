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
#define MN 82000
using namespace std;

char ss[MN];
char saa[MN];
int s[MN];
int x[MN],y[MN],sa[MN],ht[MN],rk[MN];
int c[MN];
int po[MN];
bool vis[103];
int n;

int getpos(int x)
{
  if (ss[x]=='#')
    return -1;
  for(int i=1;i<=n;i++) 
    if (x<po[i]&&x>po[i-1])
      return i;
  return -1;
}

void getSA(int n)
{
  int m=1000;
  int i;
  for (i=0;i<m;i++) c[i]=0;
  for (i=0;i<n;i++) c[x[i]=s[i]]++;
  for (i=1;i<m;i++) c[i]+=c[i-1];
  for (i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
  for (int k=1;k<=n;k++)
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

void getht(int n)
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
  freopen("1226.in","r",stdin);
  freopen("1226.out","w",stdout);
  int ca,i,j,k,m,ii=0;
  scanf("%d",&ca);
  while(ca--)
  {
    scanf("%d",&n);
    if (n==1)
    {
      scanf("%s",ss);
      printf("%d\n",strlen(ss));
      continue;
	}
    po[0]=-1;
    int len=0;
    for (i=1;i<=n;i++)
    {
      scanf("%s",saa);
      int lena=strlen(saa);
      for (j=0;j<lena;j++)
        ss[len++]=saa[j];
      ss[len++]='#';
      for (j=lena-1;j>=0;j--)
        ss[len++]=saa[j];
      ss[len++]='#';
      po[i]=len-1;
	}
	ss[len]=0;
	int tmp=200;
	for (i=0;i<len;i++)
	  if (ss[i]=='#')
	    s[i]=++tmp;
	  else
	    s[i]=ss[i];
	s[len]=s[len+1]=0;
	getSA(len+1);
	getht(len);
	int l=0,r=100;
	while(l<r)
	{
	  int cnt=0;
	  bool flag=false;
	  int mid=(l+r+1)>>1;
	  for (i=1;i<=len;i++)
	    if (ht[i]<mid)
	    {
	      memset(vis,0,sizeof(vis));
	      cnt=0;
	      int tmpk=getpos(sa[i]);
	      if (tmpk!=-1)
	      {
	        vis[tmpk]=true;
	        cnt++;
		  }
		  if (cnt>=n)
		  {
		    flag=true;
		    break;
		  }
		}
		else
		{
		  int tmpk=getpos(sa[i]);
		  if (!vis[tmpk])
		  {
		    cnt++;
		    vis[tmpk]=true;
		  }
		  if (cnt==n)
		  {
		    flag=true;
		    break;
		  }
		}
	  if (flag)
	    l=mid;
	  else
	    r=mid-1;
	}
	printf("%d\n",l);
  }
  return 0;
}

