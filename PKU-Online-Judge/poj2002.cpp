#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define HS 997
using namespace std;

struct node{int x,y;};

node h[HS+2][HS+2];
node l[1004];

int hash(int x,int y)
{
  return abs(x+y)%HS;
}

void add(int x,int y)
{
  int k=hash(x,y);
  h[k][0].x++;
  int ff=h[k][0].x;
  h[k][ff].x=x;h[k][ff].y=y;
}

bool find(int x,int y)
{
  int k=hash(x,y);
  for (int i=1;i<=h[k][0].x;i++)
    if (h[k][i].x==x&&h[k][i].y==y)
      return true;
  return false;
}

int main()
{
  freopen("2002.in","r",stdin);
  freopen("2002.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  while(n){
  memset(l,0,sizeof(l));
  memset(h,0,sizeof(h));
  for (i=1;i<=n;i++)
  {
    int x,y;
    scanf("%d%d",&x,&y);
    l[i].x=x;l[i].y=y;
    add(x,y); 
  }
  int ans=0;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j) continue;
      int a=l[i].x,b=l[i].y,c=l[j].x,d=l[j].y;
      if (find(c+d-b,d+a-c)&&find(a-b+d,b+a-c))
        ans++;
    }
  printf("%d\n",ans/4);
  scanf("%d",&n);}
  return 0;
}
