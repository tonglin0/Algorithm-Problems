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
#define MN 210009
using namespace std;

char s[MN];
char ss[10];
int x[MN],y[MN],c[MN],sa[MN],rk[MN],ht[MN];
int nowpo[MN],nd[MN],oripo[MN];
char op[10];
bool isori[MN];
int rmq[MN>>1][30];

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

void initRMQ(int n)
{
  for (int i=1;i<=n;i++)
    rmq[i][0]=ht[i];
  for (int j=1;(1<<j)<=n;j++)
    for (int i=1;i<=n-(1<<j)+1;i++)
      rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

int LCP(int a,int b)
{
  int l=rk[a],r=rk[b];
  if (l>r)
    swap(l,r);
  l++;
  int j=0;
  while((1<<(j+1))<=r-l+1)
    j++;
  return min(rmq[l][j],rmq[r-(1<<j)+1][j]);
}


int query(int l,int r,int len)
{
  if (l==r)
    return len-nowpo[l];
  int tmplcp=LCP(l,r);
  int minlimit=min(nd[nowpo[l]]-nowpo[l],nd[nowpo[r]]-nowpo[r]);
  if (tmplcp<minlimit)
    return tmplcp;
  else
  {
    int i=nowpo[l],j=nowpo[r];
    i+=minlimit;
    j+=minlimit;
    int ans=minlimit;
    while(i<len&&j<len)
    {
      if (s[i]!=s[j])
        return ans;
      if (isori[i]&&isori[j])
        return ans+query(oripo[i],oripo[j],len);
      ans++;
      i++;
      j++;
    }
    return ans;
  }
}

int main()
{
  freopen("2758.in","r",stdin);
  freopen("2758.out","w",stdout);
  int n,i,j,k,m,ca,ii=0;
  scanf("%s",s);
  int len=strlen(s);
  int tmplen=len;
  s[len]=s[len+1]=0;
  getSA(len+1);
  getht(len);
  memset(isori,0,sizeof(isori));
  initRMQ(len);
  for (i=0;i<len;i++)
  {
    nd[i]=INF;
    oripo[i]=i;
    nowpo[i]=i;
    isori[i]=true;
  }
  int qus;
  scanf("%d",&qus);
  while(qus--)
  {
    scanf("%s",op);
    if (op[0]=='I')
    {
      scanf("%s",ss);
      char ch=ss[0];
      int d;
      scanf("%d",&d);
      d--;
      if (d>len-1)
        d=len;
      len++;
      s[len]=0;
      for (i=len-1;i>=d+1;i--)
      {
        s[i]=s[i-1];
        isori[i]=isori[i-1];
        if (isori[i-1])
		  nowpo[oripo[i-1]]=i;
		oripo[i]=oripo[i-1];
      }
      isori[d]=false;
      s[d]=ch;
      int nrs=INF;
      for (i=len-1;i>=0;i--)
        if (!isori[i])
        {
          nrs=i;
          nd[i]=i;
        }
        else
          nd[i]=nrs;
    }
    else
    {
      int l,r;
      scanf("%d%d",&l,&r);
      l--;r--;
      printf("%d\n",query(l,r,len));
    }
  }
  return 0;
}
