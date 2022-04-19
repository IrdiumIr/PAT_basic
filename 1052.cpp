// 1052 卖个萌 (20 分)
// 萌萌哒表情符号通常由“手”、“眼”、“口”三个主要部分组成。简单起见，我们假设一个表情符号是按下列格式输出的：

// [左手]([左眼][口][右眼])[右手]
// 现给出可选用的符号集合，请你按用户的要求输出表情。

#include <iostream>
#include <vector>

int main()
{
    using sz = std::string::size_type;
    std::vector<std::vector<std::string>> emoji;
    for (int i = 0; i != 3; ++i)
    {
        std::vector<std::string> tmp;// 每行的emoji
        std::string str;
        getline(std::cin, str);
        sz j = 0, k = 0;
        while (j != str.size())
        {
            if (str[j] == '[')
            {
                for (k = j + 1; k != str.size(); ++k)
                {
                    if (str[k] == ']')
                    {
                        tmp.push_back(str.substr(j + 1, k - j - 1));
                        break;
                    }
                }
            }
            j++;
        }
        emoji.push_back(tmp);
    }

    int N = 0;
    std::cin >> N;
    for (int i = 0; i != N; ++i)
    {
        sz e1, e2, e3, e4, e5;// 5*emoji
        std::cin >> e1 >> e2 >> e3 >> e4 >> e5;

        if (e1 > emoji[0].size() || e5 > emoji[0].size() ||
            e2 > emoji[1].size() || e4 > emoji[1].size() ||
            e3 > emoji[2].size() || e1 < 1 || e2 < 1 || e3 < 1 || e4 < 1 || e5 < 1)
            {
                std::cout << "Are you kidding me? @\\/@" << std::endl;
                continue;
            }
        std::cout << emoji[0][e1 - 1] 
                    << "(" << emoji[1][e2 - 1] << emoji[2][e3 - 1] << emoji[1][e4 - 1] << ")"
                    << emoji[0][e5 - 1] << std::endl;
    }
    return 0;
}