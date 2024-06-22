#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr, answer;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(auto  &a : arr) cin >> a;
    
    for(auto &a : arr){
        if(answer.empty() || answer.back() < a) answer.push_back(a);
        else{
            auto pos = lower_bound(answer.begin(), answer.end(), a);
            *pos = a;
        }
    }
    cout << answer.size() << "\n";
    return 0;
}