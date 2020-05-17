// Approach - Not Geometrical. Simple Logic
// Given n, since it's cylce for last digit (10) is 60
// if given n=63; All I've to do is:
// n%60 => 3
// Now, iterate over the squared_pisano_cycle and add the first 3 digits, and return %10 as result
// So, squared_pisano_cycle = 1, 1, 4, 9, 5, 4, 9, 1, 6, 5, 1 ...
// 1+1+4 = 6
// Time Complexity: O(60) i.e O(constant), O(1s)
#include <iostream>
#include <vector>
using namespace std;

vector <long long> pisano(long long m){
    vector <long long> p_cycle;
    
    p_cycle.push_back(0);
    p_cycle.push_back(1);
    
    for (int i=2; i<=m*m*m; i++){
        p_cycle.push_back((p_cycle[i-2] + p_cycle[i-1])%m);
        
        if (i!=2 && p_cycle[i-2]==0 && p_cycle[i-1]==1){
            // Period repeated
            return p_cycle;
        }
    }
}

vector <long long> pisano_n_square_cycle(long long n, long long m){
    long long p, temp;
    
    vector <long long> p_cycle = pisano(m);
    // Remove last 2 elements 0 and i-1
    p_cycle.pop_back();
    p_cycle.pop_back();
    p_cycle.pop_back();
    
    vector <long long> p_squared_cycle;
    for (int i=0; i<p_cycle.size(); i++){
        p_squared_cycle.push_back((p_cycle[i]*p_cycle[i])%10);
    }
    
    // Print cycle
    // for(int i=0; i<p_squared_cycle.size(); i++){
    //     cout<<p_squared_cycle[i]<<" ";
    // }
    // cout<<endl;
    
    return p_squared_cycle;
}

long long last_digit_sum_fibo(long long n){
    long long sum = 0;
    vector <long long> cycle = pisano_n_square_cycle(n, 10);
    
    for (int i=1; i<n+1; i++){
        sum += cycle[i];
    }
    return sum%10;
}

int main()
{
    long long n;
    cin>>n;
    n = n%60;
    cout<<last_digit_sum_fibo(n)<<endl;
    
    return 0;
}
