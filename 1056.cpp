// 1056 组合数的和 (15 分)
// 给定 N 个非 0 的个位数字，用其中任意 2 个数字都可以组合成 1 个 2 位的数字。
// 要求所有可能组合出来的 2 位数字的和。例如给定 2、5、8，则可以组合出：25、28、52、58、82、85，它们的和为330。

#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int sum = 0;
    for (int i = 0; i != n; ++i)
    {
        int ii = 0;
        std::cin >> ii;
        sum += ii * (n - 1) * (10 + 1);
    }// 每个数字都能在其他n-1个数字中出现在十位/个位
    std::cout << sum << std::endl;
    return 0;
}