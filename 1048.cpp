// 1048 数字加密 (20 分)
// 本题要求实现一种数字加密方法。首先固定一个加密用正整数 A，对任一正整数 B，将其每 1 位数字与 A 的对应位置上的数字进行以下运算：
// 对奇数位，对应位的数字相加后对 13 取余——这里用 J 代表 10、Q 代表 11、K 代表 12；
// 对偶数位，用 B 的数字减去 A 的数字，若结果为负数，则再加 10。这里令个位为第 1 位。

#include <iostream>
#include <algorithm>

int main()
{
    using sz = std::string::size_type;
    std::string A, B;
    std::cin >> A >> B;

    int flag = 1;// 末位是1开始
    if (A.size() > B.size())
    {
        std::reverse(B.begin(), B.end());
        B.append(A.size() - B.size(), '0');
        std::reverse(B.begin(), B.end());
    }  
    else
    {
        std::reverse(A.begin(), A.end());
        A.append(B.size() - A.size(), '0');
        std::reverse(A.begin(), A.end());
    }
    
    char arr[14] = {"0123456789JQK"};
    std::string ans(B.size(), '0');
    for (sz i = B.size(); i != 0; --i)
    {
        if (flag % 2)// 奇数
            ans[i-1] = arr[(A[i-1] - '0' + B[i-1] - '0') % 13];
        else
        {
            int tmp = (B[i-1] - '0') - (A[i-1] - '0');
            if (tmp >= 0)
                ans[i-1] = arr[tmp];
            else
                ans[i-1] = arr[tmp + 10];
        }
        ++flag;
    }
    std::cout << ans;
    return 0;
}