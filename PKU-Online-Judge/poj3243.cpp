#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint long long
#define HS 100007
using namespace std;

int head[HS+2],hash[HS+2],id[HS+2],next[HS+2];
int top;

lint gcd(lint a,lint b)
{
  lint t;
  while(b)
  {
    t=a;
    a=b;
    b=t%b;
  }
  return a;
}

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else{ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint rev(lint a,lint n)
{
  lint d,x,y;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

void insert(lint x,lint y)
{
  lint t=x%HS;
  hash[top]=x;
  id[top]=y;
  next[top]=head[t];
  head[t]=top++;
}

lint find(lint x)
{
  lint t=x%HS;
  for (lint i=head[t];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

lint log_mod(lint a,lint b,lint c)
{
  lint p=1,i,j,k=0,v;
  top=0;
  memset(head,-1,sizeof(head));
  for (i=0;i<64;i++)
  {
    if (p==b)
      return i;
    p=p*a%c;
  }
  lint d;
  p=1;
  while((d=gcd(a,c))!=1)
  {
    if (b%d)
      return -1;
    b/=d;
    c/=d;
    k++;
    p=p*a/d%c;
  }
  b=b*rev(p,c)%c;
  lint m=ceil(sqrt(c+0.5));
  p=1;
  for (i=1;i<m;i++)
  {
    p=p*a%c;
    if (!find(p))
      insert(p,i);
  }
  p=p*a%c;
  v=rev(p,c);
  lint t;
  for (i=0;i<m;i++)
  {
    if (b==1)
      return i*m+k;
    if ((t=find(b))!=0)
      return i*m+t+k;
    b=b*v%c;
  }
  return -1;
}

int main()
{
  freopen("3243.in","r",stdin);
  freopen("3243.out","w",stdout);
  int a,c,b;
  while(scanf("%d%d%d",&a,&c,&b)==3&&(a+b+c))
  {
  	b%=c;
    lint ans=log_mod(a,b,c);
    if (ans==-1)
      printf("No Solution\n");
    else
      printf("%d\n",(int)ans);
  }
  return 0;
}
