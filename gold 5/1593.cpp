#include <iostream>
#include <unordered_map>

using namespace std;
unordered_map<char, int> m1, m2;

int main()
{
    int n, m, answer = 0;
    cin >> n >> m;
    string w, s;
    cin >> w;
    cin >> s;
    for(auto a : w)
        m1[a]++;
    bool ch = true;
    for(int i = 0;i<n;i++)
    {
        if(m1.find(s[i])!=m1.end()) m1[s[i]]--;
        else m2[s[i]]++;
    }
    for(auto [k, v] : m1)
        if(v != 0)
        {
            ch = false;
            break;
        }

    if(ch)
    {
        for(auto [k, v] : m2)
            if(v != 0)
            {
                ch = false;
                break;
            }
    }
    if(ch) answer++;
    int left = 0, right = n - 1;
    while(n < m && right < m)
    {
        ch = true;
        if(m1.find(s[left]) != m1.end()) m1[s[left]]++;
        else m2[s[left]]--;
        left++;
        right++;
        if(m1.find(s[right]) != m1.end()) m1[s[right]]--;
        else m2[s[right]]++;
        for(auto [k, v] : m1)
            if(v != 0)
            {
                ch = false;
                break;
            }

        if(ch)
        {
            for(auto [k, v] : m2)
                if(v != 0)
                {
                    ch = false;
                    break;
                }
        }
        if(ch) answer++;
    }
    cout << answer << endl;
    return 0;
}