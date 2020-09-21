#include "Appliance.h"

// constructor, destructor : deep copy cons.와 destructor는 별도로 선언정의 안함
Appliance::Appliance()  // default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
	: machineName(""), powerFlag(false), powerConsumption(0), startHour(0), useHour(0)
{}

Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
 : machineName(machineName), powerFlag(powerFlag), powerConsumption(powerConsumption), startHour(startHour), useHour(useHour)
{}
						 // getter, setter member function
string Appliance::getMachineName() const  // machineName 멤버값 반환 함수
{
	return this->machineName;
}

bool Appliance::getPowerFlag() const // powerFlag 멤버 값 반환 함수 
{
	return this->powerFlag;
}

int Appliance::getPowerConsumption() const // powerConsumtion 멤버 값 반환 함수
{
	return this->powerConsumption;
}

time_t Appliance::getStartHour() // startHour 멤버 값 반환 함수
{
	return this->startHour;
}

time_t Appliance::getUseHour() // useHour 멤버 값 반환 함수
{
	return this->useHour;
}

void Appliance::setMachineName(string machineName)  // machineName 멤버 초기화 함수
{
	this->machineName = machineName;
}

void Appliance::setPowerFlag(bool powerFlag) // powerFlag 멤버 초기화 함수 
{
	this->powerFlag = powerFlag;
}

void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion 멤버 초기화 함수
{
	this->powerConsumption = powerConsumption;
}

												// member fucntion
bool Appliance::turnOn() // 제품을 켜다
{
	this->powerFlag = true;
	time(&startHour);
	return true;
}

bool Appliance::turnOff() // 제품을 끄다
{
	time_t endHour;
	this->powerFlag = false;
	time(&endHour);
	this->useHour += endHour - this->getStartHour(); //여러번 키고 끄는 것을 대비
	return true; //끄는것도 했으면 true!
}