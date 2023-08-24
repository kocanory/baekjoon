#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

bool comp(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

int main()
{
    int n, answer = 0;
    vector<vector<int>> arr;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    cin.ignore();
    for(int i = 0;i < n;i++)
    {
        vector<int> temp;
        for(int j = 0;j<3;j++)
        {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        arr.push_back(temp);
    }
    
    sort(arr.begin(), arr.end(), comp);
    
    for(auto a : arr)
    {
        while(!pq.empty() && pq.top() <= a[1])
            pq.pop();
        pq.push(a[2]);
        answer = max(answer, (int)pq.size());
    }
    cout << answer << endl;
    return 0;
}