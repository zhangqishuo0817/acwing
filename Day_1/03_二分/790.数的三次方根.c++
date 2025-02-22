#include <cstdio>
#include <iostream>

int main() {
    double x;
    std::cin >> x; // 读取用户输入的目标值

    double l = -10000; // 左边界
    double r = 10000;  // 右边界

    // 二分查找，直到区间长度小于 1e-8
    while (r - l > 1e-8) {
        double mid = (l + r) / 2; // 计算中间值
        if (mid * mid * mid >= x) {
            r = mid; // 缩小右边界
        } else {
            l = mid; // 缩小左边界
        }
    }

    // 输出结果，保留 6 位小数
    printf("%.6f\n", l);

    return 0;
}