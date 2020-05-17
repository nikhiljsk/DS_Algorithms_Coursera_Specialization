// #include <iostream>
// #include <vector>
// using namespace std;

// int main()
// {
//     long long a, b, temp;
//     cin>>a>>b;
    
//     if(a>b){
//         temp = a;
//         a = b;
//         b = temp;
//     }
//     temp = b;
//     while(true){
//         if (b%a==0)
//             break;
//         b += temp;
//     }
//     cout<<b;
//     return 0;
// }

// Could be much more faster using this relation
// LCM(a, b) = (a*b)/GCD(a, b)


#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long a, b, temp, temp1, temp2;
    cin>>a>>b;
    temp1 = a;
    temp2 = b;
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
    cout<<((temp1*temp2)/b);
    return 0;
}
