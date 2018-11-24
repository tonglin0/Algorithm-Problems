#include<cstdio>
#include<cstring>
using namespace std;

struct node{char name[30];int a,b,l,s;bool isg,isx;};
node a[103];

int main()
{
	int n,i;
	int ans=0;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%s",a[i].name);
		scanf("%d%d",&a[i].a,&a[i].b);
		char t[3];
		scanf("%s",t);
		if (t[0]=='Y')
			a[i].isg=true;
		else 
			a[i].isg=false;
		scanf("%s",t);
		if (t[0]=='Y')
			a[i].isx=true;
		else
			a[i].isx=false;
		scanf("%d",&a[i].l);
		a[i].s=0;
		if (a[i].a>80&&a[i].l>=1)
			a[i].s+=8000;
		if (a[i].a>85&&a[i].b>80)
			a[i].s+=4000;
		if (a[i].a>90)
			a[i].s+=2000;
		if (a[i].a>85&&a[i].isx)
			a[i].s+=1000;
		if (a[i].b>80&&a[i].isg)
			a[i].s+=850;
		ans+=a[i].s;
	}
	int ms=1;
	for (i=2;i<=n;i++)
		if (a[i].s>a[ms].s)
			ms=i;
	printf("%s\n",a[ms].name);
	printf("%d\n%d\n",a[ms].s,ans);
	return 0;
}
