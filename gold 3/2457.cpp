#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef pair<int, int> pii;

int n, cur = 0, ans = 1;
vector<pii> arr;
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

int conv(int month, int date){
    return accumulate(day, day + month, 0) + date;
}

bool comp(pii a, pii b){
    return a.second > b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    for(int i = 0;i < n;i++){
        int m1, d1, m2, d2;
        cin >> m1 >> d1 >> m2 >> d2;
        arr.push_back({conv(m1, d1), conv(m2, d2)});
    }
    
    sort(arr.begin(), arr.end(), comp);
    if(arr[0].second <= conv(11, 30)){
        cout << 0;
        return 0;
    }
    
    sort(arr.begin(), arr.end());
    if(arr[0].first > conv(3, 1)){
        cout << 0;
        return 0;
    }
    
    for(int i = 1;i < n;i++){
        if(arr[i].first <= conv(3, 1) && arr[cur].second < arr[i].second)
            cur = i;
    }
    
    while(true){
        if(arr[cur].second > conv(11, 30)) break;
        
        pii l = {1, 1};
        int idx = -1;
        
        for(int i = cur + 1;i < n;i++){
            if(arr[i].first <= arr[cur].second && arr[i].second > l.second){
                l = arr[i];
                idx = i;
            }
        }
        
        if(idx == -1){
            cout << 0;
            return 0;
        }
        ans++;
        cur = idx;
    }
    cout << ans;
    return 0;
}