#include<cstdio>
using namespace std;

int main()
{
	int n,i,a=1,b=1;
	scanf("%d",&n);
	bool down=false;
	for (i=1;i<=n-1;i++)
	{
		if ((a==1)&&(!down)) b++,down=true;
		else if ((b==1)&&(down)) a++,down=false;
		else if (down)
		{
			a++;b--;
		}
		else
		{
			a--;b++;
		}
	}
	printf("%d/%d\n",a,b);
	return 0;
}
