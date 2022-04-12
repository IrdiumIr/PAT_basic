// 1039 到底买不买 (20 分)
// 小红想买些珠子做一串自己喜欢的珠串。卖珠子的摊主有很多串五颜六色的珠串，但是不肯把任何一串拆散了卖。
// 于是小红要你帮忙判断一下，某串珠子里是否包含了全部自己想要的珠子？
// 如果是，那么告诉她有多少多余的珠子；如果不是，那么告诉她缺了多少珠子。

// 为方便起见，我们用[0-9]、[a-z]、[A-Z]范围内的字符来表示颜色。
// 例如在图1中，第3串是小红想做的珠串；那么第1串可以买，因为包含了全部她想要的珠子，还多了8颗不需要的珠子；
// 第2串不能买，因为没有黑色珠子，并且少了一颗红色的珠子。

#include <iostream>
#include <unordered_map>

int main()
{
    using sz = std::string::size_type;
    std::string given, wanted;
    std::cin >> given >> wanted;
    std::unordered_map<char, int> maps;
    int nums = 0;
    for (sz i = 0; i != given.size(); ++i)// 建立了char-个数的map
    {
        auto ret = maps.insert({given[i], 1});
        if (!ret.second)
            ++ret.first->second;
    }
    for (sz i = 0; i != wanted.size(); ++i)// 遍历想要的string
    {
        if (maps[wanted[i]] != 0)
            --maps[wanted[i]];
        else
            ++nums;
    }
    if (nums != 0)
        std::cout << "No " << nums;
    else
        std::cout << "Yes " << given.size() - wanted.size();
    return 0;
}