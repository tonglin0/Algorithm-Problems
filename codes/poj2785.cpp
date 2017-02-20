#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<iostream>
#define HS 1000007
#define LL long long
using namespace std;

struct node{int time,data;};

//vector<node> h[HS+2];
//vector<node> h2[HS+2];
node h[HS][10];
node h2[HS][10];
int a[4003],b[4003],c[4003],d[4003];

bool find_add(int x)
{
  int k;
  if (x>=0)
    k=x%HS;
  else
    k=abs(x)%HS;
  if (x>=0){
  /*for (int i=0;i<h[k].size();i++)
    if (h[k][i].data==x)
    {
      h[k][i].time++;
      return true;
    }*/
  for (int i=1;i<=h[k][0].time;i++)
    if (h[k][i].data==x)
    {
      h[k][i].time++;
      return true;
    }
  return false;}/*
  for (int i=0;i<h2[k].size();i++)
    if (h2[k][i].data==x)
    {
      h2[k][i].time++;
      return true;
    }*/
  for (int i=1;i<=h2[k][0].time;i++)
    if (h2[k][i].data==x)
    {
      h2[k][i].time++;
      return true;
    }
  return false;
}

void add(int x)
{
  int k;
  if (x>=0)
    k=x%HS;
  else
    k=(-x)%HS;
  node t;
  t.time=1;t.data=x;
  /*if (x>=0)
    h[k].push_back(t);
  else
    h2[k].push_back(t);*/
  if (x>=0)
  {
    h[k][0].time++;
    int ff=h[k][0].time;
    h[k][ff]=t;
  }
  h2[k][0].time++;
  int ff=h2[k][0].time;
  h2[k][ff]=t;
}

int find(int x)
{
  int k;
  if (x>=0)
    k=x%HS;
  else
    k=(-x)%HS;
  /*if (x>=0){
  for (int i=0;i<h[k].size();i++)
    if (h[k][i].data==x)
      return h[k][i].time;
  return 0;}
  for (int i=0;i<h2[k].size();i++)
    if (h2[k][i].data==x)
      return h2[k][i].time;
  return 0;*/
  if (x>=0)
  {
    for (int i=1;i<=h[k][0].time;i++)
      if (h[k][i].data==x)
        return h[k][i].time;
    return 0;
  }
  for (int i=1;i<=h2[k][0].time;i++)
    if (h2[k][i].data==x)
      return h2[k][i].time;
  return 0;
}

int main()
{
  freopen("2785.in","r",stdin);
  freopen("2785.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  memset(h,0,sizeof(h));
  memset(h2,0,sizeof(h2));
  for (i=1;i<=n;i++)
    scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      int t=a[i]+b[j];
      if (!find_add(t))
        add(t);
    }
  LL ans=0;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      int t=c[i]+d[j];
      if (k=find(-t))
        ans=ans+(LL)k;
    }
  cout<<ans<<endl;
  return 0;
}
