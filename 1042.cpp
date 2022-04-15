// 1042 字符统计 (20 分)
// 请编写程序，找出一段给定文字中出现最频繁的那个英文字母。

#include <iostream>
#include <unordered_map>

int main()
{
    using sz = std::string::size_type;
    std::string s;
    getline(std::cin, s);
    std::unordered_map<char, int> dic;
    for (sz i = 0; i != s.size(); ++i)
    {
        if (isalpha(s[i]))
        {
            auto iter = dic.insert({tolower(s[i]), 1});
            if (!iter.second)
                ++iter.first->second;
        }
    }
    int maxnum = 0;
    char maxalpha = 'z';
    for (auto it = dic.begin(); it != dic.end(); ++it)
    {
        if (it->second >= maxnum)
        {
            if (it->first <= maxalpha)
            {
                maxnum = it->second;
                maxalpha = it->first;
            }
        }
    }
    std::cout << maxalpha << " " << maxnum << std::endl;
    return 0;
}