#include "ParentScene.h"

ParentScene::ParentScene()
	:gameProcess(GameProcess::gameEnginePointer)
{
}

ParentScene::~ParentScene()
{
}

void ParentScene::Initialize()
{	
	gameProcess->AddScene(this);
}

void ParentScene::Finalize()
{
	//���⼭ gameProcess ���� ������!!!
}

void ParentScene::RemoveObject()
{
}

void ParentScene::FindObject()
{
	cout << "�ִµ�?";
}

void ParentScene::ChangeObjectState()
{
}