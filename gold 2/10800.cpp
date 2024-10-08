#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ball {
    int weight, color, idx;
};

bool comp(ball &a, ball &b) {
    if(a.weight == b.weight) return a.color < b.color;
    return a.weight < b.weight;
}

int n, sum = 0;
vector<ball> arr;
vector<int> c(200001), s(200001), ans(200001);

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0;i < n;i++) {
        int weight, color;
        cin >> color >> weight;
        arr.push_back({weight, color, i});
    }
    sort(arr.begin(), arr.end(), comp);

    for(int i = 0;i < n;i++) {
        auto[weight, color, idx] = arr[i];
        c[color] += weight;
        s[weight] += weight;
        sum += weight;

        ans[idx] = sum - c[color] - s[weight] + weight;
        if(i != 0 && (arr[i - 1].color == color) && (arr[i - 1].weight == weight))
            ans[idx] = ans[arr[i - 1].idx];
    }
    for(int i = 0;i < n;i++)
        cout << ans[i] << "\n";
    return 0;
}