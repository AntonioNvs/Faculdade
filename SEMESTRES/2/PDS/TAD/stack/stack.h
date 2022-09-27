class Stack {
  private:
    int *arr;
    int max_size;
    int top;
  
  public:
    // Constructor
    Stack();
    
    // Destructor
    ~Stack();

    void push(int val);

    void pop();

    int get_top();

    bool empty();
};