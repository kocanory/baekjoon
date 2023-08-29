#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    
    string input;
    getline(cin, input);
    
    stringstream ss(input);
    string temp = "";
    vector<long long> arr;
    while(getline(ss, temp, ' '))
        arr.push_back(stol(temp));
    
    if(arr[0] == 1)
    {
        long long count = arr[1] - 1;
        vector<int> f;
        for(int i = 1;i<=n;i++)
            f.push_back(i);
            
        long long fact = 1;
        for(int i = 1;i<=n;i++)
            fact *= i;
            
        vector<int>answer;
        long long mod, div;
        while(f.size() > 1)
        {
            fact /= n;
            mod = count % fact;
            div = count / fact;
            answer.push_back(f[div]);
            f.erase(f.begin() + div);
            count = mod;
            n--;
        }
        answer.push_back(f[0]);
        for(auto a : answer)
            cout << a << " ";
    }
    else
    {
        long long answer = 0;
        long long fact = 1;
        for(int i = 1;i<=n;i++)
            fact *= i;
        
        vector<int> f;
        for(int i = 1;i<=n;i++)
            f.push_back(i);
            
        for(int i = 1;i<arr.size();i++)
        {
            int j = 0;
            for(j;j<f.size();j++)
            {
                if(arr[i] == f[j])
                    break;
            }
            fact /= n;
            answer += (j * fact);
            f.erase(f.begin() + j);
            n--;
        }
        cout << answer + 1 << endl;
    }

    return 0;
}