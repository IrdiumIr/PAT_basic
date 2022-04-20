// 1059 C语言竞赛 (20 分)
// C 语言竞赛是浙江大学计算机学院主持的一个欢乐的竞赛。既然竞赛主旨是为了好玩，颁奖规则也就制定得很滑稽：

// 0、冠军将赢得一份“神秘大奖”（比如很巨大的一本学生研究论文集……）。
// 1、排名为素数的学生将赢得最好的奖品 —— 小黄人玩偶！
// 2、其他人将得到巧克力。
// 给定比赛的最终排名以及一系列参赛者的 ID，你要给出这些参赛者应该获得的奖品。

#include <iostream>
#include <unordered_map>

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n == 2 || n == 3)
        return true;
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int N = 0;
    std::cin >> N;
    std::unordered_map<int, int> dic;
    for (int i = 0; i != N; ++i)
    {
        int id = 0;
        std::cin >> id;
        dic.insert({id, i + 1});
    }

    int K = 0;
    std::cin >> K;

    for (int i = 0; i != K; ++i)
    {
        int id = 0;
        std::cin >> id;
        printf("%04d: ", id);

        if (dic.find(id) == dic.end())
        {
            std::cout << "Are you kidding?" << std::endl;
            continue;
        }
        if (dic[id] == 1)
        {
            std::cout << "Mystery Award" << std::endl;
            dic[id] = 0;
        }
        else if (isPrime(dic[id]))
        {
            std::cout << "Minion" << std::endl;
            dic[id] = 0;
        }
        else if (dic[id] == 0)
        {
            std::cout << "Checked" << std::endl;
            continue;
        }
        else
        {
            std::cout << "Chocolate" << std::endl;
            dic[id] = 0;
        }
    }
    return 0;
}