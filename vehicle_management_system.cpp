#include<iostream>
#include<string>
using namespace std;


//Base Class
class Vehicle {
	//make, model, year, and color.
private:
	string make;
	string model;
	int year;
	string color;

public:
	//Constructor
	Vehicle() {
		make = "";
		model = "";
		year = 0;
		color = "";
	}

	// Parametrized Constructor
	Vehicle(string mk, string mdl, int yr, string clr) {
		make = mk;
		model = mdl;
		year = yr;
		color = clr;
	}

	void setMake(string mk) {
		make = mk;
	}

	void setModel(string mdl) {
		model = mdl;
	}

	void setYear(int yr) {
		year = yr;
	}

	void setColor(string clr) {
		color = clr;
	}

	void display_info() {
		cout << "Make: " << make << endl;
		cout << "Model: " << model << endl;
		cout << "Year: " << year << endl;
		cout << "Color: " << color << endl;
	}
};

class Car : public Vehicle {
private:
	int num_doors;

public:
	//Constructor
	Car() {
		num_doors = 0;
	}

	//Parametrized Constructor

	Car(string mk, string mdl, int yr, string clr, int doors) {
		setMake(mk);
		setModel(mdl);
		setYear(yr);
		setColor(clr);

		num_doors = doors;
	}

	void setNumDoors(int n) {
		num_doors = n;
	}

	bool has_trunk() {
		return num_doors >= 4;
	}

};

//Motorcycle: Inherits from Vehicle.Add an attribute engine_type and a method
//is_two_wheeler that returns True if the motorcycle has two wheels(engine type
//	must be "2-stroke" or "4-stroke" for this).

class Motorcycle : public Vehicle {
private:
	string engine_type;

public:
	//Constructor
	Motorcycle() {
		engine_type = "";
	}

	//Parametrized Constructor
	Motorcycle(string mk, string mdl, int yr, string clr, string engine) {
		setMake(mk);
		setModel(mdl);
		setYear(yr);
		setColor(clr);

		engine_type = engine;
	}

	void setEngineType(string eng) {
		engine_type = eng;
	}

	bool is_two_wheeler() {
		return engine_type == "2-stroke" || engine_type == "4-stroke";
	}

	void display_info() {
		Vehicle::display_info();
		cout << "Engine: " << engine_type << endl;
		
	}
};

class ElectricCar : public Vehicle, public Car {
private:
	double battery_capacity;
public:
	
	ElectricCar() {
		battery_capacity = 0;
	}

	bool is_electric() {
		if (battery_capacity > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	ElectricCar(string mk, string mdl, int yr, string clr, int doors, double battery) {
		Vehicle::setMake(mk);
		Vehicle::setModel(mdl);
		Vehicle::setYear(yr);
		Vehicle::setColor(clr);
		Car::setNumDoors(doors);
		 
		setBatterycapacity(battery);
		
	}

	double setBatterycapacity(double battery){
		battery_capacity = battery;
		return battery_capacity;
	}

	void display_info() {
		Vehicle::display_info();
		cout << "Battery Capacity: " << battery_capacity << endl;
		cout << "Is Electric: " << (is_electric() ? "Yes" : "NO") << endl;
	}
};
class ElectricMotorcycle : public Motorcycle  {
private:
	double battery_capacity;

public:
	bool is_Electric() {
		if (battery_capacity > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	ElectricMotorcycle(string mk, string mdl, int yr, string clr, string engine, double battery) {
		Motorcycle::setMake(mk);
		Motorcycle::setModel(mdl);
		Motorcycle::setYear(yr);
		Motorcycle::setColor(clr);
		Motorcycle::setEngineType(engine);
		
		setBatteryC(battery);
	}
		double setBatteryC (double battery){
			battery_capacity = battery;
			return battery_capacity;
		
	}

	void display_info() {
		Motorcycle::display_info();
		cout << "Battery Capacity: " << battery_capacity << endl;
	}
    };

class Truck : public  Vehicle {
private:
	double cargo_capacity;
public:
	Truck() {
		cargo_capacity = 0;
	}
	bool can_carry_cargo() {
		if (cargo_capacity > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	Truck(string mk, string mdl, int yr, string clr, double cargoC) {
		Vehicle::setMake(mk);
		Vehicle::setModel(mdl);
		Vehicle::setYear(yr);
		Vehicle::setColor(clr);
		setCargoCapacity(cargoC);
	}

	double setCargoCapacity(double cargoC) {
		cargo_capacity = cargoC;
		return cargo_capacity;
	}

	void display_info() {
		Vehicle::display_info();
		cout << "Cargo Capacity: " << cargo_capacity << endl;
	}
};

class Bicycle : public Vehicle {
private:
	string is_foldable;
public:
	void setFold(string fold) {
		is_foldable = fold;
	}

	bool is_foldable_bicycle() {
		return is_foldable == "Foldable";
	}

	Bicycle(string mk, string mdl, int yr, string clr, string fold) {
		Vehicle::setMake(mk);
		Vehicle::setModel(mdl);
		Vehicle::setYear(yr);
		Vehicle::setColor(clr);
		setFold(fold);
	}

	void display_Info() {
		Vehicle::display_info();
		
	}
	
};


int main() {
	////Constructor
	//Vehicle V1;
	//V1.display_info();

	////Set values
	//V1.setMake("Ford");
	//V1.setModel("Mustang GT");
	//V1.setYear(1999);
	//V1.setColor("Black");
	//V1.display_info();

	////Parametrized Constructor
	//Vehicle V2("Ford", "Mustang GT", 1999, "Black");
	//V2.display_info();

	Car C1("Toyota", "Mark X", 2011, "Red Wine", 4);
	C1.display_info();
	cout << "Has Trunk: " << (C1.has_trunk() ? "Yes" : "No") << endl;

	cout << endl;

	Motorcycle MC1("Kawasaki", "Ninja", 2023, "Black", "4-stroke");
	MC1.display_info();
	cout << "Is Two Wheeler: " << (MC1.is_two_wheeler() ? "Yes" : "No") << endl;

	cout << endl;


	ElectricCar EC1("BYD", "NINJA", 2025, "Black", 4, 5);
	EC1.display_info();

	cout << endl;

	ElectricMotorcycle EM1("Honda", "CD70", 2025, "Red", "2-stroke", 4);
	cout << "Is Two Wheeler: " << (EM1.is_two_wheeler() ? "Yes" : "No") << endl;
	EM1.display_info();

	cout << endl;

	Truck T("Mercedes", "VJ 22 Wheeler", 2025, "White", 20000);
	cout << "Can Carry Cargo:" << (T.can_carry_cargo() ? "Yes" : "No");
	cout << endl;
	T.display_info();

	cout << endl;

	Bicycle B("Sohrab", "Pico", 2025, "Black", "Foldable");
	cout << "Is Foldable: " << (B.is_foldable_bicycle() ? "Yes" : "No");
	cout << endl;
	B.display_Info();
	return 0;
}