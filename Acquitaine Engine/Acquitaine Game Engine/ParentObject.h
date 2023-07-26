#pragma once
#include <vector>

#include "IObject.h"
#include "IComponent.h"
#include "string"

using namespace std;

class ParentScene;

class ParentObject : public IObject
{
public:
	ParentObject();
	virtual ~ParentObject();

public:
	virtual void AddComponent(IComponent* component);
	virtual void RemoveComponent();

private:
	virtual void Initialize() override;
	virtual void Finalize() override;

	virtual void Awake() override;
	virtual void Enable() override;
	virtual void Start() override;

	virtual void InputEvent() override;
	virtual void FixedUpdate() override;
	virtual void Update() override;

	virtual void Disable() override;
	virtual void Release() override;

private:
	static int objectIDs;					// �̰�... �����ڰ� ȣ�� �� ������ �ڵ����� 1�� ��������. �׸��� �װ� ID�� ��´�.

	int objectID;							// ���� �� ������Ʈ�� �����ϴ� �뵵�� ���� ID
	string objectName;						// ������Ʈ�� �̸�
	vector<IComponent*> componentList;		// ������Ʈ�� ������ �ִ� ������Ʈ�� ���

	///�Ҽӵ� Scene ����
	ParentScene* includedScene;
	int includedSceneID;
};

