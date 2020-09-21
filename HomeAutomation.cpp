#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() // appliaceArray의 메모리 영역을 모두 0으로 초기화 하고, applianceCnt를 0으로 초기화
	: applianceCnt(0)
{
	for(int i=0;i< APPLIANCE_MAX_CNT;i++)
	{
		applianceArray[i] = 0;
	}
}

HomeAutomation::HomeAutomation(const HomeAutomation &r) // deep copy constructor
	: applianceCnt(r.applianceCnt)
{
	for (int i = 0; i< APPLIANCE_MAX_CNT; i++)
	{
		applianceArray[i] = 0;
	}

	for (int i = 0; i< applianceCnt; i++)
	{
		//Washer(string machineName, int powerConsumption)
		//RiceCooker(string machineName, int powerConsumption)
		//AirConditioner(string machineName, int powerConsumption)
		if (dynamic_cast<Washer *>(r.applianceArray[i]))
		{
			Washer * bp = dynamic_cast<Washer *>(r.applianceArray[i]);
			Washer * ap = dynamic_cast<Washer *>(applianceArray[i]);
			ap = new Washer(bp->getMachineName(),bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());

		}
		else if (dynamic_cast<RiceCooker *>(r.applianceArray[i]))
		{
			RiceCooker * bp = dynamic_cast<RiceCooker *>(r.applianceArray[i]);
			RiceCooker * ap = dynamic_cast<RiceCooker *>(applianceArray[i]);
			ap = new RiceCooker(bp->getMachineName(), bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());

		}
		else {

			AirConditioner * bp = dynamic_cast<AirConditioner *>(r.applianceArray[i]);
			AirConditioner * ap = dynamic_cast<AirConditioner *>(applianceArray[i]);
			ap = new AirConditioner(bp->getMachineName(), bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());
			ap->setSetTemperature(bp->getSetTemperature());
		
		}

	}

}

HomeAutomation::~HomeAutomation() // applianceArray에 동적 할당된 객체를 모두 해제함
{
	for (int i = 0; i< applianceCnt; i++)
	{
		delete applianceArray[i];
	}

}


				   // getter, setter member function
Appliance ** HomeAutomation::getApplianceArray() // applianceArray 멤버 값 반환 함수
{
	return this->applianceArray;

}

int HomeAutomation::getApplianceCnt() const // applianceCnt 멤버 값 반환 함수
{
	return this->applianceCnt;

}


							 // member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) // 대입(할당)연산자 오버로딩 함수
//연산자 오버로드 함수는 생성자가 아니므로 콜론초기화를 하면 안됨!
{
	if (this == &r) return *this;

	this->applianceCnt = r.applianceCnt;

	for (int i = 0; i< APPLIANCE_MAX_CNT; i++)
	{
		delete applianceArray[i]; //소멸자 virtual
		applianceArray[i] = 0;
	}

	for (int i = 0; i< applianceCnt; i++)
	{
		//Washer(string machineName, int powerConsumption)
		//RiceCooker(string machineName, int powerConsumption)
		//AirConditioner(string machineName, int powerConsumption)
		if (dynamic_cast<Washer *>(r.applianceArray[i]))
		{
			Washer * bp = dynamic_cast<Washer *>(r.applianceArray[i]);
			Washer * ap = dynamic_cast<Washer *>(applianceArray[i]);
			ap = new Washer(bp->getMachineName(), bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());

		}
		else if (dynamic_cast<RiceCooker *>(r.applianceArray[i]))
		{
			RiceCooker * bp = dynamic_cast<RiceCooker *>(r.applianceArray[i]);
			RiceCooker * ap = dynamic_cast<RiceCooker *>(applianceArray[i]);
			ap = new RiceCooker(bp->getMachineName(), bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());

		}
		else {

			AirConditioner * bp = dynamic_cast<AirConditioner *>(r.applianceArray[i]);
			AirConditioner * ap = dynamic_cast<AirConditioner *>(applianceArray[i]);
			ap = new AirConditioner(bp->getMachineName(), bp->getPowerConsumption());
			ap->setMachineState(bp->getMachineState());
			ap->setPowerFlag(bp->getPowerFlag());
			ap->setSetTemperature(bp->getSetTemperature());

		}

	}

	return *this;

}

bool HomeAutomation::addAppliance(Appliance *ap)// 가전제품을 목록에 추가.  동일한 제품명 추가 불가능. 
{
	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == ap->getMachineName())
			return false;
	}

	applianceArray[applianceCnt] = ap;
	applianceCnt++;
	return true;

}

int HomeAutomation::searchMachine(string machineName) // 가전제품명에 해당하는 가전제품을 찾아서 배열의 index리턴/없을 시 -1 리턴
{

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
			return i;
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName) // 가전제품명에 해당하는 가전제품을 목록에서 삭제하다
{
	int j;

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			delete applianceArray[i];
			

			for (j=i+1; j<applianceCnt;j++) //index+1부터 한칸씩 옮기기
			{
				applianceArray[j - 1] = applianceArray[j]; //해지된 member의 주소에 그 옆의 member주소를 넣음.
			}
			applianceArray[j - 1] = NULL; //NULL을 넣어야 메모리 중복이 방지
			applianceCnt--;
			return true;
		}
	}

	return false;
}

void HomeAutomation::listDisplayAppliance() // 등록된 가전제품 전체 목록 및 상태를  확인하다
{
	for (int i = 0; i < applianceCnt; i++)
	{
		applianceArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName)   // 해당 가전제품을 제어하다
{

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			if (!(applianceArray[i]->getPowerFlag()))
			{
				cout << "제품을 켜시곘습니까? (Y/N)";
				getchar(); //입력할때 쳤던 엔터 하나 고려해서 엔터를 먼저 없애줌
				int ch = getchar();
				if (ch == 'y' || ch == 'Y')
				{
					applianceArray[i]->turnOn();
					setStateAppliance(applianceArray[i]);
					return true;
				}
				else return true;
				//꺼져있는 상태에서 제품을 안켜겠다하면 끝.



			}
			else
			{
				setStateAppliance(applianceArray[i]);
				return true;
				//켜져있는 상태면 바로 시행.
			}

			
			
		}
	}
	return false; //아예 제품을 못찾은 경우

}

void HomeAutomation::setStateAppliance(Appliance * ap) // 켜져있는 가전제품의 상태를 변경하다
{
	string applianceList;
	int applianceNum;

	if (dynamic_cast<Washer *>(ap))
	{
		Washer * bp = dynamic_cast<Washer *>(ap);
		applianceList = "1:무동작/ 2:일반빨래/ 3:삶은빨래/ 4:건조 / 5:끄기 :";
		applianceNum = controlMenuSelect(applianceList, 5);

		if (applianceNum == 5)
		{
			bp->turnOff(); return;
		}
		else { //5가 아니면
			bp->setMachineState(applianceNum);
		}

	}
	else if (dynamic_cast<RiceCooker *>(ap))
	{
		RiceCooker * bp = dynamic_cast<RiceCooker *>(ap);
		applianceList = "1:무동작/ 2:보온/ 3:밥짓기/ 4:데우기/ 5:끄기 :";
		applianceNum = controlMenuSelect(applianceList, 5);

		if (applianceNum == 5)
		{
			bp->turnOff(); return;
		}
		else { //5가 아니면
			bp->setMachineState(applianceNum);
		}
	}
	else {

		AirConditioner * bp = dynamic_cast<AirConditioner *>(ap);
		applianceList = "1:송풍/ 2:냉방/ 3:난방/ 4:끄기 :";
		applianceNum = controlMenuSelect(applianceList, 4);

		if (applianceNum==4)
		{
			bp->turnOff(); return;
		}
		else { //4가 아니면
			bp->setMachineState(applianceNum);
		}

		applianceList = "1:온도 올리기/ 2:온도 내리기/ 3:온도 제어 종료 :";
		applianceNum = controlMenuSelect(applianceList, 3);

		switch (applianceNum)
		{
		case 1:++(*bp); break;
		case 2:--(*bp); break;
			//prefix만 됨 postfix는 안됨!!
		case 3:break;
		}

	}

	ap->stateView(); //virtual이라 ap로 받아도 괜찮음!


}
