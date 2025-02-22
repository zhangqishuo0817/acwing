#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5;
char map[N][N], backup[N][N];
typedef pair<int, int> PII;
vector<PII> ans;

// 获取位置索引
int get(int x, int y) {
    return 4 * x + y;
}

// 翻转单个格子
void turn_one(int x, int y) {
    if (map[x][y] == '+') map[x][y] = '-';
    else map[x][y] = '+';
}

// 翻转某个格子所在的行和列
void turn_all(int x, int y) {
    for (int i = 0; i < 4; i++) {
        turn_one(x, i); // 翻转行
        turn_one(i, y); // 翻转列
    }
    turn_one(x, y); // 中心格子被翻转两次，需要再翻转一次
}

int main() {
    // 输入棋盘状态
    for (int i = 0; i < 4; i++) {
        cin >> map[i];
    }

    // 枚举所有可能的操作组合
    for (int op = 0; op < (1 << 16); op++) {
        memcpy(backup, map, sizeof(map)); // 备份原始棋盘
        vector<PII> temp;

        // 根据当前操作组合翻转棋盘
        for (int k = 0; k < 4; k++) {
            for (int t = 0; t < 4; t++) {
                if (op >> get(k, t) & 1) {
                    turn_all(k, t);
                    temp.push_back({k, t});
                }
            }
        }

        // 检查是否所有格子都变为 '-'
        bool flag = true;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (map[i][j] == '+') {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }

        // 更新最优解
        if (flag) {
            if (ans.empty() || ans.size() > temp.size()) {
                ans = temp;
            }
        }

        // 恢复原始棋盘
        memcpy(map, backup, sizeof(map));
    }

    // 输出结果
    cout << ans.size() << endl;
    for (auto op : ans) {
        cout << op.first + 1 << " " << op.second + 1 << endl;
    }

    return 0;
}