#pragma once
#include <vector>
#include <string>

#include "IObject.h"
#include "IComponent.h"

using namespace std;

class ParentScene;
class ParentComponent;

class ParentObject : public IObject
{
public:
	ParentObject();
	virtual ~ParentObject();

public:
	template<typename T>
	void AddComponent()
	{
		IComponent* temp = new T();
		componentList.push_back(temp);
	}

	void RemoveComponent();

//private:
public:
	virtual void Initialize() override;
	virtual void Finalize() override;

	virtual void Awake() override;
	virtual void Enable() override;
	virtual void Start() override;

	virtual void InputEvent() override;
	virtual void FixedUpdate() override;
	virtual void Phsics() override;
	virtual void Update() override;

	virtual void Render() override;

	virtual void Disable() override;
	virtual void Release() override;

private:
	static int objectIDs;					// �̰�... �����ڰ� ȣ�� �� ������ �ڵ����� 1�� ��������. �׸��� �װ� ID�� ��´�.

	/// ������Ʈ�� ���� ������ ����Ǿ� �ִ� �κ�
	int objectID;							// ���� �� ������Ʈ�� �����ϴ� �뵵�� ���� ID
	string objectName;						// ������Ʈ�� �̸�
	vector<IComponent*> componentList;		// ������Ʈ�� ������ �ִ� ������Ʈ�� ���
	bool isEnabled;

	///�Ҽӵ� Scene ����
	ParentScene* includedScene;
	int includedSceneID;
};

