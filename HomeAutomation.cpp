#include "HomeAutomation.h"

HomeAutomation::HomeAutomation() // appliaceArray�� �޸� ������ ��� 0���� �ʱ�ȭ �ϰ�, applianceCnt�� 0���� �ʱ�ȭ
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

HomeAutomation::~HomeAutomation() // applianceArray�� ���� �Ҵ�� ��ü�� ��� ������
{
	for (int i = 0; i< applianceCnt; i++)
	{
		delete applianceArray[i];
	}

}


				   // getter, setter member function
Appliance ** HomeAutomation::getApplianceArray() // applianceArray ��� �� ��ȯ �Լ�
{
	return this->applianceArray;

}

int HomeAutomation::getApplianceCnt() const // applianceCnt ��� �� ��ȯ �Լ�
{
	return this->applianceCnt;

}


							 // member function
HomeAutomation & HomeAutomation::operator=(const HomeAutomation &r) // ����(�Ҵ�)������ �����ε� �Լ�
//������ �����ε� �Լ��� �����ڰ� �ƴϹǷ� �ݷ��ʱ�ȭ�� �ϸ� �ȵ�!
{
	if (this == &r) return *this;

	this->applianceCnt = r.applianceCnt;

	for (int i = 0; i< APPLIANCE_MAX_CNT; i++)
	{
		delete applianceArray[i]; //�Ҹ��� virtual
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

bool HomeAutomation::addAppliance(Appliance *ap)// ������ǰ�� ��Ͽ� �߰�.  ������ ��ǰ�� �߰� �Ұ���. 
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

int HomeAutomation::searchMachine(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ã�Ƽ� �迭�� index����/���� �� -1 ����
{

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
			return i;
	}
	return -1;
}

bool HomeAutomation::deleteAppliance(string machineName) // ������ǰ�� �ش��ϴ� ������ǰ�� ��Ͽ��� �����ϴ�
{
	int j;

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			delete applianceArray[i];
			

			for (j=i+1; j<applianceCnt;j++) //index+1���� ��ĭ�� �ű��
			{
				applianceArray[j - 1] = applianceArray[j]; //������ member�� �ּҿ� �� ���� member�ּҸ� ����.
			}
			applianceArray[j - 1] = NULL; //NULL�� �־�� �޸� �ߺ��� ����
			applianceCnt--;
			return true;
		}
	}

	return false;
}

void HomeAutomation::listDisplayAppliance() // ��ϵ� ������ǰ ��ü ��� �� ���¸�  Ȯ���ϴ�
{
	for (int i = 0; i < applianceCnt; i++)
	{
		applianceArray[i]->stateView();
	}
}

bool HomeAutomation::controlAppliance(string machineName)   // �ش� ������ǰ�� �����ϴ�
{

	for (int i = 0; i < applianceCnt; i++)
	{
		if (applianceArray[i]->getMachineName() == machineName)
		{
			if (!(applianceArray[i]->getPowerFlag()))
			{
				cout << "��ǰ�� �ѽÁٽ��ϱ�? (Y/N)";
				getchar(); //�Է��Ҷ� �ƴ� ���� �ϳ� ����ؼ� ���͸� ���� ������
				int ch = getchar();
				if (ch == 'y' || ch == 'Y')
				{
					applianceArray[i]->turnOn();
					setStateAppliance(applianceArray[i]);
					return true;
				}
				else return true;
				//�����ִ� ���¿��� ��ǰ�� ���Ѱڴ��ϸ� ��.



			}
			else
			{
				setStateAppliance(applianceArray[i]);
				return true;
				//�����ִ� ���¸� �ٷ� ����.
			}

			
			
		}
	}
	return false; //�ƿ� ��ǰ�� ��ã�� ���

}

void HomeAutomation::setStateAppliance(Appliance * ap) // �����ִ� ������ǰ�� ���¸� �����ϴ�
{
	string applianceList;
	int applianceNum;

	if (dynamic_cast<Washer *>(ap))
	{
		Washer * bp = dynamic_cast<Washer *>(ap);
		applianceList = "1:������/ 2:�Ϲݻ���/ 3:��������/ 4:���� / 5:���� :";
		applianceNum = controlMenuSelect(applianceList, 5);

		if (applianceNum == 5)
		{
			bp->turnOff(); return;
		}
		else { //5�� �ƴϸ�
			bp->setMachineState(applianceNum);
		}

	}
	else if (dynamic_cast<RiceCooker *>(ap))
	{
		RiceCooker * bp = dynamic_cast<RiceCooker *>(ap);
		applianceList = "1:������/ 2:����/ 3:������/ 4:�����/ 5:���� :";
		applianceNum = controlMenuSelect(applianceList, 5);

		if (applianceNum == 5)
		{
			bp->turnOff(); return;
		}
		else { //5�� �ƴϸ�
			bp->setMachineState(applianceNum);
		}
	}
	else {

		AirConditioner * bp = dynamic_cast<AirConditioner *>(ap);
		applianceList = "1:��ǳ/ 2:�ù�/ 3:����/ 4:���� :";
		applianceNum = controlMenuSelect(applianceList, 4);

		if (applianceNum==4)
		{
			bp->turnOff(); return;
		}
		else { //4�� �ƴϸ�
			bp->setMachineState(applianceNum);
		}

		applianceList = "1:�µ� �ø���/ 2:�µ� ������/ 3:�µ� ���� ���� :";
		applianceNum = controlMenuSelect(applianceList, 3);

		switch (applianceNum)
		{
		case 1:++(*bp); break;
		case 2:--(*bp); break;
			//prefix�� �� postfix�� �ȵ�!!
		case 3:break;
		}

	}

	ap->stateView(); //virtual�̶� ap�� �޾Ƶ� ������!


}
