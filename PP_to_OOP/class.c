#include "class.h"

static int test(){
    return 1;
}

static likeClass this = {test};

likeClass *set() {
    return &this;
}
