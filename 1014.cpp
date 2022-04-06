// 1014 福尔摩斯的约会 (20 分)
// 大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间星期四 14:04，
// 因为前面两字符串中第 1 对相同的大写英文字母（大小写有区分）是第 4 个字母 D，代表星期四；
// 第 2 对相同的字符是 E ，那是第 5 个英文字母，代表一天里的第 14 个钟头
// （于是一天的 0 点到 23 点由数字 0 到 9、以及大写字母 A 到 N 表示）；
// 后面两字符串第 1 对相同的英文字母 s 出现在第 4 个位置（从 0 开始计数）上，代表第 4 分钟。
// 现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::string s1, s2, s3, s4;
    std::cin >> s1 >> s2 >> s3 >> s4;
    using sz = std::string::size_type;
    sz i = 0, j = 0;
    sz time_min = 0;
    std::vector<char> datetime;

    while (i != s1.size() && i != s2.size())
    {
        // if (s1[i] == s2[i] && isupper(s1[i]))
        if (s1[i] == s2[i] && (s1[i] >= 'A' && s1[i] <= 'G'))// 星期1-7只能有7个选项
        {
            datetime.emplace_back(s1[i]);
            break;// 第1对相同(Upper)
        }
        ++i;
    }
    
    ++i;// i=i+1，从第二组重复的开始找
    
    while (i != s1.size() && i != s2.size())
    {
        if (s1[i] == s2[i] && (isdigit(s1[i]) || (s1[i] >= 'A' && s1[i] <= 'N')))
        {
            datetime.emplace_back(s1[i]);
            break;// 第2对相同(0-9 A-N)
        }
        ++i;
    }
    
    while (j != s3.size() && j != s4.size())
    {
        if (s3[j] == s4[j] && isalpha(s3[j]))
        {
            time_min = j;
            break;// 第1对相同位置
        }
        ++j;
    }
    
    switch (datetime[0])
    {
        case 'A':
            std::cout << "MON ";
            break;
        case 'B':
            std::cout << "TUE ";
            break;
        case 'C':
            std::cout << "WED ";
            break;
        case 'D':
            std::cout << "THU ";
            break;
        case 'E':
            std::cout << "FRI ";
            break;
        case 'F':
            std::cout << "SAT ";
            break;
        case 'G':
            std::cout << "SUN ";
            break;
        default:
            break;
    }

    std::cout << std::setfill('0') << std::setw(2) << (isalpha(datetime[1]) ? (datetime[1] - 'A' + 10) : (datetime[1] - '0')) << ":";
    std::cout << std::setfill('0') << std::setw(2) << time_min;
    return 0;
}