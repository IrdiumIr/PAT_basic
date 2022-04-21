// 1062 最简分数 (20 分)
// 一个分数一般写成两个整数相除的形式：N/M，其中 M 不为0。最简分数是指分子和分母没有公约数的分数表示形式。

// 现给定两个不相等的正分数 N 1/M 1和 N 2/M 2，要求你按从小到大的顺序列出它们之间分母为 K 的最简分数。

#include <iostream>

int gcd(int a, int b) {
    int r = 0;
    while (b != 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    int N1 = 0, M1 = 0, N2 = 0, M2 = 0;
    int K = 0;
    scanf("%d/%d %d/%d %d", &N1, &M1, &N2, &M2, &K);
    // 保证左侧区间<右侧
    if (N1 * M2 > N2 * M1) {
        std::swap(N1, N2);
        std::swap(M1, M2);
    }
    // 给定分母=K，则区间内分数为num/K，通分三个分数以确定分子num
    int num = 1;
    int count = 0;

    while (num * M1 <= N1 * K)
        ++num;
    while (num * M1 > N1 * K && num * M2 < N2 * K) {
        if (gcd(num, K) == 1) {
            if (count == 0)
                printf("%d/%d", num, K);
            else if (count != 0)
                printf("%s%d/%d", " ", num, K);
            ++count;
        }
        ++num;
    }
    return 0;
}