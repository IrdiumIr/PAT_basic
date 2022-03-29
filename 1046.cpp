// 1046 划拳 (15 分)
// 划拳是古老中国酒文化的一个有趣的组成部分。
// 酒桌上两人划拳的方法为：每人口中喊出一个数字，同时用手比划出一个数字。
// 如果谁比划出的数字正好等于两人喊出的数字之和，谁就赢了，输家罚一杯酒。
// 两人同赢或两人同输则继续下一轮，直到唯一的赢家出现。

// 下面给出甲、乙两人的划拳记录，请你统计他们最后分别喝了多少杯酒。

#include <iostream>

int main()
{
    int num = 0;
    int count_a = 0, count_b = 0;
    int a1 = 0, a2 = 0, b1 = 0, b2 = 0;
    std::cin >> num;

    for (auto i = 0; i != num; ++i)
    {
        std::cin >> a1 >> a2 >> b1 >> b2;
        if (a2 == (a1 + b1) && b2 != (a1 + b1))
            ++count_b;// a赢b喝
        if (a2 != (a1 + b1) && b2 == (a1 + b1))
            ++count_a;// b赢a喝
    }
    std::cout << count_a << " " << count_b << std::endl;
    return 0;
}