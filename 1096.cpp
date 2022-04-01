// 1096 大美数 (15 分)
// 若正整数 N 可以整除它的 4 个不同正因数之和，则称这样的正整数为“大美数”。
// 本题就要求你判断任一给定的正整数是否是“大美数”。

#include <iostream>
#include <vector>

int main()
{
    int K = 0;
    std::cin >> K;
    int N = 0;// 每个数字
    for (auto i = 0; i != K; ++i)
    {
        std::cin >> N;
        std::vector<int> tmp;
        for (auto i = 1; i <= N; ++i)
        {
            if (N % i == 0)
                tmp.push_back(i);
        }
        auto n = tmp.size();
        auto flag = false;
        for (auto i = 0; i != n && !flag; ++i)
        {
            for (auto j = i + 1; j != n && !flag; ++j)
            {
                for (auto k = j + 1; k != n && !flag; ++k)
                {
                    for (auto l = k + 1; l != n && !flag; ++l)
                    {
                        int sum = 0;
                        sum += tmp[i] + tmp[j] + tmp[k] + tmp[l];
                        if (sum % N == 0)
                        {
                            flag = true;
                            break;
                        }
                    }
                }
            }
        }

        if (flag)
            std::cout << "Yes" << std::endl;
        else
            std::cout << "No" << std::endl;
    }
    return 0;
}