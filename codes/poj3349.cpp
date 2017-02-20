#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#define HS 99983
using namespace std;

struct node{int s[7];};

//vector<node> h[HS+2];
node h[HS+2][10];

bool same(node a,node b)
{
  int i,j;
  bool flag=true;
  for (j=0;j<6;j++)
  {
    flag=true;
    for (i=0;i<6;i++)
    {
      if (a.s[i]!=b.s[(i+j)%6]) 
      {
        flag=false;
        break;
      }
    }
    if (flag) return true;
  }
  for (j=0;j<6;j++)
  {
    flag=true;
    for (i=0;i<6;i++)
    {
      if (a.s[i]!=b.s[(-i-j+12)%6]) 
      {
        flag=false;
        break;
      }
    }
    if (flag) return true;
  }
  return false;
}

bool find(node a,int &m)
{
  int k=0;
  for (int i=0;i<6;i++)
    k=(k+a.s[i])%HS;
  /*for (int i=0;i<h[k].size();i++)
    if (same(a,h[k][i]))
      return true;*/
  for (int i=1;i<=h[k][0].s[0];i++)
    if (same(a,h[k][i]))
      return true;
      
  m=k;
  return false;
}

void add(node a,int k)
{
  //h[k].push_back(a);
  h[k][0].s[0]++;
  int ff=h[k][0].s[0];
  h[k][ff]=a;
}

int main()
{
  freopen("3349.in","r",stdin);
  freopen("3349.out","w",stdout);
  int n,i,j,k,m;
  scanf("%d",&n);
  memset(h,0,sizeof(h));
  for (i=1;i<=n;i++)
  {
    node a;
    for (j=0;j<6;j++)
      scanf("%d",&a.s[j]);
    if (find(a,m))
    {
      printf("Twin snowflakes found.\n");
      return 0;
    }
    else add(a,m);
  }
  printf("No two snowflakes are alike.\n");
  return 0;
}
