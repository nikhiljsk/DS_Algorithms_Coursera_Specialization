#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long a, b, temp;
    cin>>a>>b;
    
    if(a>b){
        temp = a;
        a = b;
        b = temp;
    }
    
    while(a!=0){
        temp = b;
        b = a;
        a = temp%a;
    }
    cout<<b;
    return 0;
}
