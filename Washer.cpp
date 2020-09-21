#include "Washer.h"

Washer::Washer() // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
	: Appliance()
{
	this->machineState = NO_OPERATION;
}

Washer::Washer(string machineName, int powerConsumption) // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
	: Appliance(machineName, powerConsumption)
{
	this->machineState = NO_OPERATION;
}

												  // getter, setter member function
int Washer::getMachineState() const // machineState 멤버 값 반환 함수
{
	return this->machineState;

}

void Washer::setMachineState(int machineState) // machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}

										// member function
void Washer::stateView()  // 객체의 상태 출력
{
	cout << "제품명:" << this->getMachineName();
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
		return;
	}
	else { cout << "(ON)" << "		제품상태 : "; }

	switch (this->machineState)
	{
	case NO_OPERATION: cout<< "무동작" << endl; break;
	case GENERAL: cout << "일반 빨래" << endl; break;
	case BOIL: cout << "삶은 빨래" << endl; break;
	case  DRY: cout << "건조" << endl; break;
	}
}

//enum { NO_OPERATION = 1, GENERAL, BOIL, DRY }; // 세탁기의 상태를 나타내는 열거형 상수