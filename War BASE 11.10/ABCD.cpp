//#include <iostream>
//
//#include<typeinfo>
//
//using namespace std;
//
//
//class A
//{
//public:
//
//    virtual void Show() const {
//        cout << "Class A" << endl;
//    }
//};
//
//
//class B :
//    public A
//{
//public:
//
//    virtual void Show() const {
//        cout << "Class B" << endl;
//    }
//};
//
//
//
//class C :
//    public B
//{
//public:
//
//    virtual void Show() const {
//        cout << "Class C" << endl;
//    }
//};
//
//class D :
//    public C
//{
//public:
//
//    virtual void Show() const {
//        cout << "Class D" << endl;
//    }
//};
//
//
//
//A* Generator()
//{
//    A* object = nullptr;
//
//    int choice = rand() % 4;
//
//    switch (choice)
//    {
//    case 0:
//        object = new A;
//        break;
//    case 1:
//        object = new B;
//        break;
//    case 2:
//        object = new C;
//        break;
//    case 3:
//        object = new D;
//        break;
//    }
//
//    return object;
//}