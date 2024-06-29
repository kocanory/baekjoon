#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n, f;
string f1, f2;
vector<int> parent, s;

int find(int i){
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

int join(int a, int b){
    a = find(a), b = find(b);
    if(a != b){
        parent[max(a, b)] = min(a, b);
        s[min(a, b)] += s[max(a, b)];
    }
    return s[min(a, b)];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n--){
        cin >> f;
        unordered_map<string, int> index;
        int count = 0;
        parent.assign(200000 + 1, 0);
        s.assign(200000 + 1, 1);

        for(int i = 1;i <= 200000;i++) parent[i] = i;
        while(f--) {
            cin >> f1 >> f2;
            if(index.count(f1) == 0) index[f1] = ++count;
            if(index.count(f2) == 0) index[f2] = ++count;
            cout << join(index[f1], index[f2]) << "\n";
        }
    }
    return 0;
}