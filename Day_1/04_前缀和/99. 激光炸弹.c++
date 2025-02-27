#include <iostream>

using namespace std;

#define N 5002
int f[N][N];

int main() {

    int n, r;
    int max_x, max_y;
    int x = 0, y = 0, w = 0;
    cin >> n >> r;
    r = min(r, 5001); // 爆炸范围超过5001时覆盖了所有目标范围，因此没必要考虑超出范围。
    max_x = max_y = r;// 最小的爆炸计算范围是在一个最小爆炸范围之内计算
    for (int i = 0; i < n; ++i) {
        cin >> x >> y >> w;
        f[++x][++y] += w; // 将目标范围统一偏移1，便于边界计算。
        max_x = max(x, max_x); // 如果有目标落在一个最小爆炸范围之外，则扩大计算范围。
        max_y = max(y, max_y);
    }
    // 下面两个循环的计算公式都需要自己用手画一下，才能获得利用二维前缀和计算总价值的结果
    for (int i = 1; i <= max_x; ++i) { // 循环从偏移的1开始
        for (int j = 1; j <= max_y; ++j) {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + f[i][j];
        }
    }

    int ans = 0;
    for (int i = r; i <= max_x; ++i) {
        for (int j = r; j <= max_y; ++j) {
            ans = max(ans, f[i][j] - f[i - r][j] - f[i][j - r] + f[i - r][j - r]);
        }
    }

    cout << ans << endl;

    return 0;
} 

