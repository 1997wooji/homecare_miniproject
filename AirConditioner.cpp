#include "AirConditioner.h"

AirConditioner::AirConditioner() // Appliance�� default �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
	: Appliance()
{
	this->machineState=SENDAIR;
	this->setTemperature = 25;
}

AirConditioner::AirConditioner(string machineName, int powerConsumption)// Appliance�� Overloaded �����ڷ� ����, machineState�� ��ǳ���� �ʱ�ȭ
	: Appliance(machineName, powerConsumption)
{
	this->machineState = SENDAIR;
	this->setTemperature = 25;
}

														 // getter, setter member function
int AirConditioner::getMachineState() const // machineState ����� ��ȯ �Լ�
{
	return this->machineState;
}

int AirConditioner::getSetTemperature() const  // setTemperature ����� ��ȯ �Լ�
{
	return this->setTemperature;
}

void AirConditioner::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}

void AirConditioner::setSetTemperature(int setTemperature) // setTemperature ��� �ʱ�ȭ �Լ�
{
	this->setTemperature = setTemperature;
}

											// member function
AirConditioner & AirConditioner::operator++()// ���� �µ��� 1���� �ø���(prefix increment)
{
	this->setTemperature++;
	return *this;
}

AirConditioner & AirConditioner::operator--() // ���� �µ��� 1���� ������(prefix decrement)
{
	this->setTemperature--;
	return *this;
}

void AirConditioner::stateView() // ��ü�� ���� ���
{
	cout << "��ǰ��:"<<this->getMachineName();
	 if (this->getPowerFlag()==false)
	 {
		 cout << "(OFF)" << endl;
		 return;
	 }
	 else { cout << "(ON)" << "		��ǰ���� : "; }

	switch (this->machineState)
	{
	case SENDAIR: cout << "��ǳ" << "(" << this->setTemperature << "��)" <<endl; break;
	case COOLER: cout << "�ù�" << "(" << this->setTemperature << "��)" <<endl; break;
	case HEATER: cout << "����" <<"("<< this->setTemperature <<"��)" <<endl; break;
	}
}


//enum { SENDAIR = 1, COOLER, HEATER }; // ��ǳ, �ù�, ������ ��Ÿ���� ������ ���