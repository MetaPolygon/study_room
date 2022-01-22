#include "class.h"

static void constructor();
static void printInfo();

static likeClass this = { //list of function_name or value
    0, constructor, printInfo
};

static void constructor(int num) {
    this.num = num;
}

static void printInfo() {
    printf("{num  : %d}\n", this.num);
}

pLikeClass likeClass_ctor(int num, ...) { // for "this pointer"
    constructor(num);
    return &this;
}
