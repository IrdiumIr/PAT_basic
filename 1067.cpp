// 1067 试密码 分数 20

// 当你试图登录某个系统却忘了密码时，系统一般只会允许你尝试有限多次，当超出允许次数时，账号就会被锁死。
// 本题就请你实现这个小功能。

#include <iostream>

int main()
{
    std::string password;
    int N = 0;
    std::cin >> password >> N;
    getchar();

    std::string tmp;
    int cnt = 0;

    while (true) {
        std::getline(std::cin, tmp);

        if (tmp == "#")
            break;
        ++cnt;
        
        if (cnt <= N && tmp != password) {
            std::cout << "Wrong password: " << tmp << std::endl;
            if (cnt == N) {
                std::cout << "Account locked";
                break;
            }
        } else if (cnt <= N && tmp == password) {
            std::cout << "Welcome in" << std::endl;
            break;
        }
    }
    return 0;
}