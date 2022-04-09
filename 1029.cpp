// 1029 旧键盘 (20 分)
// 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
// 现在给出应该输入的一段文字、以及实际被输入的文字，请你列出肯定坏掉的那些键。

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    std::string s1, s2;
    std::string res;// 确保不重复输出坏键
    std::cin >> s1 >> s2;
    for (sz i = 0; i != s1.size(); ++i)
    {
        if (s2.find(s1[i]) == std::string::npos && res.find(toupper(s1[i])) == std::string::npos)
            res += toupper(s1[i]);
    }
    std::cout << res << std::endl;
}