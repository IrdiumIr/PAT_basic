// 1017 A除以B (20 分)
// 本题要求计算 A/B，其中 A 是不超过 1000 位的正整数，B 是 1 位正整数。
// 你需要输出商数 Q 和余数 R，使得 A=B×Q+R 成立。

#include <iostream>
#include <vector>

int main()
{
    using sz = std::string::size_type;
    std::string A;// 1000位使用string
    int B = 0;

    std::cin >> A >> B;// 输入AB
    sz Alenth = A.size();
    // 除法竖式の实现
    if (Alenth == 1)
        std::cout << (std::stoi(A) / B) << " " << (std::stoi(A) % B);
    else
    {   
        int tmp1 = 0, tmp2 = 0;
        std::vector<int> ans;
        ans.reserve(1000);
        tmp1 = (A[0] - '0') / B;// 第一次得到结果首位

        if (tmp1 != 0)
            ans.emplace_back(tmp1);
        tmp2 = (A[0] - '0') % B;

        for (sz i = 1; i != Alenth; ++i)
        {
            tmp1 = ((A[i] - '0') + 10 * tmp2) / B;// 新的一位+上一位*10 / 除数
            ans.emplace_back(tmp1);
            tmp2 = ((A[i] - '0') + 10 * tmp2) % B;
        }

        for (const auto i : ans)
            std::cout << i;
        std::cout << " " << tmp2;
    }
    return 0;
}