#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int uInt;

static struct _user {
    uInt age;
    double height;
    double weight;
    /*
    static uInt age;        // wrong
    static double height;   // wrong
    static double weight;   // wrong
    struct member can't have a memory classification specifier.
    so, access modifiers are difficult to make :(
    */
    void (*setAge)(uInt);
    void (*setHeight)(double);
    void (*setWeight)(double);
    uInt (*getAge)(void);
    double (*getHeight)(void);
    double (*getWeight)(void);
    void (*printUserInfo)(void);
}_user;

typedef struct _user User, *pUser;

extern pUser newUser(uInt age, double height, double weight);
