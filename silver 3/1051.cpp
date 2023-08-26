#include <iostream>
#include <vector>

using namespace std;

vector<string> arr;
int answer = 0, max_size;
void recursive(int x, int y, int size)
{
    if(size > max_size) return;
    if(x + size - 1 >= arr.size() || y + size - 1 >= arr[0].length())
        return;
    if(arr[x][y] == arr[x][y + size - 1] && arr[x][y] == arr[x + size - 1][y] && arr[x][y] == arr[x + size - 1][y + size - 1])
        answer = max(answer, size * size);
    recursive(x, y, size + 1);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0;i<n;i++)
    {
        string temp;
        cin >> temp;
        arr.push_back(temp);
    }
    max_size = min(n, m);
    if(max_size == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0;i<n;i++)
        for(int j =0;j<m;j++)
            recursive(i, j, 1);
    cout << answer << endl;
    return 0;
}