#include <iostream>
#include <cstring>

using namespace std;
int n, answer_bit;
int map[16][16];
int cost[16][1 << 16]; //자리 탐색한 각 경우 별로 cost 계산
int dfs(int cur_node, int cur_bit)
{
    if(cur_bit == answer_bit) //모든 자리를 탐색하고 출발 자리에 돌아올 경우
    {
        if(map[cur_node][0] == 0) return 1e9; 
        return map[cur_node][0];
    }
    if(cost[cur_node][cur_bit] != -1) return cost[cur_node][cur_bit]; //값이 이미 있으면 그대로 사용
    cost[cur_node][cur_bit] = 1e9;
    for(int i =0;i < n;i++)
    {
        if(map[cur_node][i] == 0) continue;             //현재와 동일한 자리 탐색할 경우
        if((cur_bit & (1 << i)) == (1 << i)) continue;  //방문했던 자리에 다시 탐색할 경우
        cost[cur_node][cur_bit] = min(cost[cur_node][cur_bit], map[cur_node][i] + dfs(i, cur_bit | (1 << i)));
        //현재 자리에서 다음 자리로 이동 후 다음 자리에서 탐색한 값을 더해 나간다.
    }
    return cost[cur_node][cur_bit];
}

int main()
{
    cin >> n;
    answer_bit = (1 << n) - 1;
    memset(cost, -1, sizeof(cost));
    for(int i = 0;i < n;i++)
        for(int j = 0;j < n;j++)
            cin >> map[i][j];
    
    cout << dfs(0, 1) << endl;
    return 0;
}