// 1057 数零壹 (20 分)
// 给定一串长度不超过 10 5的字符串，本题要求你
// 将其中所有英文字母的序号（字母 a-z 对应序号 1-26，不分大小写）相加，得到整数 N，
// 然后再分析一下 N 的二进制表示中有多少 0、多少 1。
// 例如给定字符串 PAT (Basic)，其字母序号之和为：16+1+20+2+1+19+9+3=71，而 71 的二进制是 1000111，即有 3 个 0、4 个 1。

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    std::string str;
    std::getline(std::cin, str);
    int sum = 0;

    for (sz i = 0; i != str.size(); ++i)
    {
        if (isalpha(str[i]))
        {
            str[i] = tolower(str[i]);
            sum += (str[i] - 'a' + 1);// a-z~1-26
        }
    }

    int cnt_1 = 0, cnt_0 = 0;
    while (sum != 0)
    {
        if (sum % 2 != 0)
            ++cnt_1;
        else
            ++cnt_0;
        sum /= 2;
    }
    std::cout << cnt_0 << " " << cnt_1;
    return 0;
}