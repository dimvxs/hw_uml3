// hw_uml3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
class Car {
    string name; //название машины
    string frame;//корпус
    int engine;//двигатель
    int wheels;//колеса
    string kpp;//кпп

public:

    void setName(string n) {
        this->name = n;
    }

    void setFrame(string f) {
       this->frame = f;
    }

    void setEngine(int e) {
        this -> engine = e;
    }

    void setWheels(int w) {
        this->wheels = w;
    }

    void setKpp(string k) {
        this->kpp = k;
    }

    string getName() {
        return this->name;
    }

    string getFrame() {
        return this->frame;
    }
    int getEngine() {
        return this->engine;
    }

    int getWheels() {
        return this->wheels;
    }
    string getKpp() {
        return this->kpp;
    }

    void showCar() {
        cout << "Name: " << name << endl;
        cout << "Frame: " << frame << endl;
        cout << "Engine: " << engine << endl;
        cout << "Wheels: " << wheels << endl;
        cout << "Kpp: " << kpp << endl;
    }

};


// Abstract Builder задает абстрактный интерфейс (класс) дл€ создани€ частей объекта Product (в нашем случае, Car);
  /** "Abstract Builder" */

class CarBuilder abstract {
protected:
    Car car;
public:
    Car getCar() {
        return car;
    }
    virtual void buildName() abstract;
    virtual void buildFrame() abstract;
    virtual void buildEngine() abstract;
    virtual void buildWheels() abstract;
    virtual void buildkpp() abstract;
};

class DaewooLanas: public CarBuilder {
public:
    void buildName() override {
        car.setName("Daewoo Lanas");
    }
    void buildFrame() override{
        car.setFrame("Sedan");
    }

    void buildEngine() override {
        car.setEngine(98);
    }
    void buildWheels() override {
        car.setWheels(13);
    }
    void buildkpp() override {
        car.setKpp("5 manual");
    }

};


class FordProbe : public CarBuilder {
public:
    void buildName() override {
        car.setName("Ford Probe");
    }
    void buildFrame() override {
        car.setFrame("Coupe");
    }

    void buildEngine() override {
        car.setEngine(160);
    }
    void buildWheels() override {
        car.setWheels(14);
    }
    void buildkpp() override {
        car.setKpp("4 auto");
    }

};

class UAZpatriot : public CarBuilder {
public:
    void buildName() override {
        car.setName("UAZ Patriot");
    }
    void buildFrame() override {
        car.setFrame("Universal");
    }

    void buildEngine() override {
        car.setEngine(120);
    }
    void buildWheels() override {
        car.setWheels(16);
    }
    void buildkpp() override {
        car.setKpp("4 manual");
    }

};

class HyundaiGetz : public CarBuilder {
public:
    void buildName() override {
        car.setName("Hyundai Getz");
    }
    void buildFrame() override {
        car.setFrame("Hatchback");
    }

    void buildEngine() override {
        car.setEngine(66);
    }
    void buildWheels() override {
        car.setWheels(13);
    }
    void buildkpp() override {
        car.setKpp("4 auto");
    }

};
// Director(распор€дитель) - конструирует объект (Car), пользу€сь интерфейсом Builder
class Director {
    CarBuilder* carBuilder;
public:
    void SetCarBuilder(CarBuilder* cb) {
        carBuilder = cb;
    }
    Car getCar() {
        return carBuilder->getCar();
    }

    void createCar() {
        carBuilder->buildName();
        carBuilder->buildFrame();
        carBuilder->buildEngine();
        carBuilder->buildWheels();
        carBuilder->buildkpp();
    }

 

};

// клиент создает объект-распор€дитель Director и конфигурирует его нужным объектом-строителем Builder
void client(CarBuilder* builder) {
    Director director;
    director.SetCarBuilder(builder);
    director.createCar();
    Car car = director.getCar();
    car.showCar();
}



int main()
{
    CarBuilder* builder = new FordProbe();
    client(builder);
    delete builder;
}

