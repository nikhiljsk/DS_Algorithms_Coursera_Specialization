#include <iostream>

using namespace std;

int cal_stop_points(int d, int m, int n, int *arr){
    int currR=0, count=0;
    while(currR <= n){
        int prevR = currR;
        if(d<=m)
            return 0;
        while (currR<=n && (arr[currR+1]-arr[prevR]) <= m)
            currR += 1;
        // cout<<currR<<prevR<<"here"<<endl;
        if(currR == n-1)
            return count;
        if(currR == prevR)
            return -1;
        if(currR <= n)
            count += 1;
    }
    return count;
}

int main()
{
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
