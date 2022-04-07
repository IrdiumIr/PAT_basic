// 1003 我要通过！ (20 分)
// “答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于 PAT 的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

// 得到“答案正确”的条件是：

// 字符串中必须仅有 P、 A、 T这三种字符，不可以包含其它字符；
// 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
// 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a、 b、 c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
// 现在就请你为 PAT 写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

#include <iostream>

int main()
{
    using sz = std::string::size_type;
    int N = 0;
    
    std::cin >> N;
    std::string s;
    
    for (int i = 0; i != N; ++i)
    {
        bool flag = true;
        int count_p = 0, count_t = 0;
        sz pos_p = 0, pos_t = 0;

        std::cin >> s;
        for (sz j = 0; j != s.size(); ++j)
        {
            bool flag = true;
            if (s[j] != 'P' && s[j] != 'A' && s[j] != 'T')// 多余字符直接break
            {
                flag = false;
                break;
            }
            if (s[j] == 'P')
            {
                ++count_p;
                pos_p = j;
            } 
            if (s[j] == 'T')
            {
                ++count_t;
                pos_t = j;
            }
        }
        if (flag)
        {
            if (count_p == 1 && count_t == 1 && (pos_t - pos_p) > 1)// AT仅1个，且T在P右侧且不相邻
            {
                if ((pos_p * (pos_t - pos_p - 1)) == s.size() - pos_t -1)// nA2AT2nA
                    std::cout << "YES" << std::endl;
                else
                    std::cout << "NO" << std::endl;
            }
            else
                std::cout << "NO" << std::endl;
        }
        else
            std::cout << "NO" << std::endl;
    }
    return 0;
}