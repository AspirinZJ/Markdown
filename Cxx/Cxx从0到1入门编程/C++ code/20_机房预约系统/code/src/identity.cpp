// Created by jackzhang on 2021/2/18.

#include "identity.h"


Identity::Identity() = default;

Identity::Identity(std::string name, std::string passwd) : m_name(std::move(name)), m_passwd(std::move(passwd))
{

}

Identity::~Identity() = default;
