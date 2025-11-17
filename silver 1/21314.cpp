#include <iostream>
#include <vector>

using namespace std;

string n;

string findMax(){
    string tmp;
    vector<char> st;

    for(auto c : n){
        if (st.empty()) {
            if(c == 'M') st.push_back(c);
            else tmp += '5';
        }
        else{
            if(c == 'M') st.push_back(c);
            else{
                tmp += '5' + string(st.size(), '0');
                st.clear();
            }
        }
    }
    if(!st.empty())
        tmp += string(st.size(), '1');
    return tmp;
}

string findMin(){
    string tmp;
    vector<char> st;

    for(auto c : n){
        if(c == 'M') st.push_back(c);
        else{
            if(!st.empty()){
                tmp += '1' + string(st.size() - 1, '0');
                st.clear();
            }
            tmp += '5';
        }
    }
    if(!st.empty())
        tmp += '1' + string(st.size() - 1, '0');
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cout << findMax() << "\n" << findMin();

    return 0;
}