// 1018 锤子剪刀布 (20 分)
// 大家应该都会玩“锤子剪刀布”的游戏：两人同时给出手势，胜负规则如图所示：
// 现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    int win_j = 0, lose_j = 0;
    std::vector<int> sig_j{0, 0, 0}, sig_y{0, 0, 0};// 统计手势c/j/b
    for (int i = 0; i != N; ++i)
    {
        char a, b;
        std::cin >> a >> b;
        if (a == 'C' && b == 'J')
        {
            ++win_j;
            ++sig_j[0];
        }
        if (a == 'C' && b == 'B')
        {
            ++lose_j;
            ++sig_y[2];
        }
        if (a == 'J' && b == 'C')
        {
            ++lose_j;
            ++sig_y[0];
        }
        if (a == 'J' && b == 'B')
        {
            ++win_j;
            ++sig_j[1];
        }
        if (a == 'B' && b == 'C')
        {
            ++win_j;
            ++sig_j[2];
        }
        if (a == 'B' && b == 'J')
        {
            ++lose_j;
            ++sig_y[1];
        }
    }

    std::cout << win_j << " " << (N - win_j - lose_j) << " " << lose_j << std::endl;
    std::cout << lose_j << " " << (N - win_j - lose_j) << " " << win_j << std::endl;
    // 调节一下比较顺序保证输出是BCJ字典序
    if (sig_j[2] >= sig_j[1])
    {
        if (sig_j[2] >= sig_j[0])
            std::cout << "B ";
        else
            std::cout << "C ";
    }
    else
    {
        if (sig_j[0] >= sig_j[1])
            std::cout << "C ";
        else
            std::cout << "J ";
    }

    if (sig_y[2] >= sig_y[1])
    {
        if (sig_y[2] >= sig_y[0])
            std::cout << "B";
        else
            std::cout << "C";
    }
    else
    {
        if (sig_y[0] >= sig_y[1])
            std::cout << "C";
        else
            std::cout << "J";
    }
    return 0;
}