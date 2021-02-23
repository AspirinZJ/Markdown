// Created by jackzhang on 2021/2/18.

#ifndef INC_20__IDENTITY_H
#define INC_20__IDENTITY_H


#include <string>
#include <utility>

// 身份抽象类, 作为学生、教师和管理员的抽象基类
class Identity
{
public:
	virtual void operMenu() = 0;    // 操作菜单, 纯虚函数
	Identity();
	Identity(std::string, std::string);
	std::string m_name;    // 用户名
	std::string m_passwd;    // 密码
	virtual ~Identity();
};


#endif //INC_20__IDENTITY_H
