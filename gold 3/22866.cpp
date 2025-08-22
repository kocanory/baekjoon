#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> arr, s, l, r;
vector<pair<int, int>> dist;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr = vector<int>(n + 1);
    s = vector<int>(n + 1);
    dist = vector<pair<int, int>>(n + 1);

    for(int i = 1; i <= n; i++) cin >> arr[i];

    for (int i = 2;i <= n;i++) {
        if (arr[i - 1] > arr[i]) l.push_back(i - 1);
        else {
            while (!l.empty() && arr[i] >= arr[l.back()]) l.pop_back();
        }
        s[i] += l.size();
        if (!l.empty()) dist[i].first = l.back();
    }

    for (int i = n - 1; i >= 1; i--) {
        if (arr[i + 1] > arr[i]) r.push_back(i + 1);
        else {
            while (!r.empty() && arr[i] >= arr[r.back()]) r.pop_back();
        }
        s[i] += r.size();
        if (!r.empty()) dist[i].second = r.back();
    }

    for (int i = 1;i <= n;i++) {
        cout << s[i] << " ";
        if (s[i]) {
            if (!dist[i].first) cout << dist[i].second;
            else if (!dist[i].second) cout << dist[i].first;
            else {
                if ((i - dist[i].first) <= (dist[i].second - i)) cout << dist[i].first;
                else cout << dist[i].second;
            }
        }
        cout << "\n";
    }
}