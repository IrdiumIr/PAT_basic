// 1006 换个格式输出整数 (15 分)
// 让我们用字母 B 来表示“百”、字母 S 表示“十”，用 12...n 来表示不为零的个位数字 n（<10）
// 换个格式来输出任一个不超过 3 位的正整数。
// 例如 234 应该被输出为 BBSSS1234，因为它有 2 个“百”、3 个“十”、以及个位的 4。

#include <iostream>
#include <deque>
int main()
{
    int number = 0;// 输入正整数
    std::cin >> number;
    std::deque<int> ideq;
    while (number != 0)
    {
        ideq.push_front(number % 10);
        number /= 10;
    }// 输入234得到{2, 3, 4}
    // auto it = ideq.begin();
    if (ideq.size() == 3)
    {
        std::cout << std::string(ideq[0], 'B') << std::string(ideq[1], 'S');
        for (auto i = 0; i != ideq[2]; ++i)
            std::cout << i + 1;
    }
    else if (ideq.size() == 2)
    {
        std::cout << std::string(ideq[0], 'S');
        for (auto i = 0; i != ideq[1]; ++i)
            std::cout << i + 1;
    }
    else
    { 
        for (auto i = 0; i != ideq[0]; ++i)
            std::cout << i + 1;
    }
    return 0;
}

// given solution from github by `liuchuo-`

    // for (int k = 0; k < b[2]; k++)
    //     cout << "B";
    // for (int k = 0; k < b[1]; k++)
    //     cout << "S";
    // for (int k = 0; k < b[0]; k++)
    //     cout << k + 1;