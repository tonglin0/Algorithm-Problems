#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cctype>
#include<ctime>
#include<queue>
#include<string>
#include<vector>
#include<map>
#define eps 1e-8
#define INF (int)1e9
#define lint long long
#define MN 800009
#define N MN
#define llu unsigned long long
using namespace std;

struct node{
	int x,id;
};
bool cmp(node a,node b)
{
  return a.x<b.x;
}
node a[MN];
int s[MN];
int b[MN];
int rk[MN],f[MN];
int x[MN],y[MN],sa[MN],c[MN];

void getSA(int n)
{
  int i,m=200001;
  for (i=0;i<m;i++) c[i]=0;
  for (i=0;i<n;i++) c[x[i]=s[i]]++;
  for (i=1;i<m;i++) c[i]+=c[i-1];
  for (i=n-1;i>=0;i--) sa[--c[x[i]]]=i;
  for (int k=1;k<=n;k++)
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
  for (i=1;i<n;i++)
    rk[sa[i]]=i;
}

int cmp2(int *r,int a,int b,int l){  
    return (r[a]==r[b]) && (r[a+l]==r[b+l]);  }

int wa[N],wb[N],wv[N];  
void DA(int *r,int *sa,int n,int m){  
    int i,j,p,*x=wa,*y=wb,*t;  
    for(i=0;i<m;i++) c[i]=0;  
    for(i=0;i<n;i++) c[x[i]=r[i]]++;  
    for(i=1;i<m;i++) c[i]+=c[i-1];  
    for(i=n-1;i>=0;i--) sa[--c[x[i]]]=i;  
    for(j=1,p=1;p<n&&j<=n;j*=2,m=p)  
    {  
        for(p=0,i=n-j;i<n;i++) y[p++]=i;  
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;  
        for(i=0;i<n;i++) wv[i]=x[y[i]];  
        for(i=0;i<m;i++) c[i]=0;  
        for(i=0;i<n;i++) c[wv[i]]++;  
        for(i=1;i<m;i++) c[i]+=c[i-1];  
        for(i=n-1;i>=0;i--) sa[--c[wv[i]]]=y[i];  
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)  
            x[sa[i]]=cmp2(y,sa[i-1],sa[i],j)?p-1:p++;  
    }  
    for (i=1;i<n;i++)
      rk[sa[i]]=i;
}  

int main()
{
  freopen("3581.in","r",stdin);
  freopen("3581.out","w",stdout);
  int ca,n,i,j,k,m,ii=0;
  scanf("%d",&n);
  for (i=n-1;i>=0;i--)
  {
    scanf("%d",&a[i].x);
	f[i]=a[i].x;
	a[i].id=i;
  }
  int t=0;
  sort(a,a+n,cmp);
  s[a[0].id]=0;
  b[a[0].id]=0;
  for (i=1;i<=n-1;i++)
  {
    b[a[i].id]=i;
	if (a[i].x==a[i-1].x)
      s[a[i].id]=t;
    else
      s[a[i].id]=++t;
  }
  s[n+1]=s[n]=0;
  DA(s,sa,n+1,200001);
  //getSA(n+1);
  for (k=1;k<=n;k++)
    if (sa[k]>=2)
      break;
  for (i=sa[k];i<n;i++)
    printf("%d\n",f[i]);
  for (i=0;i<sa[k];i++)
    s[sa[k]+i]=s[i];
  n=sa[k]+sa[k];
  s[n]=s[n+1]=0;
  int tmpk=sa[k];
  DA(s,sa,n,200001);
  //getSA(n+1);
  int mi=INF;
  int po=1;
  for (i=1;i<tmpk;i++)
    if (rk[i]<mi)
    {
      mi=rk[i];
      po=i;
	}
  for (i=po;i<tmpk;i++)
    printf("%d\n",f[i]);
  for (i=0;i<po;i++)
    printf("%d\n",f[i]);
  return 0;
}

