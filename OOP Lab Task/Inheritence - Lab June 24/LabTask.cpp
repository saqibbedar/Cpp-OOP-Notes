#include <iostream>
using namespace std;

class University
{
protected:
    int total;
    int bs;
    int phd;
public:
    University(){
        bs = 0;
        phd = 0;
        total = 0;
    }
    University(int x){
        total += x;89
    };
    void setBcs(int x){
        bs = x;
    }
    void set_phd(int x){
        phd = x;
    }
    int get_phd(){
        return phd;
    }
    int get_bs(){
        return bs;
    }
};
class BScs_Students : public University
{
    public:
    BScs_Students(int x){
        setBcs(x);
        cout<<"Students ratio in BScs is: "<<x<<endl;
    }
};
class PHD_Students : public University
{
    public:
    PHD_Students(int x){
        set_phd(x);
        cout<<"Students ratio in PHD is: "<<x<<endl;
    }
};

int main()
{
    BScs_Students b(20);
    PHD_Students p(50);
     int total = b.get_bs() + p.get_phd();
     cout<<"Total no. of students: "<<total<<endl;
    return 0;
}

