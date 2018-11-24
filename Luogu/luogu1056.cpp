#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a[1003],b[1003];
int A[1003],B[1003];

bool cmp(int a,int b){return a>b;}

int get_kth(int *a,int l,int r,int k)
{
	int tl=l,tr=r;
	int x=a[l];
	while(l<r)
	{
		while(l<r&&a[r]<=x)
			r--;
		a[l]=a[r];
		while(l<r&&a[l]>=x)
			l++;
		a[r]=a[l];
	}
	a[l]=x;
	if (l==k)
		return a[l];
	else if (l<k)
		return get_kth(a,l+1,tr,k);
	else 
		return get_kth(a,tl,l-1,k);
	//sort(a+1,a+r+1,cmp);
	//return a[k];
}

int main()
{
	freopen("1056.in","r",stdin);
	int d,n,m,i,j,k,l;
	scanf("%d%d%d%d%d",&n,&m,&k,&l,&d);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	while(d--)
	{
		int x,y,p,q;
		scanf("%d%d%d%d",&x,&y,&p,&q);
		if (x==p)
			b[min(y,q)]++;
		else
			a[min(x,p)]++;
	}
	memcpy(A,a,(n+1)*sizeof(int));
	memcpy(B,b,(m+1)*sizeof(int));
	int ta=get_kth(A,1,n,k);
	int tb=get_kth(B,1,m,l);
	bool first=true;
	for (i=1;i<=n;i++)
		if (a[i]>=ta)
		{
			if (first)
			{
				printf("%d",i);
				first=false;
			}
			else
				printf(" %d",i);
		}
	printf("\n");
	first=true;
	for (i=1;i<=m;i++)
		if (b[i]>=tb)
		{
			if (first)
			{
				printf("%d",i);
				first=false;
			}
			else
				printf(" %d",i);
		}
	printf("\n");
	return 0;
}
