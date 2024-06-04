#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, num;
vector<int> card, parent;

int findParent(int i){
    if(parent[i] == i) return i;
    return parent[i] = findParent(parent[i]);
}

void join(int a, int b){
    a = findParent(a), b = findParent(b);
    parent[min(a, b)] = max(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    parent.assign(m + 1, 0);
    for(int i = 0;i < m;i++) parent[i] = i;

    for(int i = 0;i < m;i++){
        cin >> num;
        card.push_back(num);
    }

    sort(card.begin(), card.end());


    for(int i = 0;i < k;i++){
        cin >> num;
        int index = upper_bound(card.begin(), card.end(), num) - card.begin();
        cout << card[findParent(index)] << "\n";
        join(findParent(index), findParent(index) + 1);
    }
    return 0;
}