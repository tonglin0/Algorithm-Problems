#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define lint long long
#define HS 1000007
using namespace std;

lint head[HS+2],next[HS+2],hash[HS+2],id[HS+2];
int top;

void ex_gcd(lint a,lint b,lint &d,lint &x,lint &y)
{
  if (b==0){d=a;x=1;y=0;}
  else {ex_gcd(b,a%b,d,y,x);y-=x*(a/b);}
}

lint inv(lint a,lint n)
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
  lint k=x%HS,i;
  for (i=head[k];i!=-1;i=next[i])
    if (hash[i]==x)
      return id[i];
  return 0;
}

lint log_mod(lint a,lint b,lint c)
{
  lint p=1,v,m,i;
  if (b==1) return 0;
  top=1;
  memset(head,-1,sizeof(head));
  m=(lint)ceil(sqrt(c+0.5));
  for (i=1;i<m;i++)
  {
    p=p*a%c;
    if (!find(p))
      insert(p,i);
  }
  p=p*a%c;
  lint tmp;
  v=inv(p,c);
  for (i=0;i<m;i++)
  {
    if (b==1)
      return i*m;
    else if ((tmp=find(b))!=0)
      return i*m+tmp;
    b=b*v%c;
  }
  return -1;
}

int main()
{
  freopen("3122.in","r",stdin);
  freopen("3122.out","w",stdout);
  lint n,i,j,k,p,t,a,b,x1,T;
  scanf("%I64d",&T);
  while(T--)
  {
    scanf("%I64d%I64d%I64d%I64d%I64d",&p,&a,&b,&x1,&t);
    if (x1==t)
    {
      printf("1\n");
      continue;
    }
    else if (a==1)
    {
      if (b==0)
      {
        if (x1==t)
        {
          printf("1\n");
          continue;
        }
        else
        {
          printf("-1\n");
          continue;
        }
      }
      else if (b!=0)
      {
        lint v=inv(b,p);
        lint ans=(((t-x1)*v+1)%p+p)%p;
        if (ans==0) ans=p;
        printf("%I64d\n",ans);
        continue;  
      }
    }
    else if (a==0)
    {
      if (b==t)
      {
        printf("2\n");
        continue;
      }
      else
      {
        printf("-1\n");
        continue;
      }
    }
    else
    {
      lint v=inv(a*x1-x1+b,p);
      lint tmp=((t*(a-1)%p+b)%p*v%p+p)%p;
      lint ans=log_mod(a,tmp,p);
      if (ans==-1)
        printf("-1\n");
      else
        printf("%I64d\n",ans+1);
    }
  }
  return 0;
}
