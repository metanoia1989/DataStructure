#include <iostream>
#include <iomanip>
#include <string>

//********************************************************
// 字符串函数示例
//********************************************************

int main(int argc, char const *argv[])
{
    std::string str = "高德纳 美国 计算机科学家 计算机程序设计艺术";
    std::string str_temp = "";
    str_temp.assign(str);

    std::string result[4] = { "", "", "", "" };

    int position = 0;

    for (int i = 0; i < 3; i++) {
        position = str_temp.find(" ");
        result[i] = str_temp.substr(0, position);
        str_temp = str_temp.substr(position+1, str_temp.length() - position);
    }

    result[3] = str_temp; // 取余

    std::cout << "姓名：" << std::setw(8) << result[0] << std::endl;
    std::cout << "国籍：" << std::setw(6) << result[1] << std::endl;
    std::cout << "职业：" << std::setw(14) << result[2] << std::endl;
    std::cout << "代表作：" << std::setw(18) << result[3] << std::endl;

    str_temp.swap(result[0]);

    for(int i = 1; i < 4; i++) {
        str_temp += " ";
        str_temp.append(result[i]);
    }

    int equal = str.compare(str_temp);

    if (equal == 0) {
        std::cout << "Successful Matching!" << std::endl;
    } else {
        std::cout << "Unsuccessful Matching!" << std::endl;
    }

    return 0;
}
