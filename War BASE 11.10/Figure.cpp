//#include <iostream>
//
//
//#include <typeinfo>
//
//using namespace std;
///*
//��������� ������������� ���� ������� ���������� (run - time type identification � RTTI) ����� ���������� ��� ������� �� ����� ���������� ���������.
//��� ����� ������������ ������� typeid. ��� ������������� ���� ������� ���������� �������� ������������ ���� typeinfo. ����� ����� ������ ������� typeid ����� ��������� ��� :
//
//typeid (������)
//
//����� ������ �������� ��������, ��� ��� ��������� ����������.������� typeid ���������� ������ �� ������ ���� typeinfo, ������� ��������� ��� �������. (� ������� ��������� �++ ���� ��� ���������� type_info.)
//*/
//
//
//
//
//
//
//
//
//template<typename T>
//void Test(T a)
//{
//    cout << typeid(a).name() << endl; // ��� �������(����������)
//
//}
//
//
//
//
//class Figure
//{
//protected:
//
//    double m_value1;
//    double m_value2;
//
//public:
//
//    Figure(const double value1, const double value2) :
//        m_value1(value1),
//        m_value2(value2)
//    {
//    }
//
//    virtual void ShowArea() const = 0;
//};
//
//
//class Triangle :
//    public Figure
//{
//public:
//
//    Triangle(const double value1, const double value2) :
//        Figure(value1, value2)
//    {
//    }
//
//    void ShowArea() const
//    {
//        cout << "Square of triangle: " << 0.5 * m_value1 * m_value2 << endl;
//    }
//};
//
//
//class Rectangle :
//    public Figure
//{
//public:
//
//    Rectangle(const double value1, const double value2) :
//        Figure(value1, value2)
//    {
//    }
//
//
//    void ShowArea() const {
//        cout << "Square of rectangle: " << m_value1 * m_value2 << endl;
//    }
//
//};
//
//
//class Circle :
//    public Figure
//{
//public:
//
//    Circle(const double value1) :
//        Figure(value1, 0.0)
//    {
//    }
//
//    void ShowArea() const {
//        cout << "Square of circle: " << 3.14159 * m_value1 * m_value2 << endl;
//    }
//};
//
//
//
//Figure* GeneratorOfFigures()
//{
//    Figure* figure = nullptr;
//
//    int choice = rand() % 3;// 0 1 2
//
//    switch (choice)
//    {
//    case 0:
//        figure = new Triangle(10.5, 6.5);
//        break;
//    case 1:
//        figure = new Rectangle(10.5, 6.5);
//        break;
//    case 2:
//        figure = new Circle(10);
//        break;
//    }
//
//    return figure;
//}
