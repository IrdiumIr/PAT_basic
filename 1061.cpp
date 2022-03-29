// 1061 判断题 (15 分)
// 判断题的评判很简单，本题就要求你写个简单的程序帮助老师判题并统计学生们判断题的得分。

// 输入格式：
// 输入在第一行给出两个不超过 100 的正整数 N 和 M，分别是学生人数和判断题数量。
// 第二行给出 M 个不超过 5 的正整数，是每道题的满分值。
// 第三行给出每道题对应的正确答案，0 代表“非”，1 代表“是”。
// 随后 N 行，每行给出一个学生的解答。数字间均以空格分隔。

#include <iostream>
#include <vector>
// vector初始化时用大小初始化，容器内元素会产生并值初始化为默认值
// 此时继续使用push_back会导致元素不是想要的
int main()
{
    int n = 0, m = 0;
    std::cin >> n >> m;
    std::vector<int> score, answer;
    score.reserve(m);
    answer.reserve(m);
    int score_p = 0, answer_p = 0;
    for (auto i = 0; i != m; ++i)
    {
        std::cin >> score_p;
        score.push_back(score_p);
    }
    for (auto i = 0; i != m; ++i)
    {
        std::cin >> answer_p;
        answer.push_back(answer_p);
    }
    for (auto i = 0; i != n; ++i)
    {
        int total = 0;
        for (auto ii = 0; ii != m; ++ii)
        {
            int tmp = 0;
            std::cin >> tmp;
            if (tmp == answer[ii])
                total += score[ii];
        }
        std::cout << total << std::endl;
    }
    return 0;
}