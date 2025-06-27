#include <iostream>
#include <map>

using namespace std;

string a, b;
map<char, int> romeNum = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int convertToNum(string rom){
    int res = 0;
    for(int i = 0;i < rom.size();i++){
        if(i + 1 != rom.size() && romeNum[rom[i]] < romeNum[rom[i + 1]]) res -= romeNum[rom[i]];
        else res += romeNum[rom[i]];
    }
    return res;
}

string convertToRom(int num){
    string res = "";
    int digit;
    
    while(num){
        if(num / 1000){
            digit = num / 1000;
            while(digit--) res += 'M';
            num %= 1000;
        }
        else if(num / 100){
            digit = num / 100;
            if(digit == 9) res += "CM";
            else if(digit == 4) res += "CD";
            else{
                if(digit >= 5){
                    res += 'D';
                    digit -= 5;
                }
                while(digit--) res += 'C';
            }
            num %= 100;
        }
        else if(num / 10){
            digit = num / 10;
            if(digit == 9) res += "XC";
            else if(digit == 4) res += "XL";
            else{
                if(digit >= 5){
                    res += 'L';
                    digit -= 5;
                }
                while(digit--) res += 'X';
            }
            num %= 10;
        }
        else{
            digit = num;
            if(digit == 9) res += "IX";
            else if(digit == 4) res += "IV";
            else{
                if(digit >= 5){
                    res += 'V';
                    digit -= 5;
                    }
                while(digit--) res += 'I';
            }
            num /= 10;
        }
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> a >> b;
    int sum = convertToNum(a) + convertToNum(b);
    cout << sum << "\n" << convertToRom(sum);
    return 0;
}