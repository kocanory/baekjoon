#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, k, c;
vector<int> cut;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> l >> k >> c;
    cut.assign(k, 0);

    for(int i = 0;i < k;i++) cin >> cut[i];
    cut.push_back(l);
    sort(cut.begin(), cut.end());
    cut.erase(unique(cut.begin(), cut.end()), cut.end());
    int left = 1, right = l, ans, ansf;
    while(left <= right){
        int mid = (left + right) / 2;

        int prev = l, count = c;
        bool flag = true;
        for(int i = cut.size() - 1;i >= 0;i--){
            if(prev - cut[i] > mid){
                if(cut[i + 1] - cut[i] > mid){
                    flag = false;
                    break;
                }
                count--;
                prev = cut[i + 1];
                if(count == 0) break;
            }
        }

        if(count > 0) prev = cut[0];
        if(prev > mid) flag = false;
        if(!flag) left = mid + 1;
        else{
            right = mid - 1;
            ans = mid;
            ansf = prev;
        }
    }
    cout << ans << " " << ansf << "\n";
    return 0;
}