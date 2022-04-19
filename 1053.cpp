// 1053 住房空置率 (20 分)
// 在不打扰居民的前提下，统计住房空置率的一种方法是根据每户用电量的连续变化规律进行判断。判断方法如下：
// 在观察期内，若存在超过一半的日子用电量低于某给定的阈值 e，则该住房为“可能空置”；
// 若观察期超过某给定阈值 D 天，且满足上一个条件，则该住房为“空置”。
// 现给定某居民区的住户用电量数据，请你统计“可能空置”的比率和“空置”比率，即以上两种状态的住房占居民区住房总套数的百分比。

#include <iostream>

int main()
{
    int N, D;
    double e;
    std::cin >> N >> e >> D;
    int K;// day(s)
    double ei;// e1.e2...ek

    int empty_num = 0, maybe_empty_num = 0;

    for (int i = 0; i != N; ++i)
    {
        std::cin >> K;
        int day_sum = 0;// num of (<e)
        for (int j = 0; j != K; ++j)
        {
            std::cin >> ei;
            if (ei < e)
                day_sum++;
        }
        if (day_sum > (K / 2))
        {
            if (K > D)// empty
                empty_num++;
            else// maybe empty
                maybe_empty_num++;
        }
    }
    printf("%.1f%% %.1f%%", (maybe_empty_num * 1.0 / N * 100), (empty_num * 1.0 / N * 100));
    return 0;
}