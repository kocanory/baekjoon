#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int cnt = 0;
string name;
map<string, int> check;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (getline(cin, name)) {
        check[name]++;
        cnt++;
    }

    for (auto [k, v] : check)
        printf("%s %.4f\n", k.c_str(), v / double(cnt) * 100);
    
    return 0;
}