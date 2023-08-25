#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c, n;
    cin >> c >> n;
    vector<int> dp(c + 100);
    vector<pair<int, int>> info;
    fill(dp.begin(), dp.end(), 1e9);
    for(int i = 0;i<n;i++)
    {
        int cost, income;
        cin >> cost >> income;
        info.push_back({cost, income});
        dp[income] = min(dp[income], cost);
    }
    for(int i = 1;i<c + 100;i++)
    {
        for(auto a : info)
            if(i - a.second)
                dp[i] = min(dp[i - a.second] + dp[a.second], dp[i]);
    }
    
    int answer = 1e9;
    for(int i = c;i<c+100;i++)
        answer = min(answer, dp[i]);
    cout << answer << endl;
    return 0;
}