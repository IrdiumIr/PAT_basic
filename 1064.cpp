// 1064 朋友数 (20 分)
// 如果两个整数各位数字的和是一样的，则被称为是“朋友数”，而那个公共的和就是它们的“朋友证号”。
// 例如 123 和 51 就是朋友数，因为 1+2+3 = 5+1 = 6，而 6 就是它们的朋友证号。
// 给定一些整数，要求你统计一下它们中有多少个不同的朋友证号。

#include <iostream>
#include <set>

int main()
{
    int N = 0;
    std::cin >> N;
    std::string s;
    std::set<int> st;
    using sz = std::string::size_type;

    for (int i = 0; i != N; ++i)
    {
        std::cin >> s;
        int sum = 0;
        for (sz j = 0; j != s.size(); ++j)
            sum += s[j]- '0';
        st.insert(sum);
    }
    std::cout << st.size() << std::endl;
    for (auto it = st.begin(); it != st.end(); ++it)
    {
        if (it != st.begin())
            std::cout << " ";
        std::cout << *it;
    }
    return 0;
}