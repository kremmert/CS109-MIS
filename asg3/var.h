

class Var {
public:
    Var();
    Var(const Var& orig);
    virtual ~Var();
    void decode();
private:
    std::vector<std::string> insns;
    std::string varType;
    std::string name;
    std::string type;
    std::string val;
    int num;

};
