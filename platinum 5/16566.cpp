#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k, num;
vector<int> card, parent;

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void join(int a, int b){
    a = find(a), b = find(b);
    parent[min(a, b)] = max(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    parent.assign(m, 0);
    for(int i = 0;i < m;i++) parent[i] = i;
    
    for(int i = 0;i < m;i++){
        cin >> num;
        card.push_back(num);
    }
    
    sort(card.begin(), card.end());
    
    for(int i = 0;i < k ;i++){
        cin >> num;
        int index = upper_bound(card.begin(), card.end(), num) - card.begin();
        cout << card[find(index)] << "\n";
        if(index < m - 1) join(find(index), find(index) + 1);
    }

    return 0;
}