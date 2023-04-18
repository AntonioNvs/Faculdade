#ifndef OPERATION
#define OPERATION

struct Operation {
    char op;
    float value;
    Operation* left;
    Operation* right;
};

#endif