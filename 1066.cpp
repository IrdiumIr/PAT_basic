// 1066 图像过滤 (15 分)
// 图像过滤是把图像中不重要的像素都染成背景色，使得重要部分被凸显出来。
// 现给定一幅黑白图像，要求你将灰度值位于某指定区间内的所有像素颜色都用一种指定的颜色替换。

// 输入格式：
// 输入在第一行给出一幅图像的分辨率，即两个正整数 M 和 N（0<M,N≤500），另外是待过滤的灰度值区间端点 A 和 B（0≤A<B≤255）、以及指定的替换灰度值。
// 随后 M 行，每行给出 N 个像素点的灰度值，其间以空格分隔。所有灰度值都在 [0, 255] 区间内。

#include <iostream>
#include <iomanip>

int main()
{
    int m = 0, n = 0, a = 0, b = 0, c = 0;
    int tmp = 0;
    std::cin >> m >> n >> a >> b >> c;
    for (auto i = 0; i != m; ++i)
    {
        for (auto ii = 0; ii != n; ++ii)
        {
            // 一直超时 使用scanf后解决
            scanf("%d", &tmp);
            // std::cin >> tmp;
            if (tmp >= a && tmp <= b)
                tmp = c;
            if (ii != 0)
                std::cout << " ";
            std::cout << std::setfill('0') << std::setw(3) << tmp;
        }
        std::cout << std::endl;
    }
    return 0;
}