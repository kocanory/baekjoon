#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, answer, trace;

void backtrace(int size){
    if(size == 0) return;
    int cur = trace.back();
    if(cur == size - 1){
        int idx = trace.size()-1;
        trace.pop_back();
        backtrace(size - 1);
        cout << arr[idx] << " ";
    }
    else{
        trace.pop_back();
        backtrace(size);
    }
}

void LIS(){
    int idx = 0;
    for(auto &a : arr){
        if(answer.empty() || answer.back() < a) {
            answer.push_back(a);
            trace.push_back(idx++);
        }
        else{
            auto pos = lower_bound(answer.begin(), answer.end(), a);
            *pos = a;
            trace.push_back(distance(answer.begin(), pos));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    LIS();

    int size = answer.size();
    cout << size << "\n";
    backtrace(size);
    return 0;
}