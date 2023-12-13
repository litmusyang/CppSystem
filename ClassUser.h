
#ifndef CLASSUSER_H
#define CLASSUSER_H
#include <vector>
#include <cstring>
#include <string>

class User
{
public :
    std::string myname;
    std::vector<std::string> courselist; //课程目录
    int coursenumber = 0; //课程总数
    void Display_the_Course(std::vector<std::string> courselist) const; //查看所有课程
    int SearchCourseName(const std::string& coursename);
    //在课程目录中查找课程，返回课程在课程目录中的位置，未找到则返回-1
    User(std::string username);
    virtual ~User() = 0;
    void reset(std::string username) ; // 赋值
    User(const User& x); //拷贝构造
    virtual void Delete(std::string myname) = 0;  //注销
    virtual void LogIn() = 0;
};

class Teacher : public User
{
private:
    void Set_Up_a_Course(const std::string& coursename); //创建课程
    void End_the_Course(const std::string& coursename); //解散课程

public:
    void LogIn() override; //登录
    Teacher(const char username[] = "Anonymous") : User(username)
    {
    }; //注册
    ~Teacher();
    void Delete(std::string myname); //注销

};

class Assistant : public User
{
public:
    void LogIn(); //登录
    explicit Assistant(const const std::string&& username = "Anonymous") : User(std::move(username))
    {
    }; //注册
    ~Assistant() override;
    void Delete(std::string myname) override; //注销
};
#endif //CLASSUSER_H
