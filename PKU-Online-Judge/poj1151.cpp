#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define eps 1e-8
using namespace std;

struct node{double x,y;int c;int zx;};
int dcmp(double a){if (fabs(a)<eps) return 0;return a<0?-1:1;}
bool cmp1(double a,double b){return a<b;}
bool cmp2(node a,node b){if (dcmp(a.x-b.x)!=0) return a.x<b.x;return a.y<b.y;}
int vis[1000];
vector<node> q;
vector<double> hy;

void addy(double y)
{
  for (int i=0;i<hy.size();i++)
    if (dcmp(y-hy[i])==0) return ;
  hy.push_back(y);
  return ;
}

int findy(double yy)
{
  int f=0,r=hy.size()-1;
  while(f<r)
  {
    int mid=(r+f)>>1;
    if (dcmp(hy[mid]-yy)==0)
      return mid;
    else if (dcmp(hy[mid]-yy)>0)
      r=mid-1;
    else 
      f=mid+1;
  }
  return f;
}

int main()
{
  freopen("1151.in","r",stdin);
  freopen("1151.out","w",stdout);
  int n,i,j,k,m,l,r;
  scanf("%d",&n);
  int T=0;
  while(n)
  {
    T++;
    memset(vis,0,sizeof(vis));
    q.clear();
    double maxx=-1e9;
    hy.clear();
    for (i=1;i<=n;i++)
    {
      double x1,y1,x2,y2;
      scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
      node a;
      a.x=x1;a.y=y1;a.c=i;a.zx=1;
      q.push_back(a);
      addy(y1);
      a.y=y2;
      a.zx=2;
      addy(y2);
      q.push_back(a);
      a.x=x2;a.y=y1;a.zx=3;
      q.push_back(a);
      a.y=y2;a.zx=4;
      q.push_back(a);
    }
    sort(hy.begin(),hy.end(),cmp1);
    sort(q.begin(),q.end(),cmp2);
    //for (i=0;i<q.size();i++)
      //printf("%.2lf %.2lf\n",q[i].x,q[i].y);
    int l=q.size();
    maxx=q[l-1].x;
    double ans=0.0;
    for (i=0;i<l&&(dcmp(q[i].x-maxx)!=0);)
    {
      for (j=i+1;j<l&&(dcmp(q[i].x-q[j].x)==0);j++);
      //while(j<l&&dcmp(q[i].x-q[j].x)==0)j++;
      k=j;
      for (j=i;j<k;j++)
        if (q[j].zx==1)
        {
          int cc=q[j].c;
          int ff=findy(q[j].y);
          int ii;
          for (ii=j+1;ii<k&&(q[ii].c!=cc);ii++);
          int rr=findy(q[ii].y);
          for (ii=ff;ii<rr;ii++)
            vis[ii]++;
        }
        else if (q[j].zx==3)
        {
          int cc=q[j].c;
          int ff=findy(q[j].y);
          int ii;
          for (ii=j+1;ii<k&&(q[ii].c!=cc);ii++);
          int rr=findy(q[ii].y);
          for (ii=ff;ii<rr;ii++)
            vis[ii]--;
        }
      double xx=q[k].x-q[i].x;
      for (j=0;j<hy.size()-1;j++)
        if (vis[j]>0)
          ans+=(hy[j+1]-hy[j])*xx;
      i=k;
    }
    printf("Test case #%d\n",T);
    printf("Total explored area: %.2lf \n\n",ans);
    scanf("%d",&n);
  }
  return 0;
}
