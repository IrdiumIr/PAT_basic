// 1009 说反话 (20 分)
// 给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。

// 输入格式：
// 测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。
// 字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，
// 单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。

// 输出格式：
// 每个测试用例的输出占一行，输出倒序后的句子。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    auto idx_right = -1;
    std::string src;
    std::getline(std::cin, src);
    std::vector<std::string> svec;
    for (auto i = 0; i != static_cast<int>(src.size()); ++i)
    {
        if (src[i] == ' ')
        {
            auto idx_left = idx_right;
            idx_right = i;
            auto idx = idx_left + 1;
            svec.emplace_back(src.data() + idx, idx_right - idx);
        }
    }
    svec.emplace_back(src.data() + idx_right + 1, src.size() - idx_right - 1);
    std::reverse(svec.begin(), svec.end());

    std::cout << svec[0];
    for (auto i = 1; i != static_cast<int>(svec.size()); ++i)
        std::cout << " " << svec[i];
    return 0;
}

// using stack 先入先出
// given solution from github by `liuchuo-`
    // stack<string> v;
    // string s;
    // while(cin >> s) v.push(s);
    // cout << v.top();
    // v.pop();
    // while(!v.empty()) {
    //     cout << " " << v.top();
    //     v.pop();
    // }