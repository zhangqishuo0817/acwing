bfs棋盘不大是可用
上去整

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    // 使用 vector 来替代变长数组
    vector<int> arr(m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    // 对数组进行排序（二分查找的前提）
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);

        // 第一次二分查找：找到第一个 >= x 的位置
        int l = 0, r = m - 1;
        while (l < r) {
            int mid = l + r / 2;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        // 检查是否找到目标值
        if (arr[r] == x) {
            printf("%d ", r); // 输出第一个等于 x 的索引

            // 第二次二分查找：找到最后一个 <= x 的位置
            l = 0, r = m - 1;
            while (l < r) {
                int mid = l + r+1 / 2;
                if (arr[mid] <= x) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }

            printf("%d\n", r); // 输出最后一个等于 x 的索引
        } else {
            printf("-1 -1\n"); // 如果找不到 x
        }
    }

    return 0;
}
