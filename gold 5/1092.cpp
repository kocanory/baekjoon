#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
bool comp(pair<int, queue<int>>a, pair<int, queue<int>> b)
{
    return a.first > b.first;
}

int main()
{
    int n, m;
    vector<pair<int, queue<int>>> cr;
    vector<int> arr;
    cin >> n;
    for(int i = 0;i<n;i++)
    {
        int input;
        cin >> input;
        queue<int> q = {};
        cr.push_back({input, q});
    }
    cin >> m;
    for(int i = 0;i<m;i++)
    {
        int input;
        cin >> input;
        arr.push_back(input);
    }
    sort(cr.begin(), cr.end(), comp);
    sort(arr.begin(), arr.end(), greater<int>());
    
    if(cr[0].first < arr[0])
    {
        cout << -1 << endl;
        return 0;
    }
    
    for(auto & c : cr)
    {
        for(int i = 0;i<arr.size();i++)
        {
            if(c.first >= arr[i])
                c.second.push(i);
        }
    }
    
    int cnt = 0;
    int moved = 0;
    while(true)
    {
        for(auto &c : cr)
        {
            while(!c.second.empty())
            {
                if(arr[c.second.front()])
                {
                    arr[c.second.front()] = 0;
                    c.second.pop();
                    moved++;
                    break;
                }
                c.second.pop();
            }
        }
        cnt++;
        if(moved >= m)
            break;
    }
    cout << cnt << endl;
    return 0;
}