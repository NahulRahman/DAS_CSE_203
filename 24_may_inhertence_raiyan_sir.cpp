#include<iostream>
using namespace std;
class Student{
    int theory,sessional;
public:
    void setmarks(int theory, int sessional){
        this->theory=theory;
        this->sessional=sessional;
    }
    int gettheory(){
        return theory;
    }
    int getsessional(){
        return sessional;
    }
};
class L4student:public Student{
    int thesis;
public:
    void setthesis(int thesis){
        this->thesis=thesis;
    }
    int getthesis(){
        return thesis;
    }
};
int main(){
    L4student S1;
    S1.setmarks(5,10);
    S1.setthesis(15);
    cout<<"the student got "<<S1.gettheory()<<" in theory, "<<S1.getsessional()<<" in sessional and  "<<S1.getthesis()<<" in L4 thesis"<<endl;
}
