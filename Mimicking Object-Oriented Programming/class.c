#include "class.h"

pUser this;//last...

static void _setAge(unsigned int);
static void _printUserInfo();

pUser newUser(unsigned int age)
{
    this = malloc(sizeof(User));
    this->self = this;
    this->setAge = _setAge;
    this->setAge(age);
    this->printUserInfo = _printUserInfo;
    return this;
}

static void _setAge(unsigned int age)
{
    this->age = age;
}

static void _printUserInfo()
{
    printf("age : %u\n", this->age);
}
