typedef uint32_t ui;

bool limited, console, toN;
ui _max, special;

class MyPrime {
public:
    MyPrime();

    void go();

    void write();

private:
    std::vector<int> prime;
    ui Size = 0;
    const ui maximum = INT32_MAX;

    void build();

    void build_to_n(ui max);

    void build_n(ui max);

    void resize(ui size);

    void clear();

    void push_back(ui value);

    static bool isPrime(ui k);

    void to_console();

    void to_file();
};