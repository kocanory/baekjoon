#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0, num;i < n * n;i++) {
        cin >> num;
        pq.push(-num);
        if (pq.size() > n)
            pq.pop();
    }

    cout << -pq.top();
    return 0;
}