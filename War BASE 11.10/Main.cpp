#include <iostream>

using namespace std;



/*1. ��� ����� �� ����������� ����� Base, � � ��� - ������ ���������� :
int people_on_base; -���������� ����� �� ���������� ����;
int vehicles_on_base; -���������� ������������ ������� �� ���������� ����;
double petrol_on_base; -���������� ������� �� ������� "��������" (� ������);
double goods_on_base; -���������� "�����" - ��������� ������������ ���������(� ������).
��� ��� ���� � ��� ����, � ��������� ���� �� �� ��������� �� ���������� - �� ��� ���� �����������������.
��������� �������� ����������������� ���������� ����� ������ ����������� �� ������ ����������.*/


class Base {
public:
	static int people_on_base; 
	static int vehicles_on_base;
	static double petrol_on_base;
	static double goods_on_base;
};
int Base::people_on_base = 0;
int Base::vehicles_on_base = 0;
double Base::petrol_on_base = 0.0;
double Base::goods_on_base = 0.0;
/*2. �����, ��� ���������� ����������� �������� ������� ������������ ������� :
������� �����Vehicle�("������������ ��������").����������� ����� ���������, �� �����, �� ���������� �� ���������, ���������� ��������� ���������� �������.
��������� ������ Vehicle - �����Bus�("������ ��� ��������� ������� �������" - �������).���������� �� Vehicle ���, ��� ����� ��������� ���������� ���� ��� ����������.
��������� ������ Vehicle - �����Truck�("��������").���������� �� Vehicle ���, ��� ����� ���������� ���� ������������ �����(���������� � ������).*/

/*3. � ������ ������ ������� �������arrive()�(�������� �� ����) �leave()�(�������� ���������� ����),
������� ��������������� ������� �������� �������� "����������" ���������� ���� (���������� ��� �������� �������� �����, �����, �����, �������).
��� ���� ������ ������ ����� ������������������������� ��������� ������ ��� �������,
������ ������������������������ � ����� ��� ����� ������ �����,
������ �������� - ��� ����� ������ �����(���� ���� ���������� ������������ �� ����� ����� ���������� � �������� ������).
��� ������� �� ���������� ���� ������ ������������� �������� ��� ��������� (� ��������) ������������ (����������� "�� ������" ����),
���� ����������� (�� ������ �� ���������).
*/

/*4.���������� ������ Vehicle������� �������� �� ��������� �������:
Vehicle(double petrol_amount, double tank_volume);
double getTankVolume(); - ������ ����� ��������� � ������;
double getPetrolAmount(); - ������ ������� ���������� ������� � ����;
void arrive(); - �������� �� ����;
boolean leave(); - ������ ������ ��� � �������� ����; � ������ ������������� ������ ���������� false;
*/
class Vehicle
{
private:
	double petrol_amount;
	double tank_volume;
public:
	Vehicle(double petrol_amount, double tank_volume) : petrol_amount(petrol_amount), tank_volume(tank_volume) {}

	double getTankVolume()
	{
		return tank_volume;
	}
	double getPetrolAmount()
	{
		return petrol_amount;
	}
	void arrive()
	{
		Base::vehicles_on_base++;
	}
	bool leave()
	{

		if (Base::people_on_base > 0 && petrol_amount >= tank_volume)
		{
			petrol_amount = 0.0;

			Base::people_on_base--;
			Base::vehicles_on_base--;

			return true;
		}

	
		return false;
	}

};


/*5.���������� ������ Bus���������� ��������� ������ Vehicle ���������� ����������:
Bus(int people, int max_people, double petrol, double max_petrol);
int getPeopleCount(); - �������� ������� ���������� ���������� (�������� � ��� ����� �� ������);
int getMaxPeople(); - �������� ���������� ������������ ����;
- �������� arrive() � leave(), �����������,������������������� �������� ��-������� - ���������/������, ������ �������� � �������, ����� �����.
*/

class Bus : public Vehicle
{
private:

	int people;
	int max_people;

public:
	Bus(int people, int max_people, double petrol, double max_petrol)
		: Vehicle(petrol, max_petrol), people(people), max_people(max_people) {}

	int getPeopleCount()
	{
		return people;
	}
	int getMaxPeople()
	{
		return max_people;
	}
	void arrive()
	{
		Vehicle::arrive();
		Base::people_on_base += people;
	}
	bool leave() 
	{
		if (Vehicle::leave() && Base::people_on_base >= people) {
			Base::people_on_base -= people;
			return true;
		}
		return false;
	}
};


/*6.���������� ������ Truck���������� ��������� ������ Vehicle ���������� ����������:
Truck(double load, double max_load, double petrol, double max_petrol);
double getCurrentLoad(); - �������� ������� ������������� ������ (����� ����� � ������);
double getMaxLoad(); - ������ ������������ ��������������� (����������������) ������;
- �������� arrive() � leave(), �����������, ���������������� � �������� ��-������� - ���������/������, ������ �������� � �������, ����� ������������ ��������.
*/

class Truck : public Vehicle
{
private:
	double load;
	double max_load;
public:

	Truck(double load, double max_load, double petrol, double max_petrol)
		: Vehicle(petrol, max_petrol), load(load), max_load(max_load) {}

	double getCurrentLoad() 
	{
		return load;
	}
	double getMaxLoad()
	{
		return max_load;
	}

	void arrive()
	{
		Vehicle::arrive();
		Base::goods_on_base += load;
	}

	bool leave()
	{
		if (Vehicle::leave() && Base::goods_on_base >= load) {
			Base::goods_on_base -= load;
			return true;
		}
		return false;
	
	}
};





/*����������� �����������
��������� ������ ������ �������� � ��������� �����.
���� � ��� ��������� ������� � ����� ����� - ��� ������ ���� ����������� "�����". �������� ���� ������ ������ ������ �� ������� (�� ��� ���� ������ ���� �� ��� ����� ���� "public").
"����������" ����������� ���������� XXXX_on_base, �����������, �� ����� ���� ������ ����, � ���� ������ (������, ������ arrive() � leave()) ������ �� ���� �������.
�� ������� �� ���� ������ ��������� � "�������" ���� ���� (vehicles_on_base), ������ �������� (people_on_base), ���� ����� ���������� ��� ����.
���� ��� ������� ������ (leave()) ������ �� ����� ������ ������ ��� ��� �� ���� �� �������� �� ������ �������� (��� ��������), ������ ������������ ����� � ���������� false.
���������: ����� �������, ��� ������ �� �������������� �� ���������- ��������� �� ����� ����� ������� � ����.
������� � �������� ��� ������� ������ ����� ���� ����� ��� ��, ��� Vehicle, �� ������������� - �������� ������ ������ ����� ����� ��� ������ ����� ����� ��������������. 
���� �� ���� �������� ����� ��� ����� ������, ��� ������� ������ ������ - ��� �������� �������, ������� ����*/

int main() {

	Vehicle vehicle(50.0, 50.0);
	vehicle.arrive();

	if (vehicle.leave()) {
		cout << "Vehicle left.\n";
	}
	else {
		cout << "Vehicle cannot leave.\n";
	}

	Bus bus(20, 50, 100.0, 100.0);
	bus.arrive();

	if (bus.leave()) {
		cout << "Bus left.\n";
	}
	else {
		cout << "Bus cannot leave.\n";
	}

	Truck truck(20, 50, 50.0, 100.0);
	truck.arrive();

	if (truck.leave()) {
		cout << "Truck left.\n";
	}
	else {
		cout << "Truck cannot leave.\n";
	}

	cout << "people_on_base: " << Base::people_on_base << endl;
	cout << "vehicles_on_base: " << Base::vehicles_on_base << endl;
	cout << "petrol_on_base: " << Base::petrol_on_base << endl;
	cout << "goods_on_base: " << Base::goods_on_base << endl;

	return 0;
}


