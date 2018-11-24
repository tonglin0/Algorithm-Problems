#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;

int f[100003];
char c;

void read(int &x)
{
	x=0;
	c=getchar();
	while(!isdigit(c))
		c=getchar();
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
}

int main()
{
	int n,v,i,j,vi,wi;
	read(v);read(n);
	//scanf("%d%d",&v,&n);
	for (i=1;i<=n;i++)
	{
		read(vi);read(wi);
		//scanf("%d%d",&vi,&wi);
		for (j=vi;j<=v;j++)
			f[j]=max(f[j],f[j-vi]+wi);
	}
	printf("%d\n",f[v]);
	return 0;
}
