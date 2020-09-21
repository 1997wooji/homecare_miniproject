#include "Appliance.h"

// constructor, destructor : deep copy cons.�� destructor�� ������ �������� ����
Appliance::Appliance()  // default constructor (machineName:Null string, powerFlag:false, powerConsumption:0, startHour:0, useHour:0)
	: machineName(""), powerFlag(false), powerConsumption(0), startHour(0), useHour(0)
{}

Appliance::Appliance(string machineName, int powerConsumption, bool powerFlag, time_t startHour, time_t useHour)
 : machineName(machineName), powerFlag(powerFlag), powerConsumption(powerConsumption), startHour(startHour), useHour(useHour)
{}
						 // getter, setter member function
string Appliance::getMachineName() const  // machineName ����� ��ȯ �Լ�
{
	return this->machineName;
}

bool Appliance::getPowerFlag() const // powerFlag ��� �� ��ȯ �Լ� 
{
	return this->powerFlag;
}

int Appliance::getPowerConsumption() const // powerConsumtion ��� �� ��ȯ �Լ�
{
	return this->powerConsumption;
}

time_t Appliance::getStartHour() // startHour ��� �� ��ȯ �Լ�
{
	return this->startHour;
}

time_t Appliance::getUseHour() // useHour ��� �� ��ȯ �Լ�
{
	return this->useHour;
}

void Appliance::setMachineName(string machineName)  // machineName ��� �ʱ�ȭ �Լ�
{
	this->machineName = machineName;
}

void Appliance::setPowerFlag(bool powerFlag) // powerFlag ��� �ʱ�ȭ �Լ� 
{
	this->powerFlag = powerFlag;
}

void Appliance::setPowerConsumption(int powerConsumption) // powerConsumtion ��� �ʱ�ȭ �Լ�
{
	this->powerConsumption = powerConsumption;
}

												// member fucntion
bool Appliance::turnOn() // ��ǰ�� �Ѵ�
{
	this->powerFlag = true;
	time(&startHour);
	return true;
}

bool Appliance::turnOff() // ��ǰ�� ����
{
	time_t endHour;
	this->powerFlag = false;
	time(&endHour);
	this->useHour += endHour - this->getStartHour(); //������ Ű�� ���� ���� ���
	return true; //���°͵� ������ true!
}