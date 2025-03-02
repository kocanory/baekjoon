#include <iostream>

using namespace std;

int t;
string s;

int is_palindrome(int left, int right, int del){
    while(left < right){
        if(s[left] != s[right]){
            if(!del){
                if(!is_palindrome(left + 1, right, 1) || !is_palindrome(left, right - 1, 1)) return 1;
                return 2;
            }
            return 2;
        }
        left++;
        right--;
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> t;
    while(t--){
        cin >> s;
        cout << is_palindrome(0, s.length() - 1, 0) << "\n";
    }
    return 0;
}