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
#define MN 402000
using namespace std;

char ss[MN];
int s[MN];
int x[MN],y[MN],sa[MN],ht[MN],rk[MN];
int c[MN];
int po[MN];
bool vis[103];

void getSA(int n)
{
  int i,m=1000;
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
  freopen("3294.in","r",stdin);
  freopen("3294.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  bool first=true;
  while(scanf("%d",&n)==1)
  {
    if (n==0)
      break;
    if (first)
      first=false;
    else
      printf("\n");
    int len=0;
    po[0]=-1;
    if (n==1)
    {
      scanf("%s",ss);
      printf("%s\n",ss);
      continue;
	}
	memset(s,0,sizeof(s));
    for (i=1;i<=n;i++)
    {
      scanf("%s",ss+len);
      int t=strlen(ss);
      ss[t]='#';
      s[t++]='z'+i+1;
      po[i]=t-1;
	  len=t;
	}
	for (i=0;i<=len;i++)
	  if (s[i]==0)
	    s[i]=ss[i];
	s[len]=s[len+1]=0;
	getSA(len+1);
	getht(len);
	int l=0,r=1001;
	while(l<r)
	{
	  int mid=(l+r+1)>>1;
	  int cnt=0;
	  bool flag=false;
	  memset(vis,0,sizeof(vis));
	  for (i=1;i<=len;i++)
	    if (ht[i]<mid)
	    {
	      if (cnt)
		    for (j=0;j<=n+1;j++)
	          vis[j]=false;
	      int tmpk=INF;
		  for (j=1;j<=n;j++)
		    if (sa[i]<po[j]&&sa[i]>po[j-1])
		    {
		      tmpk=j;
		      break;
			}
		  cnt=0;
		  if (tmpk!=INF)
		  {
		    vis[tmpk]=true;
		    cnt=1;
		  }
		  if (cnt>n/2)
		  {
		    flag=true;
		    break;
		  }
		}
		else
		{
		  for (j=1;j<=n;j++)
		    if (sa[i]<po[j]&&sa[i]>po[j-1])
		    {
		      if (!vis[j])
		      {
		        vis[j]=true;
		        cnt++;
		        if (cnt>n/2)
		        {
		          flag=true;
		          break;
				}
			  }
			  break;
			}
		  if (flag)
		    break;
		}
	  if (flag)
	    l=mid;
	  else
	    r=mid-1;
	}
	//printf("%d\n",l);
	if (l==0)
	  printf("?\n");
	else
	{
	  memset(vis,0,sizeof(vis));
	  int tmpl=l;
	  int cnt=0;
	  for (i=1;i<=len;i++)
	    if (ht[i]<tmpl)
	    {
	      if (cnt>n/2)
	      {
	        int st=sa[i-1];
	        for (int ii=st;ii<st+tmpl;ii++)
	          printf("%c",s[ii]);
	        printf("\n");
		  }
	      if (cnt)
		    for (j=0;j<=n+1;j++)
	          vis[j]=false;
	      int tmpk=INF;
	      cnt=0;
		  for (j=1;j<=n;j++)
		    if (sa[i]<po[j]&&sa[i]>po[j-1])
		    {
		      tmpk=j;
		      break;
			}
		  if (tmpk!=INF)
		  {
		    vis[tmpk]=true;
		    cnt=1;
		  }
		}
		else
		{
		  for (j=1;j<=n;j++)
		    if (sa[i]<po[j]&&sa[i]>po[j-1])
		    {
		      if (!vis[j])
		      {
		        vis[j]=true;
		        cnt++;
			  }
			}
		}
	}
  }
  return 0;
}

