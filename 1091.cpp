// 1091 N-自守数 (15 分)
// 如果某个数 K 的平方乘以 N 以后，结果的末尾几位数等于 K，那么就称这个数为“N-自守数”。例如 3×92 
// 2
//  =25392，而 25392 的末尾两位正好是 92，所以 92 是一个 3-自守数。

// 本题就请你编写程序判断一个给定的数字是否关于某个 N 是 N-自守数。

#include <iostream>

int main()
{
    int M = 0;
    std::cin >> M;
    for (auto i = 0; i != M; ++i)
    {
        int K = 0;// K<=1000
        int flag = 0;// 找到or找不到
        std::cin >> K;
        for (auto n = 1; n != 10; ++n)
        {
            int NK2 = n * K * K;
            std::string sK = std::to_string(K);
            std::string sNK2 = std::to_string(NK2);
            std::string sNK2end = sNK2.substr(sNK2.size() - sK.size());
            if (sNK2end == sK)
            {
                std::cout << n << " " << NK2 << std::endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            std::cout << "No" << std::endl;
    }
}