#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

template <typename T>

vector<size_t> sort_indexes(const vector<T> &v) {
    // https://stackoverflow.com/questions/1577475/c-sorting-and-keeping-track-of-indexes
    vector<size_t> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    stable_sort(idx.begin(), idx.end(),
       [&v](size_t i1, size_t i2) {return v[i1] > v[i2];});
    return idx;
}

double knapsack_efficient(vector<double> sort_values, vector<double> sort_weights, double W){
    long long i=0;
    double total_value=0, a;
    for(i=0; i<sort_weights.size(); i++){
        if(W == 0)
            return total_value;
            
        a = min(W, sort_weights[i]);
        total_value += a*(sort_values[i]/sort_weights[i]);
        sort_weights[i] -= a;
        W -= a;
    }
    return total_value;
}

int main()
{
    long long n;
    double W;
    cin>>n>>W;
    vector<double> values, weights;
    for(long long i=0; i<n; i++){
        int t1, t2;
        cin>>t1>>t2;
        values.push_back(t1);
        weights.push_back(t2);
    }
    // Calculate Value/weight
    vector<double> vw;
    for (long long i=0; i<n; i++){
        vw.push_back(values[i]/weights[i]);
    }
    // Sort according to vw, for all three arrays
    vector<double> sort_vw, sort_weights, sort_values;
    for (auto i: sort_indexes(vw)) {
        sort_vw.push_back(vw[i]);
        sort_values.push_back(values[i]);
        sort_weights.push_back(weights[i]);
    }
    cout<<endl;
    
    // Print sorted vectors
    // cout<<"V/W"<<"\t"<<"Val"<<"\t"<<"Weight"<<endl;
    // for (long long i=0; i<n; i++){
    //     cout<<sort_vw[i]<<"\t"<<sort_values[i]<<"\t"<<sort_weights[i]<<endl;
    // }
    
    cout<<std::fixed<<std::setprecision(4)<<knapsack_efficient(sort_values, sort_weights, W);
    
    return 0;
}
