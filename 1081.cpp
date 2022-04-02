// 1081 检查密码 (15 分)
// 本题要求你帮助某网站的用户注册模块写一个密码合法性检查的小功能。
// 该网站要求用户设置的密码必须由不少于6个字符组成，
// 并且只能有英文字母、数字和小数点 .
// ，还必须既有字母也有数字。

#include <iostream>
#include <cctype>

int main()
{
    int N = 0;
    std::cin >> N;
    getchar();// 等待输入string
    for (auto i = 0; i != N; ++i)
    {
        std::string s;
        std::getline(std::cin, s);
        if (s.size() >= 6)
        {
            bool isIllegal = false, hasNum = false, hasAlp = false;
            for (std::string::size_type i = 0; i != s.size(); ++i)
            {
                if (s[i] != '.' && !isalpha(s[i]) && !isdigit(s[i]))
                    isIllegal = true;
                else if (isalpha(s[i]))
                    hasAlp = true;
                else if (isdigit(s[i]))
                    hasNum = true;
            }
            if (isIllegal)
                std::cout << "Your password is tai luan le." << std::endl;
            else if (!hasNum)
                std::cout << "Your password needs shu zi." << std::endl;
            else if (!hasAlp)
                std::cout << "Your password needs zi mu." << std::endl;
            else
                std::cout << "Your password is wan mei." << std::endl;
        }
        else if (s.size() < 6)
            std::cout << "Your password is tai duan le." << std::endl;
    }
    return 0;
}