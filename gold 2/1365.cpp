#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int> answer;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1;i <= n;i++){
        int m;
        cin >> m;
        arr.push_back({i, m});
    }
    sort(arr.begin(), arr.end(), comp);

    for(auto &a : arr){
        if(answer.empty() || answer.back() < a.first) answer.push_back(a.first);
        else{
            auto pos = lower_bound(answer.begin(), answer.end(), a.first);
            *pos = a.first;
        }
    }
    cout << n - answer.size() << "\n";
    return 0;
}