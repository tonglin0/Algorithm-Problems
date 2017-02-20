#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#include<queue>
#define lint long long
#define INF (int)1e9
#define eps 1e-8
#define MN 120009
using namespace std;

char s[MN];
char ss[MN];
int x[MN],y[MN],sa[MN],rk[MN],c[MN];

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
      x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k])?p-1:p++;
    if (p>=n)
      break;
    m=p;
  }   
  for (i=1;i<n;i++)
    rk[sa[i]]=i;
}

int main()
{
  freopen("3623.in","r",stdin);
  freopen("3623.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  scanf("%d",&n);
  gets(s);
  for (i=0;i<n;i++)
  {
    char ch;
    scanf("%c",&ch);
    gets(ss);
    s[i]=ch;
  }
  s[n]='#';
  int tmpn=n;
  for (i=0;i<tmpn;i++)
    s[++n]=s[tmpn-1-i];
  n++;
  s[n]=s[n+1]=0;
  getSA(n+1);
  int flag=0;
  int l=0,r=tmpn-1;
  for (i=0;i<tmpn;i++)
  {
    int a=rk[l],b=rk[n-1-r];
    if (a<b)
      printf("%c",s[l++]);
    else
      printf("%c",s[r--]);
    flag++;
    if (flag==80)
    {
      printf("\n");
      flag=0;
    }
  }
  if (flag)
    printf("\n");
  return 0;
}
