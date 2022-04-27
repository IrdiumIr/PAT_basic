// 1068 万绿丛中一点红 分数 20

// 对于计算机而言，颜色不过是像素点对应的一个 24 位的数值。
// 现给定一幅分辨率为 M×N 的画，要求你找出万绿丛中的一点红，即有独一无二颜色的那个像素点，
// 并且该点的颜色与其周围 8 个相邻像素的颜色差充分大。

#include <iostream>
#include <vector>
#include <map>

std::vector<std::vector<int>> surround{{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
int M = 0, N = 0, TOL = 0;
std::vector<std::vector<int>> ivec;// N*M

bool check(int i, int j) {
    for (int k = 0; k != 8; ++k) {
        auto cmp_x = i + surround[k][0];
        auto cmp_y = j + surround[k][1];
        if (cmp_x >= 0 && cmp_x < N && cmp_y >= 0 && cmp_y < M && std::abs(ivec[i][j] - ivec[cmp_x][cmp_y]) <= TOL)
            return false;
    }
    return true;
}
int main()
{
    std::cin >> M >> N >> TOL;
    ivec.resize(N, std::vector<int>(M));

    int cnt = 0, pos_x = 0, pos_y = 0;
    std::map<int, int> dic;

    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            scanf("%d", &ivec[i][j]);
            ++dic[ivec[i][j]];
        }
    }

    for (int i = 0; i != N; ++i) {
        for (int j = 0; j != M; ++j) {
            if (check(i, j) == true && dic[ivec[i][j]] == 1) {
                ++cnt;
                pos_x = i + 1;
                pos_y = j + 1;
            }
        }
    }

    if (cnt == 1) {
        printf("(%d, %d): %d", pos_y, pos_x, ivec[pos_x - 1][pos_y - 1]);
    } else if (cnt == 0) {
        printf("Not Exist");
    } else {
        printf("Not Unique");
    }
    return 0;
}