#pragma once
#include <vector>

#include "IObject.h"
#include "ParentScene.h"
#include "GameProcess.h"

using namespace std;

class ParentScene
{
public:
	ParentScene();
	~ParentScene();
public:
	void Initialize();
	void Finalize();

public:
	template<typename T>
	void AddObject()
	{
		gameProcess->CreateObjects<T>();
	}

	void RemoveObject();
	void FindObject();
	void ChangeObjectState();

private:
	vector<IObject*>  inControlObjects;
	const GameProcess* const gameProcess;
	// �̰� �̷��� �� ����? ���� ������ ������ ���� �� �� �ۿ� ���µ�
	// ���� ������ �����͸� ������ �� ���� �� �ʿ�� ������ ����
	// ���ÿ� �ٸ� ���� ���μ����� �����ǰų� �Ҵ�Ǵ°� ���� �ȵǹǷ� const�� ����.
};

/// Scene ����
//  ���� ������Ʈ���� �� Scene�� ���ӿ�����Ʈ�� ������ ������ �и��Ǿ� ���� SceneManager�� ���� ���� ���ư��� ���� ������
//  �̹��� Scene�� �и��ؼ� Scene�� ��ũ���� �������� ��ƺ����� �Ѵ�.
//  Scene�� CreateObject �Լ��� �ּ� ������Ʈ�� �����ϰ�
//  ������ ������Ʈ�� Scene�� inControlObjects�� ������ ObjectList�� �߰���
//  ��... Scene�� inControlObjects���� ������Ʈ���� �����Ѵ�.(������ ������ ��û�ϴ°�����)
//  �ϴ��� Scene�� ������Ʈ�� ��Ƶΰ� �����ϴ� �߰� �ܰ�� ����.
//  ��¶�� ������ ¥�� ���ӿ����� �ǵ� �� ���� �ϴ°� ��ǥ.

/// Scene �Ŵ����� �����ϴ� ���� �´°�?
//	���ʿ��� ���̾� ������ �ƴ����� ���� ����.
//	�ϴ� ��� ���� ���� ���μ����� �����°� ���� �� ����.
//	�׸��� �� �Ŵ����� ���� scene�� ���� �Ѵٰ� �ص� �ᱹ�� scene���� ������Ʈ�� ������ �شٸ� gamaprocess�� �����ؾ� �ϴµ�
//	�׷��� �ᱹ const������ �ذ� ���� �ʰ� �Ѿ ���� ����. ��� �ؾ� �ϴ°�?