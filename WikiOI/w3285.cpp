#include<iostream>
#include<cstdlib>
using namespace std;

int pow(long long a,long long b,long long c)
{
  long long ans=1;
  a=a%c;
  while(b>0)
  {
    if (b%2==1) ans=ans*a%c;
    b=b>>1;
    a=a*a%c;
  }
  return ans;
}

int main()
{
  long long m,x,k,n;
  cin>>n>>m>>k>>x;
  long long a;
  a=(x%n+pow(10,k,n)*m%n)%n;
  cout<<a<<endl;
  //system("pause");
  return 0;
}
