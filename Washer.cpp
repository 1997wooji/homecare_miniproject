#include "Washer.h"

Washer::Washer() // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	: Appliance()
{
	this->machineState = NO_OPERATION;
}

Washer::Washer(string machineName, int powerConsumption) // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	: Appliance(machineName, powerConsumption)
{
	this->machineState = NO_OPERATION;
}

												  // getter, setter member function
int Washer::getMachineState() const // machineState ��� �� ��ȯ �Լ�
{
	return this->machineState;

}

void Washer::setMachineState(int machineState) // machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}

										// member function
void Washer::stateView()  // ��ü�� ���� ���
{
	cout << "��ǰ��:" << this->getMachineName();
	if (this->getPowerFlag() == false)
	{
		cout << "(OFF)" << endl;
		return;
	}
	else { cout << "(ON)" << "		��ǰ���� : "; }

	switch (this->machineState)
	{
	case NO_OPERATION: cout<< "������" << endl; break;
	case GENERAL: cout << "�Ϲ� ����" << endl; break;
	case BOIL: cout << "���� ����" << endl; break;
	case  DRY: cout << "����" << endl; break;
	}
}

//enum { NO_OPERATION = 1, GENERAL, BOIL, DRY }; // ��Ź���� ���¸� ��Ÿ���� ������ ���