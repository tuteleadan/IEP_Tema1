#include <iostream>


class A {
private:
    int n, k;
    std::string nume;
public:
    A(const int n, const int k, const std::string& s) : n(n), k(k), nume(s)
    {};

    int getsum()
    {
        return n + k;
    }

    int getprod()
    {
        return n * k;
    }

    std::string get_nume()
    {
        return nume;
    }
  //~A() = delete;
  A(A& A)=delete;
  A& operator=(const A& a)=delete;
 
  
};

class B {
private:
    int x, y;
 public:
     B(const int x, const int y) :x(x), y(y)
     {};
     B() :x(0), y(0)
     {};
     int getx() { return x; }
};
B& b()
{
    static B b0(1,-1); // obiect static nelocal
    return b0;
}


int main()
{

    std::cout << "Tema 1\n";
    A a1(2, 3, "ion");
    std::cout << "Numele elementului a1 este " << a1.get_nume() << " Suma elmentelor int este " << a1.getsum() << '\n';
    //std::cout << "Initializarea lui a2 se face utilizand constructorul de copiere\n";
    //A a2(a1);
    
    //std::cout << "Numele elementului a2 este " << a2.get_nume() << " Suma elmentelor int este " << a2.getsum() << '\n';
   
   
    A a3(5, 4, "ads");
    std::cout << "Numele elementului a3 este " << a3.get_nume() << " Suma elmentelor int este " << a3.getsum() << '\n';
    //std::cout << "Copiem a3 in a2 utilizand operatorul de copiere asignare implicit \n";
    //a2 = a3;
  //  std::cout << "Numele elementului a2 este " << a2.get_nume() << " Suma elmentelor int este " << a2.getsum() << '\n';
 
  
    std::cout <<"Utilizarea nelocala a lui b0 prin intermediul  functiei b(): b0.x= "<<b().getx();
    return 0;
}