#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, num, cnt = 1;
queue<int> now;
vector<int> wait;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--) {
        cin >> num;
        now.push(num);
    }

    while (true) {
        if (!now.empty() && now.front() == cnt) {
            now.pop();
            cnt++;
        }
        else if (!wait.empty() && wait.back() == cnt) {
            wait.pop_back();
            cnt++;
        }
        else {
            if (now.empty()) break;
            wait.push_back(now.front());
            now.pop();
        }
    }

    cout << (wait.empty() ? "Nice" : "Sad");
    return 0;
}