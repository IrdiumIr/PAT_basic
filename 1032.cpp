// 1032 挖掘机技术哪家强 (20 分)
// 为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。
// 现请你根据比赛结果统计出技术最强的那个学校。

#include <iostream>
#include <vector>

int main()
{
    int N = 0;
    std::cin >> N;
    int num = 0, score = 0;
    std::vector<int> res(N + 1);

    for (int i = 0; i != N; ++i)
    {
        std::cin >> num >> score;
        res[num] += score;
    }

    int num_max = 0, score_max = 0;
    for (int i = 1; i != N + 1; ++i)
    {
        if (score_max <= res[i])
        {
            score_max = res[i];
            num_max = i;
        }
    }
    std::cout << num_max << " " << score_max;
}