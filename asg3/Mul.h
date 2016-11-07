class Mul {
public:
    Mul();
    Mul(const Mul& orig);
    virtual ~Mul();
private:
	template<typename T, typename... num>
    T multiply(T res, num... args);


};
