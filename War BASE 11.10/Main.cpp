#include <iostream>

using namespace std;



/*1. Для этого вы разработали класс Base, а в нем - четыре переменные :
int people_on_base; -количество людей на территории базы;
int vehicles_on_base; -количество транспортных средств на территории базы;
double petrol_on_base; -количество бензина на местной "заправке" (в литрах);
double goods_on_base; -количество "груза" - различных материальных ценностей(в тоннах).
Так как база у нас одна, и несколько штук мы их создавать не собираемся - то все поля будут статическими.
Начальные значения вышеперечисленных переменных можно задать произвольно по своему усмотрению.*/


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
/*2. Далее, Вам необходимо разработать иерархию классов транспортных средств :
Базовый класс Vehicle ("транспортное средство").Управляется одним водителем, ни груза, ни пассажиров не перевозит, потребляет некоторое количество топлива.
Наследник класса Vehicle - класс Bus ("машина для перевозки личного состава" - автобус).Отличается от Vehicle тем, что имеет некоторое количество мест для пассажиров.
Наследник класса Vehicle - класс Truck ("грузовик").Отличается от Vehicle тем, что может перевозить груз ограниченной массы(измеряется в тоннах).*/

/*3. В каждом классе имеются методы arrive() (приехать на базу) и leave() (покинуть территорию базы),
которые соответствующим образом изменяют значения "балансовых" переменных базы (прибавляют или убавляют счетчики людей, машин, груза, бензина).
При этом каждая машина перед отъездом обязательно должна заправить полный бак бензина,
каждый автобус старается забрать с собой как можно больше людей,
каждый грузовик - как можно больше груза (ваша база потихоньку перемещается на новое место дислокации в соседней стране).
При приезде на территорию базы нового транспортного средства его пассажиры (и водитель) высаживаются (добавляются "на баланс" базы),
груз выгружается (но бензин не сливается).
*/

/*4. Интерфейс класса Vehicle должен состоять из следующих методов:
Vehicle(double petrol_amount, double tank_volume);
double getTankVolume(); - узнать объем бензобака в литрах;
double getPetrolAmount(); - узнать текущее количество топлива в баке;
void arrive(); - приехать на базу;
boolean leave(); - залить полный бак и покинуть базу; в случае невозможности уехать возвращает false;
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


/*5. Интерфейс класса Bus расширяет интерфейс класса Vehicle следующими операциями:
Bus(int people, int max_people, double petrol, double max_petrol);
int getPeopleCount(); - получить текущее количество пассажиров (водитель в это число не входит);
int getMaxPeople(); - получить количество пассажирских мест;
- операции arrive() и leave(), естественно, переопределяются и работают по-другому - выгружают/увозят, помимо водителя и бензина, также людей.
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


/*6. Интерфейс класса Truck расширяет интерфейс класса Vehicle следующими операциями:
Truck(double load, double max_load, double petrol, double max_petrol);
double getCurrentLoad(); - получить текущую загруженность машины (масса груза в тоннах);
double getMaxLoad(); - узнать максимальную вместительность (грузоподъемность) машины;
- операции arrive() и leave(), естественно, переопределяются и работают по-другому - выгружают/увозят, помимо водителя и бензина, также материальные ценности.
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





/*Технические подробности
Отдельные классы удобно помещать в отдельные файлы.
Если у вас несколько классов в одном файле - они должны быть расположены "рядом". Помещать одни классы внутрь других не следует (но при этом только один из них может быть "public").
"Балансовые" статические переменные XXXX_on_base, естественно, не могут быть меньше нуля, и ваши классы (вернее, методы arrive() и leave()) должны за этим следить.
По приезде на базу машина добавляет к "балансу" базы себя (vehicles_on_base), своего водителя (people_on_base), всех своих пассажиров или груз.
Если при попытке уехать (leave()) машина не может залить полный бак или на базе не осталось ни одного человека (нет водителя), машина отказывается ехать и возвращает false.
Замечание: будем считать, что машине не нужен конкретно ее водитель - управлять ей может любой человек с базы.
Автобус и грузовик при попытке уехать ведут себя точно так же, как Vehicle, но дополнительно - пытаются увезти полный салон людей или полный кузов груза соответственно. 
Если на базе осталось людей или груза меньше, чем вмещает данная машина - она забирает столько, сколько есть*/

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


