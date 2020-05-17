#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

long long MaxPairwiseProduct(const vector<int> &numbers) {
    long long result = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long) (numbers[i])) * numbers[j] > result) {
                result = ((long long) (numbers[i])) * numbers[j];
            }
        }
    }
    return result;
}

long long maxProduct(vector <int> a){
    int max1=-1, max2=-1;
    for (int i=0; i<a.size(); i++){
        if(a[i]>a[max1]){
            // cout<<"Enter max"<<i<<a[i]<<max1<<endl;
            max1 = i;
        }
    }
    for (int i=0; i<a.size(); i++){
        if (a[i]>a[max2] && i!=max1){
            max2 = i;
        }
    }
    return ((long long) a[max1]*a[max2]);
}

int main(){
    // while (true) {
    //   int n = rand() % 4 + 2;
    //   cout << n << "\n";
    //   vector<int> a;
    //   for (int i = 0; i < n; ++i) {
    //     a.push_back(rand() % 10);
    //   }
    //   for (int i = 0; i < n; ++i) {
    //     cout << a[i] << ' ';
    //   }
    //   cout << "\n";
    //   long long res1 = MaxPairwiseProduct(a);
    //   long long res2 = maxProduct(a);
    //   if (res1 != res2) {
    //     cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
    //     break;
    //   }
    //   else {
    //     cout << "OK\n";
    //   }
    // }
    
    
    long n;
    cin>>n;
    vector <int> a(n);
    for (long long i=0; i<n; i++){
        cin>>a[i];
    }
    cout<<maxProduct(a);
    return 0;
}