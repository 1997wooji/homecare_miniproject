#include "AirConditioner.h"

AirConditioner::AirConditioner() // Appliance는 default 생성자로 생성, machineState는 송풍으로 초기화
	: Appliance()
{
	this->machineState=SENDAIR;
	this->setTemperature = 25;
}

AirConditioner::AirConditioner(string machineName, int powerConsumption)// Appliance는 Overloaded 생성자로 생성, machineState는 송풍으로 초기화
	: Appliance(machineName, powerConsumption)
{
	this->machineState = SENDAIR;
	this->setTemperature = 25;
}

														 // getter, setter member function
int AirConditioner::getMachineState() const // machineState 멤버값 반환 함수
{
	return this->machineState;
}

int AirConditioner::getSetTemperature() const  // setTemperature 멤버값 반환 함수
{
	return this->setTemperature;
}

void AirConditioner::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}

void AirConditioner::setSetTemperature(int setTemperature) // setTemperature 멤버 초기화 함수
{
	this->setTemperature = setTemperature;
}

											// member function
AirConditioner & AirConditioner::operator++()// 설정 온도를 1도씩 올린다(prefix increment)
{
	this->setTemperature++;
	return *this;
}

AirConditioner & AirConditioner::operator--() // 설정 온도를 1도씩 내린다(prefix decrement)
{
	this->setTemperature--;
	return *this;
}

void AirConditioner::stateView() // 객체의 상태 출력
{
	cout << "제품명:"<<this->getMachineName();
	 if (this->getPowerFlag()==false)
	 {
		 cout << "(OFF)" << endl;
		 return;
	 }
	 else { cout << "(ON)" << "		제품상태 : "; }

	switch (this->machineState)
	{
	case SENDAIR: cout << "송풍" << "(" << this->setTemperature << "도)" <<endl; break;
	case COOLER: cout << "냉방" << "(" << this->setTemperature << "도)" <<endl; break;
	case HEATER: cout << "난방" <<"("<< this->setTemperature <<"도)" <<endl; break;
	}
}


//enum { SENDAIR = 1, COOLER, HEATER }; // 송풍, 냉방, 난방을 나타내는 열거형 상수