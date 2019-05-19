// baekjoon problem / 2931
// °¡½º°ü

#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
 
#define endl "\n"
#define MAX 26
using namespace std;
 
typedef struct
{
    int x;
    int y;
    int dir;
}Gas;
 
int R, C, Pipe_Cnt, Temp_Pipe_Cnt;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
char Pipe[] = { '|', '-', '+', '1', '2', '3', '4' };
bool Pipe_Num[8];
 
pair<int, int> Start, End;
vector<pair<int, int>> Pipe_Pos;
 
void Input()
{
    cin >> R >> C;
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            cin >> MAP[i][j];
            if (MAP[i][j] == 'M')
            {
                Start.first = i;
                Start.second = j;
            }
 
            if (MAP[i][j] != 'M' && MAP[i][j] != 'Z' && MAP[i][j] != '.')
            {
                Pipe_Pos.push_back(make_pair(i, j));
            }
        }
    }
}
 
int Set_Direct(int dir, char C)
{
    int nd = -1;
    if (C == '|')
    {
        if (dir == 2 || dir == 3) nd = dir;
    }
    else if (C == '-')
    {
        if (dir == 0 || dir == 1) nd = dir;
    }
    else if (C == '+') nd = dir;
    else if (C == '1')
    {
        if (dir == 3) nd = 0;
        else if (dir == 1) nd = 2;
    }
    else if (C == '2')
    {
        if (dir == 2) nd = 0;
        else if (dir == 1) nd = 3;
    }
    else if (C == '3')
    {
        if (dir == 0) nd = 3;
        else if (dir == 2) nd = 1;
    }
    else if (C == '4')
    {
        if (dir == 0) nd = 2;
        else if (dir == 3) nd = 1;
    }
 
    return nd;
}
 
bool Can_Use_All_Pipe()
{
    for (int i = 0; i < Pipe_Pos.size(); i++)
    {
        int x = Pipe_Pos[i].first;
        int y = Pipe_Pos[i].second;
        
        if (Visit[x][y] == false) return false;
    }
    return true;
}
 
pair<int, int> BFS()
{
    queue<Gas> Q;
    Gas Start_Gas = { Start.first, Start.second, 0 };
    Q.push(Start_Gas);
 
    int nx, ny;
    bool Answer = false;
 
    while (Q.empty() == 0)
    {
        if (Answer == true) break;
        int x = Q.front().x;
        int y = Q.front().y;
        int dir = Q.front().dir;
        Q.pop();
 
        if (MAP[x][y] == 'M')
        {
            for (int i = 0; i < 4; i++)
            {
                nx = x + dx[i];
                ny = y + dy[i];
 
                if (nx >= 1 && ny >= 1 && nx <= R && ny <= C)
                {
                    if (MAP[nx][ny] == 'Z') continue;
                    if (MAP[nx][ny] != '.')
                    {
                        dir = Set_Direct(i, MAP[nx][ny]);
                        Q.push({ nx, ny, dir });
                        if (Visit[nx][ny] == false) Visit[nx][ny] = true;
                    }
                }
            }
 
            if (Q.size() == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    memset(Visit, false, sizeof(Visit));
 
                    if (Answer == true) break;
                    nx = x + dx[i];
                    ny = y + dy[i];
 
                    if (nx >= 1 && ny >= 1 && nx <= R && ny <= C)
                    {
                        for (int j = 0; j < 7; j++)
                        {
                            memset(Visit, false, sizeof(Visit));
 
                            MAP[nx][ny] = Pipe[j];
                            pair<int, int> Temp;
                            Temp = BFS();
                            if (Temp.first == -1 && Temp.second == -1)
                            {
                                
                                if (Can_Use_All_Pipe() == true)
                                {
                                    Answer = true;
                                    cout << x << " " << y << " " << Pipe[j] << endl;
                                    exit(0);
                                }
                            }
                            MAP[nx][ny] = '.';
                        }
                    }
                }
            }
        }
        else
        {
            nx = x + dx[dir];
            ny = y + dy[dir];
 
            if (nx >= 1 && ny >= 1 && nx <= R && ny <= C)
            {
                if (MAP[nx][ny] == '.') return{ nx, ny };
                if (MAP[nx][ny] == 'Z') return{ -1, -1 };
 
                dir = Set_Direct(dir, MAP[nx][ny]);
                if (dir == -1) return{ nx ,ny };
                if (Visit[nx][ny] == false) Visit[nx][ny] = true;
                Q.push({ nx, ny, dir });
            }
        }
    }
}
 
void Solution()
{
    pair<int, int> Before, After;
    Before = BFS();
    for (int i = 0; i < 7; i++)
    {
        int x = Before.first;
        int y = Before.second;
        MAP[x][y] = Pipe[i];
 
        memset(Visit, false, sizeof(Visit));
        After = BFS();
        if (After.first == -1 && After.second == -1)
        {
            if (Can_Use_All_Pipe() == true)
            {
                cout << x << " " << y << " " << Pipe[i] << endl;
                return;
            }
        }
    }
}
 
void Solve()
{
    Input();
    Solution();
}
 
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    //freopen("Input.txt", "r", stdin);
    Solve();
 
    return 0;
}
