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
	PutStateChangeBuffer();
	
	/// ��ũ���� �Ҷ� ���̴� �κФѤѤѤѤѤѤѤѤѤ�
	// �ʱ�ȭ,�߰�, ����
	Awake();
	Enable();
	Start();

	// ��ǲ �Է�, ��������, ������Ʈ
	InputEvent(); /// ��� ��ũ���� �Ҷ� ������ �ʰ� �Ұ�.
	while (fixedupdateTimeRate > FixedUpdate());	//���������� �� �κ�. ����ð��� fixedupdatetime���� �۴ٸ� �Ƚ��� ������Ʈ�� �ݺ� �����Ѵ�.
	Update();

	// ��Ȱ��ȭ, ��� ����
	Disable();
	Release();

	/// ��ũ���� �Ҷ� ������ �ʴ� �κФѤѤѤѤѤѤѤѤѤ�
	CreateObjects();
	InitializeObjects();
}

void GameProcess::CreateObjects()
{
}

void GameProcess::InitializeObjects()
{
}

void GameProcess::Awake()
{
}

void GameProcess::Enable()
{
}

void GameProcess::Start()
{
}

void GameProcess::InputEvent()
{
}

float GameProcess::FixedUpdate()
{
	///���������� ����Ǵ� �κ��̰�, ���� �ð��� �ʴ����� ��ȯ�ϵ��� ����
}

void GameProcess::Update()
{
}

void GameProcess::Render()
{
}

void GameProcess::Disable()
{
}

void GameProcess::Release()
{
}

void GameProcess::ObjectStateChange()
{
}

void GameProcess::PutStateChangeBuffer()
{
}
