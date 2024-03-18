#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct decimal36{
    long cipher[60] = {0,};
    int maxDigit = 0;
    
    bool operator<(const decimal36 &t) const{
        if(maxDigit != t.maxDigit) return maxDigit < t.maxDigit;
        for(int i = maxDigit;i >= 0;i--)
            if(cipher[i] != t.cipher[i])
                return cipher[i] < t.cipher[i];
        return false;
    }
};

priority_queue<decimal36> decQueue;

decimal36 byCipher[36];
decimal36 total;

void arrangeCipher(decimal36 &de){
    for(int i = 0;i < 60;i++){
        if(de.cipher[i] > 0){
            de.maxDigit = i;
            if(de.cipher[i] > 35){
                de.cipher[i + 1] += (int)(de.cipher[i] / 36);
                de.cipher[i] = de.cipher[i] % 36;
            }
        }
    }
}

int charTode(char c){
    if(c >= '0' && c <= '9') return c - '0';
    else return c - 'A' + 10;
}

char cipherTochar(int i){
    if(i < 10)
        return (char)(i + '0');
    else
        return (char)(i + 'A' - 10);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    while(n--){
        string s;
        cin >> s;
        if(s.length() == 1 && s[0] == '0') continue;
        for(int i = 0;i < s.length();i++){
            int target = charTode(s[i]);
            byCipher[target].cipher[s.length() - i - 1] += (35 - target);
            total.cipher[s.length() - i - 1] += target;
        }
    }
    
    for(int i = 0;i < 36;i++){
        arrangeCipher(byCipher[i]);
        decQueue.push(byCipher[i]);
    }
    
    int k;
    cin >> k;
    
    for(int i = 0;i < k;i++){
        decimal36 temp = decQueue.top();
        for(int j = 0;j < 60;j++)
            total.cipher[j] = temp.cipher[j] + total.cipher[j];
        decQueue.pop();
    }
    arrangeCipher(total);
    for(int i = total.maxDigit;i >= 0;i--)
        cout << cipherTochar(total.cipher[i]);
    return 0;
}