#include <iostream>
#include <map>

using namespace std;

int n, cnt, ans = 0;
string first, word;
map<char, int> check, ccheck;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> first;
    for (char f : first) check[f]++;

    for (int i = 0;i < n - 1;i++) {
        cin >> word;
        ccheck = check;
        cnt = 0;
        for (char w : word)
            if (ccheck[w]) {
                ccheck[w]--;
                cnt++;
            }

        if (first.size() == word.size()) {
            if (cnt == first.size() || cnt == first.size() - 1)
                ans++;
        }
        else if (word.size() == first.size() - 1 && cnt == first.size() - 1)
            ans++;
        else if (word.size() == first.size() + 1 && cnt == first.size())
            ans++;
    }
    cout << ans;
}