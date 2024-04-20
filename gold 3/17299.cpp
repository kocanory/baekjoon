#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> num, f(1000001), st, answer;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    num.assign(n, 0);
    answer.assign(n, 0);
    for(int i = 0;i < n;i++){
        cin >> num[i];
        f[num[i]]++;
    }
    
    for(int i = n - 1;i >= 0;i--){
        int n = num[i], count = f[n];
        while(!st.empty()){
            int top = num[st.back()], topCnt = f[top];
            if(count >= topCnt) st.pop_back();
            else break;
        }
        answer[i] = -1;
        if(!st.empty()) answer[i] = num[st.back()];
        st.push_back(i);
    }
    for(auto a : answer)
        cout << a << " ";
    return 0;
}