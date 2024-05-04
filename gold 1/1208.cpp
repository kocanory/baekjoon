#include <iostream>
#include <vector>
#include <map>

using namespace std;

int n, s;
long long result = 0;
vector<int> arr;
map<long long, int> total;

void leftSeq(int st, int sum){
    if(st == n / 2){
        total[sum]++;
        return;
    }
    leftSeq(st + 1, sum);
    leftSeq(st + 1, sum + arr[st]);
}

void rightSeq(int mid, int sum){
    if(mid == n){
        result += total[s - sum];
        return;
    }
    rightSeq(mid + 1, sum);
    rightSeq(mid + 1, sum + arr[mid]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> s;
    
    arr.assign(n, 0);
    for(int i = 0;i < n;i++) cin >> arr[i];
    
    leftSeq(0, 0);
    rightSeq(n / 2, 0);
    
    cout << ((s == 0) ? result -1 : result) << "\n";
    return 0;
}