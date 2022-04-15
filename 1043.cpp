// 1043 输出PATest (20 分)
// 给定一个长度不超过 10 4的、仅由英文字母构成的字符串。
// 请将字符重新调整顺序，按 PATestPATest.... 这样的顺序输出，并忽略其它字符。
// 当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按 PATest 的顺序打印，直到所有字符都被输出。
#include <iostream>
#include <unordered_map>

int main()
{
    using sz = std::string::size_type;
    std::string s;
    std::unordered_map<char, int> dic;
    std::cin >> s;
    for (sz i = 0; i != s.size(); ++i)
    {
        if (s[i] == 'P' || s[i] == 'A' || s[i] == 'T' || s[i] == 'e' || s[i] == 's' || s[i] == 't')
            ++dic[s[i]];
    }
    while (dic['P'] > 0 || dic['A'] > 0 || dic['T'] > 0 || dic['e'] > 0 || dic['s'] > 0 || dic['t'] > 0)
    {
        if (dic['P'] > 0)
        {
            std::cout << 'P';
            --dic['P'];
        }
        if (dic['A'] > 0)
        {
            std::cout << 'A';
            --dic['A'];
        }
        if (dic['T'] > 0)
        {
            std::cout << 'T';
            --dic['T'];
        }
        if (dic['e'] > 0)
        {
            std::cout << 'e';
            --dic['e'];
        }
        if (dic['s'] > 0)
        {
            std::cout << 's';
            --dic['s'];
        }
        if (dic['t'] > 0)
        {
            std::cout << 't';
            --dic['t'];
        }
    }
    return 0;
}