#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<cctype>
#include<algorithm>
#define INF (int)1e9
#define lint long long
#define llu unsigned long long
#define eps 1e-8
#define MN 100009
#define maxn MN
#define rk Rank
#define ht height
using namespace std;

char s[MN];
int sa[MN],ht[MN],rk[MN];
int c[303];
int rmq[MN][30];
int a[MN];

int wa[maxn],wb[maxn],wv[maxn],Ws[maxn];    
int cmp(int *r,int a,int b,int l)    
{return r[a]==r[b]&&r[a+l]==r[b+l];}    
void da(const char *r,int *sa,int n,int m){    
    int i,j,p,*x=wa,*y=wb,*t;     
    for(i=0;i<m;i++) Ws[i]=0;     
    for(i=0;i<n;i++) Ws[x[i]=r[i]]++;     
    for(i=1;i<m;i++) Ws[i]+=Ws[i-1];     
    for(i=n-1;i>=0;i--) sa[--Ws[x[i]]]=i;     
    for(j=1,p=1;p<n;j*=2,m=p){     
        for(p=0,i=n-j;i<n;i++) y[p++]=i;     
        for(i=0;i<n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;     
        for(i=0;i<n;i++) wv[i]=x[y[i]];     
        for(i=0;i<m;i++) Ws[i]=0;     
        for(i=0;i<n;i++) Ws[wv[i]]++;     
        for(i=1;i<m;i++) Ws[i]+=Ws[i-1];     
        for(i=n-1;i>=0;i--) sa[--Ws[wv[i]]]=y[i];     
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)     
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;     
    }     
    return;     
}    
//int sa[maxn],Rank[maxn],height[maxn];    
//ÇóheightÊý×é    
void calheight(const char *r,int *sa,int n){    
    int i,j,k=0;    
    for(i=1;i<=n;i++) Rank[sa[i]]=i;    
    for(i=0;i<n;height[Rank[i++]]=k)    
        for(k?k--:0,j=sa[Rank[i]-1];r[i+k]==r[j+k];k++);    
    return;    
}  
/*
void getSA(int n)
{
  //memset(ht,0,sizeof(ht));
  //memset(rk,0,sizeof(rk));
  int i;
  int m=200;
  //memset(x,-1,sizeof(x));
  //memset(y,-1,sizeof(y));
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

void getheight(int n)
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
*/
void initRMQ(int n)
{
  //memset(rmq,60,sizeof(rmq));
  for (int i=1;i<=n;i++)
    rmq[i][0]=ht[i];
  for (int j=1;(1<<j)<=n;j++)
    for (int i=1;i<=n-(1<<j)+1;i++)
      rmq[i][j]=min(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
}

int LCP(int l,int r)
{
  l=rk[l],r=rk[r];
  if (l>r)
    swap(l,r);
  l++;
  //int j=0;
  int j=(int)(floor(log(r-l+1+0.01)/log(2.0)));
  //while((1<<(j+1))<=r-l+1)
    //j++;
  return min(rmq[l][j],rmq[r-(1<<j)+1][j]);
}

int main()
{
  freopen("3693.in","r",stdin);
  freopen("3693.out","w",stdout);
  int n,i,j,k,m,ii=0,ca;
  while(scanf("%s",s)==1)
  {
    if (s[0]=='#')
      break;
    n=strlen(s);
    //s[n]=s[n+1]=0;
    s[n]='@';s[++n]=0;s[n+1]=0;
    da(s,sa,n+1,200);
    calheight(s,sa,n);
	//getSA(n+1);
    //getheight(n);
    initRMQ(n);
    int cnt=1,ans=1;
    a[1]=1;
    for (int l=1;l<=n;l++)
    {
      for (i=0;i+l<n;i+=l)
      {
        k=LCP(i,i+l);
        int times=k/l+1;
        if (k%l)
        {
          int tmp=k%l;
          int tmpi=i-(l-tmp);
          if (tmpi>=0&&LCP(tmpi,tmpi+l)>k)
            times++;
		}
		if (times>ans)
		{
		  ans=times;
		  cnt=0;
		  a[++cnt]=l;
		}
		else if (times==ans)
		{
		  a[++cnt]=l;
		}
	  }
	}
	int len=-1,st;
	for (i=1;i<=n&&len==-1;i++)
	{
	  for (j=1;j<=cnt;j++)
	  {
	    int l=a[j];
	    if (sa[i]+l<n)
		if (LCP(sa[i],sa[i]+l)>=(ans-1)*l)
	    {
	      len=l;
	      st=sa[i];
	      break;
		}
	  }
	}
	printf("Case %d: ",++ii);
	for (i=st,j=0;j<ans*len;j++,i++)
	  putchar(s[i]);
	printf("\n");
	//memset(s,0,sizeof(s));
  }
  return 0;
}

