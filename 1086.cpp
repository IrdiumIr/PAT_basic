// 1086 就不告诉你 (15 分)
// 做作业的时候，邻座的小盆友问你：“五乘以七等于多少？”
// 你应该不失礼貌地围笑着告诉他：“五十三。”
// 本题就要求你，对任何一对给定的正整数，倒着输出它们的乘积。

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    int A, B;
    std::cin >> A >> B;
    std::string AB = std::to_string(A * B);
    std::reverse(AB.begin(), AB.end());
    std::cout << std::stoi(AB) << std::endl;
    return 0;
}