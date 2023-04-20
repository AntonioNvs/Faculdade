#ifndef OPERATION
#define OPERATION

struct OperatorFormat {
    char value;
    int index;
};

struct NumberFormat {
    double value;
    int index;
};

struct NodeOperation {
    char op;
    double value;
    NodeOperation* left = nullptr;
    NodeOperation* right = nullptr;

    NodeOperation() {};
    NodeOperation(double v) : value(v) {};
    NodeOperation(char o, NodeOperation* l, NodeOperation *r) : op(o), left(l), right(r) {};
};

struct NodeFormat {
    NodeOperation * value;
    int index;
};

#endif