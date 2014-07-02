

#include <iostream>
#include <map>

int main ()
{

try
{
int *myarray=new int[10];
for(int i=0;i<10;i++)
{
*myarray=i;
myarray++;
}


for(int i=0;i<10;i++)
{
std::cout<<*myarray;
myarray--;
}

}
catch(std::bad_alloc& ba)
{
std::cerr<<"bad alloc caught"<<ba.what();
}

  return 0;
}







