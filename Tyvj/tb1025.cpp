#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[5003];
int main()
{
  int i,n;
  memset(a,0,sizeof(a));
  scanf("%d\n",&n);
  for (i=1;i<=n;i++)
    scanf("%d",&a[i]);
  sort(a,a+n);
  for (i=n;i>=1;i--)
    printf("%d\n",a[i]);
  //system("pause");
  return 0;
}
 
