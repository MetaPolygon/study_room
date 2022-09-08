#include "class.h"

pUser this;//last...

static void _setAge(uInt);
static void _setHeight(double);
static void _setWeight(double);
static void _printUserInfo(void);

pUser newUser(uInt age, double height, double weight)
{
    this = malloc(sizeof(User));
    this->setAge = _setAge;
    this->setHeight = _setHeight;
    this->setWeight = _setWeight;
    this->setAge(age);
    this->setAge(height);
    this->setAge(weight);
    this->printUserInfo = _printUserInfo;
    return this;
}

static void _setAge   (uInt _age)       { this->age = _age; }
static void _setHeight(double _height) { this->height = _height; }
static void _setWeight(double _weight) { this->weight = _weight; }

static void _printUserInfo(void)
{
    printf("age    : %u\n", this->age);
    printf("height : %lf\n", this->height);
    printf("weight : %lf\n", this->weight);
}
