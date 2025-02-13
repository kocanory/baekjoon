#include <iostream>
#include <cmath>

using namespace std;

int n;

void hanoi(int cnt, int start, int mid, int end){
    if(cnt == 1){
        cout << start << " " << end << "\n";
        return;
    }
    hanoi(cnt - 1, start, end, mid);
    cout << start << " " << end << "\n";
    hanoi(cnt - 1, mid, start, end);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    string num = to_string(pow(2, n));
    num = num.substr(0, num.find('.'));
    num[num.length() - 1] -= 1;
    cout << num << "\n";
    
    if(n <= 20) hanoi(n, 1, 2, 3);
    return 0;
}