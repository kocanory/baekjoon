#include <iostream>
#include <vector>

using namespace std;

int n, m;
string ans, word;
vector<string> arr;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    arr.assign(n, "");
    ans = string(n, 'z');

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = 0; i < n; i++) {
        word = "";
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '#') {
                if (word.size() >= 2)
                    ans = min(ans, word);
                word = "";
            }
            else word += arr[i][j];
        }
        if (word.size() >= 2)
            ans = min(ans, word);
    }

    for (int j = 0; j < m; j++) {
        word = "";
        for (int i = 0; i < n; i++) {
            if (arr[i][j] == '#') {
                if (word.size() >= 2)
                    ans = min(ans, word);
                word = "";
            }
            else word += arr[i][j];
        }
        if (word.size() >= 2)
            ans = min(ans, word);
    }
    cout << ans;
}