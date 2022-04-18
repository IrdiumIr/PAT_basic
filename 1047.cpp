// 1047 编程团体赛 (20 分)
// 编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

// 现给定所有队员的比赛成绩，请你编写程序找出冠军队。

#include <iostream>
#include <unordered_map>

int main()
{
    int N = 0, team = 0, num = 0, score = 0;
    std::cin >> N;
    std::unordered_map<int, int> dic;
    
    for (int i = 0; i != N; ++i)
    {
        scanf("%d-%d %d", &team, &num, &score);
        dic[team] += score;
    }
    int highest_score = 0;
    for (int i = 1; i <= 1000; ++i)
    {
        if (dic[i] > dic[highest_score])
            highest_score = i;
    }
    std::cout << highest_score << " " << dic[highest_score];
    return 0;
}