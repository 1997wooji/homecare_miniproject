#include "Ricecooker.h"

RiceCooker::RiceCooker() // Appliance�� default�����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	: Appliance()
{
	this->machineState = NO_OPERATION;
}
RiceCooker::RiceCooker(string machineName, int powerConsumption) // Appliance�� Overloaded �����ڷ� ����, machineState�� ���������� �ʱ�ȭ
	: Appliance(machineName, powerConsumption)
{
	this->machineState = NO_OPERATION;
}
													  // getter, setter member function
int RiceCooker::getMachineState() const // machineState ��� �� ��ȯ �Լ�
{
	return this->machineState;
}
void RiceCooker::setMachineState(int machineState)// machineState ��� �ʱ�ȭ �Լ�
{
	this->machineState = machineState;
}
										// member function
void RiceCooker::stateView() // ��ü�� ���� ���
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
	case NO_OPERATION: cout << "������" << endl; break;
	case WARM: cout << "����" << endl; break;
	case COOK: cout << "�� ����" << endl; break;
	case HEAT: cout << "�����" << endl; break;
	}
}

				  //enum { NO_OPERATION = 1, WARM, COOK, HEAT }; // ����� ���¸� ��Ÿ���� ������ ���