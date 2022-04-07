// 1019 数字黑洞 (20 分)
// 给定任一个各位数字不完全相同的 4 位正整数，
// 如果我们先把 4 个数字按非递增排序，再按非递减排序，
// 然后用第 1 个数字减第 2 个数字，将得到一个新的数字。
// 一直重复这样做，我们很快会停在有“数字黑洞”之称的 6174，
// 这个神奇的数字也叫 Kaprekar 常数。

#include <iostream>
#include <iomanip>
#include <algorithm>

int main()
{
    std::string s;
    std::cin >> s;
    s.insert(0, 4 - s.size(), '0');// 将s格式化
    // bool flag = false;
    // if (s[0]==s[1]&&s[0]==s[2]&&s[0]==s[3])
    //     flag = true;
    // while (s != "6174" && (!flag))

    do
    {
        std::string ord_str = s, rev_str = s;
        // ord_str = sort() 
        // sort无返回值
        std::sort(ord_str.begin(), ord_str.end());// 从小到大
        std::sort(rev_str.begin(), rev_str.end(), [](const char a, const char b)
                  { return a > b; });// 从大到小
        int result = std::stoi(rev_str) - std::stoi(ord_str);
        s = std::to_string(result);
        s.insert(0, 4 - s.size(), '0');
        std::cout << rev_str << " - " << ord_str << " = " << s << std::endl;
    } while (s != "6174" && s != "0000");

    return 0;
}