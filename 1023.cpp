// 1023 组个最小数 (20 分)
// 给定数字 0-9 各若干个。你可以以任意顺序排列这些数字，但必须全部使用。
// 目标是使得最后得到的数尽可能小（注意 0 不能做首位）。
// 例如：给定两个 0，两个 1，三个 5，一个 8，我们得到的最小的数就是 10015558。

// 现给定数字，请编写程序输出能够组成的最小的数。

#include <iostream>
#include <vector>

int main()
{
    int n;
    std::vector<int> arr;
    while (std::cin>>n)
        arr.push_back(n);// 个数array
    int tmp = 0;
    for (int i = 1; i != 10; ++i)
    {
        if (arr[i] != 0)
        {
            std::cout << i;
            tmp = i;
            break;
        }
    }
    for (int i = 0; i != arr[0]; ++i)
        std::cout << 0;
    for (int i = 0; i != arr[tmp] - 1; ++i)
        std::cout << tmp;
    for (int i = tmp + 1; i != 10; ++i)
    {
        for (int j = 0; j != arr[i]; ++j)
            std::cout << i;
    }
    return 0;
}