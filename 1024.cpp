// 1024 科学计数法 (20 分)
// 科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，
// 其满足正则表达式 [+-][1-9].[0-9]+E[+-][0-9]+，
// 即数字的整数部分只有 1 位，小数部分至少有 1 位，
// 该数字及其指数部分的正负号即使对正数也必定明确给出。
// 现以科学计数法的格式给出实数 A，请编写程序按普通数字表示法输出 A，并保证所有有效位都被保留。

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    std::string s;
    std::cin >> s;// 输入带± E的string
    sz i = 0;
    for (; i != s.size(); ++i)
        if (s[i] == 'E')
            break;
    std::string s1 = s.substr(1, i - 1);// E前的部分
    std::string s2 = s.substr(i + 1);// E后部分
    int s2n = std::stoi(s2);

    if (s[0] == '-')// 首先输出符号
        std::cout << '-';
    
    if (s2n < 0)// 0.xxx的结果 : / 10^n
    {
        std::cout << "0.";
        for (int i = 0; i != abs(s2n) - 1; ++i)// 小数点后有 n-1 个0
            std::cout << '0';
        for (sz i = 0; i != s1.size(); ++i)// 将s1中全部输出 且 不用去掉0
        {
            if (s1[i] != '.')
                std::cout << s1[i];
        }
    }
    else// xxx.yy的结果 : * 10^n
    {
        std::cout << s1[0];// 先输出首位
        sz j = 2;
        int cnt = 0;
        while (j != s1.size() && cnt != s2n)// 处理s1 且需要考虑E后的数是否能处理完s1的小数点
        // j从2开始 无小数点
        {
            std::cout << s1[j];
            ++j;
            ++cnt;
        }
        // 测试点2/3出现问题 ： 当两条件同时满足时，由于先检测cnt==s2n 则会多输出一个小数点'.'
        // 调整顺序即可 && 或者加个判断
        
        // if (cnt == s2n)// E后位数不够还有小数
        // {
        //     std::cout << '.';
        //     for (sz i = j; i != s1.size(); ++i)
        //         std::cout << s1[i];
        // }
        // else if (j == s1.size())// 后面10^n还有余 添加0
        // {
        //     for (int i = 0; i != s2n - cnt; ++i)
        //         std::cout << '0';
        // }

        if (j == s1.size())// 后面10^n还有余 添加0
        {
            for (int i = 0; i != s2n - cnt; ++i)
                std::cout << '0';
        }
        else if (cnt == s2n)// E后位数不够还有小数
        {
            std::cout << '.';
            for (sz i = j; i != s1.size(); ++i)
                std::cout << s1[i];
        }

    }
    return 0;
}