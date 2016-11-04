
#ifndef SUB_H
#define SUB_H

class Sub {
public:
    Sub();
    Sub(const Sub& orig);
    virtual ~Sub();
private:
	subtract(int, int, int);

};

#endif /* SUB_H */