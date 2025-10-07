#include <iostream>
#include <vector>

using namespace std;

int n, l, h, max_h, max_pos, res, lh, rh;
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n--){
        cin >> l >> h;
        arr[l] = h;
        if(h > max_h){
            max_h = h;
            max_pos = l;
        }
    }

    for(int i = 1;i < max_pos;i++){
        lh = max(lh, arr[i]);
        res += lh;
    }

    for(int i = 1000;i > max_pos;i--){
        rh = max(rh, arr[i]);
        res += rh;
    }

    cout << res + max_h;
    return 0;
}