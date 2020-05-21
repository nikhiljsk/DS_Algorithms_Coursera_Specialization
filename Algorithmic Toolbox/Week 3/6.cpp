#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n, i=1;
    cin>>n;
    long long count = 0;
    vector<int> store;
    
    while(count<=n){
        if ((count + i) <= n){
            store.push_back(i);
            count += i;
        }
        else{
            break;
        }
        i++;
    }
    int len = store.size();
    store.at(len-1) = store.at(len-1) + (n-count);
    
    cout<<len<<endl;
    for(int i=0; i<len; i++)
        cout<<store[i]<<" ";
    
    return 0;
}