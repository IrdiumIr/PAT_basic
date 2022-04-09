// 1027 打印沙漏 (20 分)
// 本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

#include <iostream>

int main()
{
    int N = 0, n = 0;
    char ch;
    std::cin >> N >> ch;
    //
    // 中间1 两侧3 5 7递增
    // sn = (3 + (2n + 1)) * n / 2 = n * (n + 2)
    while ((2 * n * (n + 2) + 1) <= N)
        ++n;
    int line = n - 1;// 两侧各有line行

    for (int i = line; i != 0; --i)// 上半部
    {
        for (int j = line - i; j != 0; --j)// i + j == line
            std::cout << ' ';
        for (int k = 0; k != 2 * i + 1; ++k)
            std::cout << ch;
        std::cout << std::endl;
    }

    for (int i = 0; i != line; ++i)
        std::cout << ' ';
    std::cout << ch << std::endl;

    for (int i = 0; i != line; ++i)
    {
        for (int j = 1; j != line - i; ++j)
            std::cout << ' ';
        for (int k = 0; k != 2 * i + 3; ++k)
            std::cout << ch;
        std::cout << std::endl;
    }
    std::cout << N - (2 * line * (line + 2) + 1);
}