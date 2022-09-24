//Omar Almekhlafy
// 900213929
// Assignment 1

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Car
{
public:
	Car() {

	}
	Car(string xCarbrand, int ySpeed, int zYearmodel)
	{
		car_brand = xCarbrand;
		speed = ySpeed;
		year_model = zYearmodel;
	}
	void set_car_brand(string Carbrand)
	{
		car_brand = Carbrand;
	}
	void set_car_type(string Cartype)
	{
		car_type = Cartype;
	}
	void set_car_plate(string plate)
	{
		car_plate = plate;
	}
	void set_speed(int s)
	{
		speed = s;
	}
	void set_yearModel(int ym)
	{
		year_model = ym;
	}
	string get_car_brand()
	{
		return car_brand;
	}
	string get_car_type()
	{
		return car_type;
	}
	string get_car_plate()
	{
		return car_plate;
	}
	int get_speed()
	{
		return speed;
	}
	int get_year_model()
	{
		return year_model;
	}
private:
	string car_brand;
	string car_type;
	string car_plate;
	int speed;
	int year_model;
};
class Road
{
private:
	char road_type;
	int speed_limit;
	double countA;
	double countB;
	double countC;
public:
	Road() {
		countA = 0;
		countB = 0;
		countC = 0;
	}
	Road(char Road_Type, int Speed_Limit) {
		speed_limit = Speed_Limit;
		road_type = Road_Type;
	};
	void set_road_type(char rt)
	{
		road_type = rt;
		while (!(road_type == 'A' || road_type == 'B' || road_type == 'C')) {
			cout << "invalid road type, enter A, B, or C";
			cin >> rt;
			road_type = rt;
		}
	}

	void set_speed_limit(int sl)
	{
		speed_limit = sl;
	}
	char get_road_type() {
		return road_type;
	}
	int get_speed_limit() {
		return speed_limit;
	}
	double get_countA() {
		return countA;
	}
	double get_countB() {
		return countB;
	}
	double get_countC() {
		return countC;
	}
	bool radar(int Sp, char rt2) {

		int temp{};
		if (rt2 == 'A') {
			temp = countA;
			cout << "Road " << rt2 << " allows:  " << temp << "  Car/s \n";
		}
		else if (rt2 == 'B'){
			temp = countB;
			cout << "Road " << rt2 << " allows:  " << temp << "  Car/s \n";
	}
		else if (rt2 == 'C'){
			temp = countC;
			cout << "Road " << rt2 << " allows:  " << temp << "  Car/s \n";
	}
		if (Sp > speed_limit){
			return true;
		}
		else return false;
	}
	void allow(string CT) {
		if (CT == "Private" || CT == "Motorcycle") {
			countA++;
			countB++;
		}
		else if (CT == "Truck") {
			countC++;
			countB++;
		}
		else {
			countB++;
		}
	}
	int age(int YM2) {
		return 2022 - YM2;
	}

};
int main() {
	char C{};
	Road Tahrir;
	Tahrir.set_speed_limit(90);
	Tahrir.set_road_type('C');
	Car Gclass, Corolla, Hilux, Hyundai;
	Gclass.set_car_brand("Mercedes");
	Gclass.set_car_plate("42069");
	Gclass.set_car_type("Private");
	Gclass.set_speed(99);
	Gclass.set_yearModel(2005);
	Corolla.set_car_brand("Toyota");
	Corolla.set_car_plate("12345");
	Corolla.set_car_type("Truck");
	Corolla.set_speed(120);
	Corolla.set_yearModel(2007);
	Hilux.set_car_brand("Unknown car");
	Hilux.set_car_plate(" 666 AAA");
	Hilux.set_car_type("Motorcycle");
	Hilux.set_speed(50);
	Hilux.set_yearModel(2010);
	Hyundai.set_car_brand("Hyundai");
	Hyundai.set_car_plate("opq123");
	Hyundai.set_car_type("Private");
	Hyundai.set_speed(40);
	Hyundai.set_yearModel(1999);
	queue<Car> Qcar;
	Qcar.push(Gclass);
	Qcar.push(Corolla);
	Qcar.push(Hilux);
	Qcar.push(Hyundai);
	while(!Qcar.empty()) {
		cout << "*************************************************************************** \n";
		Tahrir.allow(Qcar.front().get_car_type());
		if (Tahrir.radar(Qcar.front().get_speed(), Tahrir.get_road_type())) {
			cout <<"Illegal activity spotted ! \n"<< "Car Brand: " << Qcar.front().get_car_brand() << "\n" << "Car Plate: " << Qcar.front().get_car_plate() << "\n" << "Car Type: " << Qcar.front().get_car_type() << "\n" << "Car Speed: " << Qcar.front().get_speed() << "\n" << "Car Year Model: " << Qcar.front().get_year_model() << endl;
			cout << "this car will be fined" << endl;
		}
		cout<< "The age of this " << Qcar.front().get_car_type() << " car is : " << Tahrir.age(Qcar.front().get_year_model()) << "  years old \n";

		
		Qcar.pop();
	}
	cout << "*************************************************************************** \n";
	cout << "Cars passed by Tahrir Road A is  " << Tahrir.get_countA() << "\n";
	cout << "Cars passed by Tahrir Road B is  " << Tahrir.get_countB() << "\n";
	cout << "Cars passed by Tahrir Road C is  " << Tahrir.get_countC() << "\n";
	cout << "*************************************************************************** \n";
	cout << "Tahrir Road A efficiency is  "<< (Tahrir.get_countA() / Tahrir.get_countB()) * 100 << "%\n";
	cout << "Tahrir Road B efficiency is  " << (Tahrir.get_countB() / Tahrir.get_countB()) * 100 << "%\n";
	cout << "Tahrir Road C efficiency is  " << (Tahrir.get_countC() / Tahrir.get_countB()) * 100 << "%\n";
	}
	

