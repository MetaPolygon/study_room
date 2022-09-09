#include "class.h"

pUser this;

static void _setAge(uInt);
static void _setHeight(double);
static void _setWeight(double);
static uInt _getAge(void);
static double _getHeight(void);
static double _getWeight(void);
static void _printUserInfo(void);

pUser newUser(uInt age, double height, double weight)
{
    this = (pUser)malloc(sizeof(User));
    this->setAge = _setAge;
    this->setHeight = _setHeight;
    this->setWeight = _setWeight;
    this->getAge = _getAge;
    this->getHeight = _getHeight;
    this->getWeight = _getWeight;
    this->printUserInfo = _printUserInfo;
    this->setAge(age);
    this->setHeight(height);
    this->setWeight(weight);
    return this;
}

static void _setAge   (uInt _age)      { this->age = _age; }
static void _setHeight(double _height) { this->height = _height; }
static void _setWeight(double _weight) { this->weight = _weight; }
static uInt _getAge(void)              { return this->age; }
static double _getHeight(void)         { return this->height; }
static double _getWeight(void)         { return this->weight; }
static void _printUserInfo(void)
{
    puts(  "-------[user info]-------");
    printf(" age    : %u\n", this->getAge());
    printf(" height : %.2lf\n", this->getHeight());
    printf(" weight : %.2lf\n", this->getWeight());
    puts(  "-------------------------");
}
