#include <iostream>


class A {
private:
    int n, k;

public:
    A() : n(0), k(0) {};

    A(const int n, const int k) : n(n), k(k)
    {};

    int getsum()
    {
        return n + k;
    }

    int getprod()
    {
        return n * k;
    }

  //~A() = delete;
  //A(A& A)=delete;
  //A& operator=(const A& a)=delete;
    A& operator+=(const A& a) {
        this->k += a.k;
        this->n += a.n;

        return *this;
  }

    A& operator-=(const A& a) {
        this->k -= a.k;
        this->n -= a.n;

        return *this;
    }
   
    A& operator*=(const A& a) {
        this->k *= a.k;
        this->n *= a.n;

        return *this;
    }

    A& operator/=(const A& a) {
        this->k /= a.k;
        this->n /= a.n;

        return *this;
    }

    A& operator^=(const A& a) {
        this->k ^= a.k;
        this->n ^= a.n;
    return *this;
    }
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

class C {
private:
    A* a;
public:
    C(A a1) : a(new A(a1)) {}
    ~C() { delete a; }

    int perimetru() {
        return 2 * a->getsum();
    }

    int area() {
        return a->getprod();
    }

    C& operator=(const C& c); // declarare operator=

};

C& C::operator=(const C& c)  // definire C::operator=
{
    A* pOrig = a;
    a = new A(*c.a);
    delete pOrig;
    return *this;
}

class D : public A {
private:
    int z;
public:
    D() : A(), z(0) {}
    D(int n, int k, int z1) : A(n, k), z(z1) {}
    D& operator=(const D d)
    {
        A::operator=(d);
        z = d.z;
        return *this;
    }

    D& operator+=(const D d)
    {
        A::operator+=(d);
        z += d.z;
        return *this;
    }

    int getz() {
        return z;
    }

    int getsum()
    {
        return A::getsum()+z;
    }

    int getprod()
    {
        return A::getprod() * z;
    }
  };



int main()
{
    std::cout << "Tema 2\n";
    A a1(2, 3), a2, a3,a4(3,1);
    a3 = a2 = a1;
    std::cout << "Item 10\n";
    std::cout << "Obiect a1: suma= " << a1.getsum() << " produs= " << a1.getprod()<<'\n';
    std::cout << "Obiect a2: suma= " << a2.getsum() << " produs= " << a2.getprod() << '\n';
    std::cout << "Obiect a3: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
    a3 += a3;
    std::cout << "Obiect a3 dupa a3+=a3: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
    a3-= a2;
    std::cout << "Obiect a3 dupa a3-=a2: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
    a3 *= a2;
    std::cout << "Obiect a3 dupa a3*=a2: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
    a3 /= a2;
    std::cout << "Obiect a3 dupa a3/=a2: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
    a3 ^= a3;
   // a3 ^= a4;
    std::cout << "Obiect a3 dupa a3^=a3: suma= " << a3.getsum() << " produs= " << a3.getprod() << '\n';
   //Item 11
    std::cout << "\nItem 11\n";
    C c1(a1), c2(a3);
    std::cout << "Obiect c1: perimetru  " << c1.perimetru() << " area= " << c1.area() << '\n';
    c1 = c1;
    std::cout << "Obiect c1 dupa atribuire c1=c1: perimetru  " << c1.perimetru() << " area= " << c1.area() << '\n';
    std::cout << "Obiect c2: perimetru  " << c2.perimetru() << " area= " << c2.area() << '\n';
    c2 = c1;
    std::cout << "Obiect c2 dupa c2=c1: perimetru  " << c2.perimetru() << " area= " << c2.area() << '\n';
// Item 12
    std::cout << "\nItem 12\n";
    D d1(2, 3, 4), d2, d3;
    d3 = d2 = d1;
    std::cout << "Obiect d1: suma= " << d1.getsum() << " produs= " << d1.getprod() << " z= "<< d1.getz()<<'\n';
    std::cout << "Obiect d2: suma= " << d2.getsum() << " produs= " << d2.getprod() << " z= " << d2.getz() << '\n';
    std::cout << "Obiect d3: suma= " << d3.getsum() << " produs= " << d3.getprod() << " z= " << d3.getz() << '\n';
    d3 += d2;
    std::cout << "Obiect d3 dupa d3+=d2: suma= " << d3.getsum() << " produs= " << d3.getprod() << " z= " << d3.getz() << '\n';
    return 0;
}
