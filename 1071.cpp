// 1071 小赌怡情 (15 分)
// 常言道“小赌怡情”。这是一个很简单的小游戏：
// 首先由计算机给出第一个整数；然后玩家下注赌第二个整数将会比第一个数大还是小；
// 玩家下注 t 个筹码后，计算机给出第二个数。若玩家猜对了，则系统奖励玩家 t 个筹码；
// 否则扣除玩家 t 个筹码。

// 注意：玩家下注的筹码数不能超过自己帐户上拥有的筹码数。当玩家输光了全部筹码后，游戏就结束。

#include <iostream>

int main()
{
    int T = 0, K = 0, n1 = 0, b = 0, t = 0, n2 = 0;
    std::cin >> T >> K;// 输入总筹码T，次数K
    for (auto i = 0; i != K; ++i)
    {
        std::cin >> n1 >> b >> t >> n2;// 输入n1，大小，筹码，n2
        int ans = (n1 > n2) ? 0 : 1;// b=0小b=1大
        if (T == 0)// 用完了
        {
            std::cout << "Game Over." << std::endl;
            return 0;
        }
        else if (t > T)// 不够
            std::cout << "Not enough tokens.  Total = " << T << "." << std::endl;
        else if (ans == b)// 够的情况下 押对
        {
            T += t;
            std::cout << "Win " << t << "!  Total = " << T << "." << std::endl;
        }
        else if (ans != b)
        {
            T -= t;
            std::cout << "Lose " << t << ".  Total = " << T << "." << std::endl;
        }
    }
    return 0;
}