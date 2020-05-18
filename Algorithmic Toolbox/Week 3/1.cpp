#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long m;
    cin>>m;

    vector <int> coins;
    coins.push_back(10);
    coins.push_back(5);
    coins.push_back(1);
    
    int i=0, coin_count=0;
    while(m > 0){
        if ((m-coins[i]) >= 0){
            m -= coins[i];
            coin_count += 1; 
        }
        else
            i++;
    }
    cout<<coin_count;
    return 0;
}
