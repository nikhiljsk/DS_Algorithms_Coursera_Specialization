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

long long fast_fibo_n(long long n, long long m){
    long long p, temp;
    
    vector <long long> p_cycle = pisano(m);
    // Remove last 2 elements 0 and i-1
    p_cycle.pop_back();
    p_cycle.pop_back();
    p_cycle.pop_back();
    
    // Print cycle
    // for(int i=0; i<p_cycle.size(); i++){
    //     cout<<p_cycle[i]<<" ";
    // }
    // cout<<endl;
    
    p = p_cycle.size();
    // cout<<"Cycle count:"<<p<<endl;
    
    temp = n%p;
    // cout<<"Fibo_n"<<p_cycle[temp]<<endl;
    
    return p_cycle[temp];
}

int main()
{
    long long n;
    cin>>n;
    cout<<(fast_fibo_n(n+2, 10) -1 +10)%10<<endl;
    return 0;
}
