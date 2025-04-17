class Summator {
public:
    virtual ~Summator() = default;
    virtual int transform(int i) const;
    int sum(int N) const;
};