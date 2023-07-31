#include "GameProcess.h"
#include "TestScene.h"

import aptoCore.Graphics;



GameProcess::GameProcess()
{
}

GameProcess::~GameProcess()
{
}

void GameProcess::Initialize()
{
	gameEnginePointer = this;
	bool ret = aptoCore::Graphics::Initialize();
	aptoCore::Graphics::Render(1.0f);
}

void GameProcess::Finalize()
{
	aptoCore::Graphics::Finalize();
}

void GameProcess::RunningGameProcess(double deltaTime)
{
	cout << "���� ���� ��" << endl;

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
	InitializeObjects();
}

void GameProcess::AddScene(ParentScene* pscene) const
{
	SceneList.push_back(pscene);
}

void GameProcess::InitializeObjects()
{
	for (auto pObject : waitingObjectList)
	{
		pObject->Initialize();
		PutStateChangeBuffer(ObjectState::START, pObject);
	}
}

void GameProcess::Awake()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Awake();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::Enable()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Enable();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::Start()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Start();
		PutStateChangeBuffer(ObjectState::UPDATE, pObject);
	}
}

void GameProcess::InputEvent()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->InputEvent();
	}
}

float GameProcess::FixedUpdate()
{
	///���������� ����Ǵ� �κ��̰�, ���� �ð��� �ʴ����� ��ȯ�ϵ��� ����
	for (auto pObject : awakeObjectList)
	{
		pObject->FixedUpdate();
		pObject->Phsics();
	}

	return 0.0;
}

void GameProcess::Update()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Update();
	}
}

void GameProcess::Render()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Render();
	}
}

void GameProcess::Disable()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Disable();
	}
}

void GameProcess::Release()
{
	for (auto pObject : awakeObjectList)
	{
		pObject->Release();
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

const GameProcess* GameProcess::gameEnginePointer;