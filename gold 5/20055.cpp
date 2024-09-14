#include <iostream>
#include <deque>

using namespace std;

int n, k;
int cnt = 0, stage = 0;
deque<int> belt, A;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for(int i = 0;i < 2 * n;i++) {
        int num;
        cin >> num;
        A.push_back(num);
        belt.push_back(0);
    }

    while(true) {
        stage++;
        A.push_front(A.back());
        A.pop_back();
        belt.push_front(belt.back());
        belt.pop_back();

        if(belt[n - 1]) belt[n - 1] = 0;

        for(int i = 2 * n;i >= 0;i--) {
            if(belt[i] && A[i + 1] && !belt[i + 1]) {
                belt[i + 1] = 1;
                belt[i] = 0;
                A[i + 1]--;
            }
            if(belt[n - 1]) belt[n - 1] = 0;
        }
        if(A[0] && !belt[0]) {
            belt[0] = 1;
            A[0]--;
        }
        cnt = 0;
        for(int i = 0;i < 2 * n;i++) {
            if(!A[i]) cnt++;
        }
        if(cnt >= k) {
            cout << stage << "\n";
            break;
        }
    }
    return 0;
}