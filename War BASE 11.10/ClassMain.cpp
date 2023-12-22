//#include <iostream>
//#include "Figure.cpp"
//#include "ABCD.cpp"
//using namespace std;
//
//#include <cstdio>
//
//
//
//void Foo(const int* value)
//{
//    // const_cast<результирующий_тип>(преобразуемое_выражение);
//
//    int* constless = const_cast<int*>(value);
//
//    *constless = 100;
//
//    cout << "Address: " << constless << endl << "Value: " << *constless << endl;
//}
////
////int main()
////{
////    /*const int size = 10;
////    cout << "address: " << &size << endl << "value: " << size << endl;
////    Foo(&size);
////    cout << "address: " << &size << endl << "value: " << size << endl;
////*/
////
////
////    ////////////////////////////////////////////////////////////////////
////
////
////   /* Circle obj(10);
////    Test(obj);
////    Test(1);
////    Test(1.4);
////    Test('a');
////
////
////
////    system("pause");
////    return 0;
////*/
////
////
////    ////////////////////////////////////////////////////////////////////
////
////
////
////
////
////
////
////    //int number = 65;
////    ////static_cast<результирующий_тип>(преобразуемое_выражение);
////    //cout << static_cast<char>(number) << endl;
////    //cout << char(number) << endl;
////    //cout << (char)number << endl;
////
////    //
////
////    //1.  reinterpret_cast<результирующий_тип>(преобразуемое_выражение);
////
////    char string[] = "This is a string";
////    int address = reinterpret_cast<int>(string);
////    /*char* ptr = &string[0];
////    cout<< ptr << endl;*/
////    cout << address << endl;
////    cout << (char*)address << endl;
////
////
////
////
////    system("pause");
////
////    ////////////////////////////////////////////////////////////////////
////
////    const unsigned int  size = 10;
////
////    A* objects[size] = {};
////
////    B* objectB = nullptr;
////    C* objectC = nullptr;
////    D* objectD = nullptr;
////
////    unsigned int countA = 0U;
////    unsigned int countB = 0U;
////    unsigned int countC = 0U;
////    unsigned int countD = 0U;
////
////    // dynamic_cast<результирующий_тип>(преобразуемое_выражение);
////
////    for (unsigned int i = 0U; i < size; ++i)
////    {
////        objects[i] = Generator();
////
////        objectD = dynamic_cast<D*>(objects[i]);
////
////        if (objectD != nullptr)
////        {
////            ++countD;
////        }
////        else
////        {
////            objectC = dynamic_cast<C*>(objects[i]);
////
////            if (objectC != nullptr)
////            {
////                ++countC;
////            }
////            else
////            {
////                objectB = dynamic_cast<B*>(objects[i]);
////
////                if (objectB != nullptr)
////                {
////                    ++countB;
////                }
////                else
////                {
////                    ++countA;
////                }
////            }
////        }
////
////        objects[i]->Show();
////    }
////
////    cout << "Quantity of object A: " << countA << endl;
////    cout << "Quantity of object B: " << countB << endl;
////    cout << "Quantity of object C: " << countC << endl;
////    cout << "Quantity of object D: " << countD << endl;
////
////
////
////
////
////
////
////
////
////
////
////}