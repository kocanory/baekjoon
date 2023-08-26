#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int l, r, k, answer = 0;
    cin >> l >> r >> k;
    switch(k)
    {
        case 2:
            answer = max(r - max(l, 3) + 1, 0);
            break;
        case 3:
            for(int i = 6;i<=r;i += 3)
                if(i >= l)
                    answer++;
            break;
        case 4:
            for(int i = 10;i<=r;i += 2)
            {
                if(i == 12)
                    continue;
                if(i >= l)
                    answer++;
            }
            break;
        case 5:
            for(int i = 15;i<=r;i+=5)
                if(i >= l)
                    answer++;
    }
    cout << answer << endl;
}