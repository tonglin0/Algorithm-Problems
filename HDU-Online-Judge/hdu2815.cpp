#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define lint long long
#define HS 100017
using namespace std;

int top;
lint head[HS+2],next[HS+2],hash[HS+2],id[HS+2];

lint pow_mod(lint a,lint b,lint c)
{
  lint ans=1,t=a%c;
  while(b>0)
  {
    if (b&1) ans=ans*t%c;
    b=b>>1;
    t=t*t%c;
  }
  return ans;
}

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
  lint x,y,d;
  ex_gcd(a,n,d,x,y);
  return (x%n+n)%n;
}

void insert(lint x,lint y)
{
  lint k=x%HS;
  hash[top]=x;
  id[top]=y;
  next[top]=head[k];
  head[k]=top++;
}

lint find(lint x)
{
  lint k=x%HS;
  for (lint i=head[k];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

lint log_mod(lint a,lint b,lint c)
{
  if (b==1)
    return 0;
  lint i,d,v,p=1%c;
  for (i=1;i<=100;i++)
  {
    p=p*a%c;
    if (p==b)
      return i;
  }
  lint tmp=0;
  lint revk=1;
  while((d=gcd(a,c))!=1)
  {
    if (b%d) return -1;
    c/=d;
    b/=d;
    revk=revk*a/d%c;
    tmp++;
  }
  revk=rev(revk,c);
  b=b*revk%c;
  if (b==1) return tmp;
  memset(head,-1,sizeof(head));
  top=1;
  lint m=(lint)ceil(sqrt(c+0.5));
  p=1;
  for (i=1;i<m;i++)
  {
    p=p*a%c;
    if (!find(p))
      insert(p,i);
  }
  v=rev(pow_mod(a,m,c),c);
  lint iffind;
  for (i=0;i<m;i++)
  {
    if (b==1)
      return i*m+tmp;
    else if ((iffind=find(b))!=0)
      return i*m+iffind+tmp;
    b=b*v%c;    
  }
  return -1;
}

int main()
{
  freopen("2815.in","r",stdin);
  freopen("2815.out","w",stdout);
  lint a,b,c,ans;
  while((scanf("%I64d%I64d%I64d",&a,&c,&b)==3)&&a&&b&&c)
  {
    a%=c;
    if (b>=c)
    {
      printf("Orz,I can¡¯t find D!\n");
      continue;
    }
    if (b==0)
    {
      if (c==0)
        printf("0\n");
      else
        printf("Orz,I can¡¯t find D!\n");
      continue;
    }
    ans=log_mod(a,b,c);
    if (ans==-1)
      printf("Orz,I can¡¯t find D!\n");
    else
      printf("%I64d\n",ans);
  }
  return 0;
}
