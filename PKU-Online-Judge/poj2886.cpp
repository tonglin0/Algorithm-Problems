#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MN 2000006
using namespace std;
/*
int RPrime[]=
{
    1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,5040,7560,10080,15120,
    20160,25200,27720,45360,50400,55440,83160,110880,166320,221760,277200,332640,498960,
    554400
};

int fact[]=
{
    1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,90,96,100,108,120,128,
    144,160,168,180,192,200,216
};*/

const int P[]={1,2,3,5,7,11,13,17,19,23,29,31,37};
int p,maxx;
int s[MN];
int n;
char ch[(MN>>2)+4][13];
int next[(MN>>2)+4];

void dfs(int s,int t,int k,int limit)
{
  if (t>maxx)
  {
    maxx=t;
    p=s;
  }
  if (t==maxx&&s<p)
    p=s;
  int temp=s;
  for (int i=1;i<=limit;i++)
  {
    temp*=P[k];
    if (temp>n)
      return ;
    dfs(temp,t*(i+1),k+1,i);
  }
}

void build(int p,int l,int r)
{
  if (l==r)
  {
    s[p]=1;
    return ;
  }
  int mid=(l+r)>>1;
  build(p<<1,l,mid);
  build(p<<1|1,mid+1,r);
  s[p]=s[p<<1]+s[p<<1|1];
}

int query(int p,int l,int r,int k)
{
  if (l==r)
  {
    s[p]=0;
    return l;
  }
  int t,mid=(l+r)>>1;
  if (s[p<<1]>=k)
  {
    t=query(p<<1,l,mid,k);
    s[p]=s[p<<1]+s[p<<1|1];
    return t;
  }
  else
  {
    k-=s[p<<1];
    t=query(p<<1|1,mid+1,r,k);
    s[p]=s[p<<1]+s[p<<1|1];
    return t;
  }
}

int main()
{
  freopen("2886.in","r",stdin);
  freopen("2886.out","w",stdout);
  int i,j,k,m;
  while(scanf("%d%d",&n,&m)==2)
  {
    memset(next,0,sizeof(next));
    for (i=0;i<n;i++)
      scanf("%s%d",ch[i],&next[i]);
    //int p,maxx;
    /*for (i=0;;i++)
    {
      if (RPrime[i]>n)
      {
        p=RPrime[i-1];
        maxx=fact[i-1];
        break;
      }
    }*/
    build(1,0,n-1);
    p=0;maxx=0;
    dfs(1,1,1,50);
    int ans,N=n;
    k=m-1;
    for (i=1;i<=p;i++)
    {
      ans=query(1,0,n-1,k+1);
      N--;
      //ans=(ans+1)%n;
      if (N==0) break;
      if (next[ans]>0)k=((k-1+next[ans])%N+N)%N;   // if k<0 the answer is wrong
        else k=((k+next[ans])%N+N)%N;
    }
    printf("%s %d\n",ch[ans],maxx);
  }
  return 0;
}
