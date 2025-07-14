#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int r, c, k, n = 3, m = 3, t = 0;
vector<vector<int>> arr(100, vector<int>(100));

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> r >> c >> k;
    
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++)
            cin >> arr[i][j];
            
    while(true){
        if(arr[r - 1][c - 1] == k){
            cout << t;
            break;
        }
        if(t > 100){
            cout << -1;
            break;
        }
        
        vector<int> size;
        
        if(n >= m){
            for(int i = 0;i < n;i++){
                map<int, int> cnt;
                vector<pair<int, int>> l;
                
                for(int j = 0;j < m;j++){
                    cnt[arr[i][j]]++;
                    arr[i][j] = 0;
                }
                    
                for(auto [key, val] : cnt)
                    if(key > 0)
                        l.push_back({val, key});
                        
                sort(l.begin(), l.end());
                
                int idx = 0;
                for(auto [val, key] : l){
                    if(idx >= 100)
                        continue;
                    arr[i][idx++] = key;
                    arr[i][idx++] = val;
                }
                size.push_back(idx);
            }
            m = *max_element(size.begin(), size.end());
        }
        else{
            for(int j = 0;j < m;j++){
                map<int, int> cnt;
                vector<pair<int, int>> l;
                
                for(int i = 0;i < n;i++){
                    cnt[arr[i][j]]++;
                    arr[i][j] = 0;
                }
                    
                for(auto [key, val] : cnt)
                    if(key > 0)
                        l.push_back({val, key});
                        
                sort(l.begin(), l.end());
                
                int idx = 0;
                for(auto [val, key] : l){
                    if(idx >= 100)
                        continue;
                    arr[idx++][j] = key;
                    arr[idx++][j] = val;
                }
                size.push_back(idx);
            }
            n = *max_element(size.begin(), size.end());
        }
        t++;
    }

    return 0;
}