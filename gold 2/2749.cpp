#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
long long n;

matrix a = {{1, 1}, {1, 0}}, answer = {{1, 0}, {0, 1}};

matrix operator*(matrix &a, matrix &b){
    int size = a.size();
    matrix ret(size, vector<long long>(size, 0));

    for(int i = 0;i < size;i++){
        for(int j = 0;j < size;j++){
            for(int k = 0;k < size;k++){
                ret[i][j] += (a[i][k] * b[k][j]);
            }
            ret[i][j] %= 1000000;
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while(n){
        if(n % 2) answer = answer * a;
        a = a * a;
        n /= 2;
    }
    cout << answer[0][1] << "\n";
    return 0;
}