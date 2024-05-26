#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<pair<int, int>> arr;
vector<int>lis, index, answer;
set<int> poll;


void LIS(){
    int size = 0;
    for(auto a : arr){
        if(lis.empty() || a.second > lis.back()){
            lis.push_back(a.second);
            index.push_back(size++);
        }
        else{
            auto pos = lower_bound(lis.begin(), lis.end(), a.second);
            *pos = a.second;
            index.push_back(distance(lis.begin(), pos));
        }
    }
}

void backtrack(int size){
    if(size < 0) return;
    int now = index.back();
    if(size == now){
        answer.push_back(arr[index.size() - 1].first);
        index.pop_back();
        backtrack(size - 1);
    }
    else{
        index.pop_back();
        backtrack(size);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++){
        int a, b;
        cin >> a >> b;
        poll.insert(a);
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end());

    LIS();
    
    backtrack(lis.size() - 1);

    for(auto a : answer) poll.erase(a);

    cout << poll.size() << "\n";
    for(auto p : poll) cout << p << "\n";

    return 0;
}
