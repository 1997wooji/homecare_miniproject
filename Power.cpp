#include "HomeAutomation.h"
//class에선 선언만 해주고 cpp에서는 인클루드해야함
#include "Power.h"

int Power::calPowerConsumption(HomeAutomation &rHa) // 가전 제품의 전력 소모량을 누적함
{
	int totalpowerconsumption=0;

	for (int i = 0; i < rHa.applianceCnt; i++)
	{

		totalpowerconsumption
			+= rHa.applianceArray[i]->getUseHour() / 30 * rHa.applianceArray[i]->getPowerConsumption();
	}
	//KW/30s로 기준 잡음 눈에 잘 안보여서

	return totalpowerconsumption;
}