#include <iostream>
#include <queue>
#include <map>

using namespace std;

int t, n;
priority_queue<int, vector<int>, greater<int>> min_pq;
priority_queue<int> max_pq;
map<int, int> cnt;

void insert(int num){
    max_pq.push(num);
    min_pq.push(num);
    cnt[num]++;
}

void deleteMax(){
    if(!max_pq.empty()) {
        cnt[max_pq.top()]--;
        max_pq.pop();
    }
}

void deleteMin(){
    if(!min_pq.empty()) {
        cnt[min_pq.top()]--;
        min_pq.pop();
    }
}

void clearPqs(){
    while(!min_pq.empty() && cnt[min_pq.top()] == 0) min_pq.pop();
    while(!max_pq.empty() && cnt[max_pq.top()] == 0) max_pq.pop();
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        priority_queue<int> temp1;
        max_pq = temp1;
        priority_queue<int, vector<int>, greater<int>> temp2;
        min_pq = temp2;
        cnt.clear();
        char cmd;
        int num;
        for(int i = 0;i < n;i++){
            cin >> cmd >> num;
            if(cmd == 'I') insert(num);
            else{
                if(num == 1) deleteMax();
                else deleteMin();
                clearPqs();
            }
        }
        clearPqs();
        if(max_pq.empty() || min_pq.empty()) cout << "EMPTY\n";
        else cout << max_pq.top() << " " << min_pq.top() << "\n";
    }
    return 0;
}