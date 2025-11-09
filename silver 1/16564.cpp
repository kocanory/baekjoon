#include <iostream>
#include <vector>

using namespace std;

int n, k, l = 1, r = 1e9 + 1;
vector<int> arr;

bool search(int mid){
    long long sum = 0;
    for(auto a : arr)
        sum += max(0, mid - a);
    return sum <= k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    arr.assign(n, 0);

    for(auto &a : arr) cin >> a;

    while(l <= r){
        int mid = (l + r) / 2;
        if (search(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << r;
    return 0;
}