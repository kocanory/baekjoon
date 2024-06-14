#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int n;
vector<int> arr;
unordered_map<int, int> score, cards;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) {
        cin >> arr[i];
        cards[arr[i]] = 1;
    }
    
    for(auto &a : arr){
        for(int i = 2 * a;i <= 1000000;i += a){
            if(cards[i]){
                score[a]++;
                score[i]--;
            }
        }
    }
    
    for(auto &a : arr) cout << score[a] << " ";
    return 0;
}