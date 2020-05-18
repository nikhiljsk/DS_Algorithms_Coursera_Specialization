#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int cal_stop_points(int d, int m, int n, int *arr){
    int currPos = 0, prevPos = 0, refillCount = 0;
    while(currPos < n){
        while((currPos < n-1) && (arr[currPos+1]-arr[prevPos])<=m)
            currPos += 1;
        
        if(currPos == n-1)
            return refillCount;

        if(currPos < n)
            refillCount += 1;
            
        if(currPos==prevPos)
            return -1;
        
        prevPos = currPos;
        
    }
    return -1;
}


int main() {
    int d, m, n, i;
    cin>>d>>m>>n;
    int arr[n+2];
    arr[0] = 0;
    for(i=1; i<=n; i++)
        cin>>arr[i];
    arr[n+1] = d;
    cout<<cal_stop_points(d, m, n+2, arr);

    return 0;
}
