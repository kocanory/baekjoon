#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

vector<long long> alpha(10);
vector<bool> nonzero(10, false);
long long answer = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        nonzero[s[0] - 'A'] = true;
        long long k = 1;
        for(int i = s.length() - 1;i >= 0;i--, k *= 10){
            alpha[s[i] - 'A'] += k;
        }
    }
    
    bool flag = false;
    for(auto a : alpha)
        if(!a) flag = true;
        
    if(!flag){
        long long Min = LLONG_MAX;
        int idx;
        for(int i = 0;i < 10;i++){
            if(!nonzero[i] && alpha[i] < Min){
                Min = alpha[i];
                idx = i;
            }
        }
        alpha[idx] = 0;
    }
    sort(alpha.begin(), alpha.end(), greater<long long>());
    for(int i = 0, j = 9;i < 10;i++, j--){
        answer += alpha[i] * j;
    }
    cout << answer << "\n";
    return 0;
}