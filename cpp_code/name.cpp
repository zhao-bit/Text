#include <iostream>
#include <string>

int main() {
    std::string name;
    std::cout << "请输入你的名字：";
    std::getline(std::cin, name);
    std::cout << "你好，" << name << "！欢迎学习C++。" << std::endl;
    return 0;
}
