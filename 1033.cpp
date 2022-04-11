// 1033 旧键盘打字 (20 分)
// 旧键盘上坏了几个键，于是在敲一段文字的时候，对应的字符就不会出现。
// 现在给出应该输入的一段文字、以及坏掉的那些键，打出的结果文字会是怎样？

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    std::string str_bad, str_should;
    getline(std::cin, str_bad);
    getline(std::cin, str_should);
    // 在should中遍历 若这个字符（的大写版本）不在bad中/若这个为大写 且 bad中有+符号
    // 则才会输出
    for (sz i = 0; i != str_should.size(); ++i)
    {
        if (str_bad.find(toupper(str_should[i])) != std::string::npos)
            continue;
        if (str_bad.find('+') != std::string::npos && isupper(str_should[i]))
            continue;
        std::cout << str_should[i];
    }
    return 0;
}