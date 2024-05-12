#include <iostream>
#include <vector>

using namespace std;

int n;
vector<pair<int, int>> arr;
long double answer = 0;

long double solve(int i, int j){
    long double a = arr[0].first, b = arr[0].second;
    long double c = arr[i].first, d = arr[i].second;
    long double e = arr[j].first, f = arr[j].second;
    return (a * d + c * f + e * b - c * b - e * d - a * f) / 2;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++){
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    
    for(int i = 1;i < n - 1;i++) answer += solve(i, i + 1);
    
    cout << fixed;
    cout.precision(1);
    cout << abs(answer) << "\n";
    return 0;
}