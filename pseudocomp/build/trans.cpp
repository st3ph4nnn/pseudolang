using namespace std;
#include <iostream>
int main()
{
int x[101];
for (int i = 0; i < 10; i++) {
std::cin>>x[i];
}
for (int i = 0; i < 10; i++) {
std::cout<<x[i];
std::cout<<"\n";
}
return 0;
}