#include "Ricecooker.h"

RiceCooker::RiceCooker() // Appliance는 default생성자로 생성, machineState는 무동작으로 초기화
	: Appliance()
{
	this->machineState = NO_OPERATION;
}
RiceCooker::RiceCooker(string machineName, int powerConsumption) // Appliance는 Overloaded 생성자로 생성, machineState는 무동작으로 초기화
	: Appliance(machineName, powerConsumption)
{
	this->machineState = NO_OPERATION;
}
													  // getter, setter member function
int RiceCooker::getMachineState() const // machineState 멤버 값 반환 함수
{
	return this->machineState;
}
void RiceCooker::setMachineState(int machineState)// machineState 멤버 초기화 함수
{
	this->machineState = machineState;
}
										// member function
void RiceCooker::stateView() // 객체의 상태 출력
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
	case NO_OPERATION: cout << "무동작" << endl; break;
	case WARM: cout << "보온" << endl; break;
	case COOK: cout << "밥 짓기" << endl; break;
	case HEAT: cout << "데우기" << endl; break;
	}
}

				  //enum { NO_OPERATION = 1, WARM, COOK, HEAT }; // 밥솥의 상태를 나타내는 열거형 상수