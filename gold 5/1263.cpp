#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

int main()
{
    int n;
    vector<pair<int, int>> arr;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        int p, e;
        cin >> p >> e;
        arr.push_back({p, e});
    }
    sort(arr.begin(), arr.end(), comp);
    int s = arr[0].second - arr[0].first;
    for(int i = 1;i<n;i++)
    {
        if(s > arr[i].second)
            s = (arr[i].second - arr[i].first);
        else
            s -= arr[i].first;
    }
    if(s < 0)
        cout << -1 << endl;
    else
        cout << s << endl;
    return 0;
}
