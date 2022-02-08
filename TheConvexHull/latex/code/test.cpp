class Test {
private:
    int n;
    std::vector<int> vec;

public:
    // this is a comment
    void method(int x)
    {
        if (n < vec.size())
            vec.push(x);
    }
};