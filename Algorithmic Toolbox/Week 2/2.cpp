#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector <int> a;
    a.push_back(0);
    a.push_back(1);
    for (int i=2; i<=n; i++){
        a.push_back((a[i-1]+a[i-2])%10);
    }
    cout<<a[n];
    return 0;
}
