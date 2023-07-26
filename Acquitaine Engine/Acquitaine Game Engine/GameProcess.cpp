#include "GameProcess.h"

GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

void GameProcess::Initialize()
{
}

void GameProcess::Finalize()
{
}

void GameProcess::RunningGameProcess()
{
	float fixedupdateTimeRate = 0;

	/// ��ũ���� �Ҷ� ������ �ʴ� �κФѤѤѤѤѤѤѤѤѤ�
	ObjectStateChange();
	
	/// ��ũ���� �Ҷ� ���̴� �κФѤѤѤѤѤѤѤѤѤ�
	// �ʱ�ȭ,�߰�, ����
	Awake();
	Enable();
	Start();

	// ��ǲ �Է�, ��������, ������Ʈ
	InputEvent(); /// ��� ��ũ���� �Ҷ� ������ �ʰ� �Ұ�.
	while (fixedupdateTimeRate > FixedUpdate());	//���������� �� �κ�. ����ð��� fixedupdatetime���� �۴ٸ� �Ƚ��� ������Ʈ�� �ݺ� �����Ѵ�.
	Update();

	Render();	/// ��� ��ũ���� �Ҷ� ������ �ʰ� �Ұ�.

	// ��Ȱ��ȭ, ��� ����
	Disable();
	Release();

	/// ��ũ���� �Ҷ� ������ �ʴ� �κФѤѤѤѤѤѤѤѤѤ�
	CreateObjects();
	InitializeObjects();
}

IObject* GameProcess::CreateObjects()
{
	//IObject* temp = new /*IObject*/();
	//objectList.push_back(temp);
	//startObjectList.push_back(temp);
	//return temp;
	return nullptr;
}

void GameProcess::InitializeObjects()
{
}

void GameProcess::Awake()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Awake();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::Enable()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Awake();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::Start()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Awake();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::InputEvent()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->InputEvent();
	}
}

float GameProcess::FixedUpdate()
{
	///���������� ����Ǵ� �κ��̰�, ���� �ð��� �ʴ����� ��ȯ�ϵ��� ����
	for (auto pObject : awakeObjectList)
	{
		//pObject->FixedUpdate();
		//pObject->phsics();
	}

	return 0.0;
}

void GameProcess::Update()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Update();
	}
}

void GameProcess::Render()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Render();
	}
}

void GameProcess::Disable()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Disable();
	}
}

void GameProcess::Release()
{
	for (auto pObject : awakeObjectList)
	{
		//pObject->Release();
	}
}

void GameProcess::ObjectStateChange()
{
	for (auto buff : stateChangeBuffer)
	{
		switch (buff.first)
		{
			case ObjectState::AWAKE:
			{
				awakeObjectList.push_back(buff.second);
			}break;
			case ObjectState::ENABLE:
			{
				enableObjectList.push_back(buff.second);
			}break;
			case ObjectState::START:
			{
				startObjectList.push_back(buff.second);
			}break;
			case ObjectState::UPDATE:
			{
				updateObjectList.push_back(buff.second);
			}break;
			case ObjectState::DISABLE:
			{
				disableObjectList.push_back(buff.second);
			}break;
			case ObjectState::RELEASE:
			{
				releaseObjectList.push_back(buff.second);
			}break;
			default:
			{
			
			}break;
		}
	}
}

void GameProcess::PutStateChangeBuffer(ObjectState state, IObject* pObject)
{
	stateChangeBuffer.push_back(make_pair(state, pObject));
}
