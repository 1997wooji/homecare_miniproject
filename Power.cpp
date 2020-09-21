#include "HomeAutomation.h"
//class���� ���� ���ְ� cpp������ ��Ŭ����ؾ���
#include "Power.h"

int Power::calPowerConsumption(HomeAutomation &rHa) // ���� ��ǰ�� ���� �Ҹ��� ������
{
	int totalpowerconsumption=0;

	for (int i = 0; i < rHa.applianceCnt; i++)
	{

		totalpowerconsumption
			+= rHa.applianceArray[i]->getUseHour() / 30 * rHa.applianceArray[i]->getPowerConsumption();
	}
	//KW/30s�� ���� ���� ���� �� �Ⱥ�����

	return totalpowerconsumption;
}