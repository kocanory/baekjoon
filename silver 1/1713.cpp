#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, r;
vector<pair<int, int>> pic;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> r;
    
    for(int i = 0;i < r;i++){
        int s; bool flag = false;
        cin >> s;
        
        for(auto &[p, c] : pic)
            if(p == s){
                flag = true;
                c++;
                break;
            }
            
        if(!flag){
            if(pic.size() >= n){
                int minCnt = 1e9, idx;
                for(int j = 0;j < n;j++)
                    if(minCnt > pic[j].second){
                        minCnt = pic[j].second;
                        idx = j;
                    }
                pic.erase(pic.begin() + idx);
            }
            pic.push_back({s, 1});
        }
    }
    
    sort(pic.begin(), pic.end());
    for(auto [p, c] : pic)
        cout << p << " ";
        
    return 0;
}