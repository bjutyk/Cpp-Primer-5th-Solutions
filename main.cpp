#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
#include <string>
using std::string;
#include <sstream>
using std::ostringstream;

//在定义任何函数之前，先声明所有重载的函数版本
//这样做可避免编译器由于未遇到希望调用的函数而实例化一个并非所需的版本
template <typename T> string debug_rep(T *p);

//为了使debug_rep(char *)正确工作，下面的声明必须在作用域中
string debug_rep(const string &);
template <> string debug_rep(const char *p);
template <> string debug_rep(char *p);

//打印任何我们不能处理的类型
template <typename T>
string debug_rep(const T &t){
    ostringstream ret;
    ret << t;
    return ret.str();
}

//打印指针的值，后跟指针指向的对象
//此函数不能用于char *，因为IO库为char *值定义了一个<<版本
//此<<版本假定指针表示一个空字符结尾的字符数组，并打印数组的内容而非地址值
template <typename T>
string debug_rep(T *p){
    ostringstream ret;
    ret << "pointer: " << p;    //打印指针本身的值（即地址）
    if (p)
        ret << " " << debug_rep(*p);    //打印p指向的值
    else
        ret << " null pointer";
    return ret.str();
}

string debug_rep(const string &s){
    return '"' + s + '"';
}

template <>
string debug_rep(const char *p){
    return debug_rep(string(p));
}

template <>
string debug_rep(char *p){
    return debug_rep(string(p));
}

int main() {}