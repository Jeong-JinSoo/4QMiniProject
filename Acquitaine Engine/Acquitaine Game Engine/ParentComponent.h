#pragma once
#include <string>

#include "IComponent.h"
#include "IObject.h"

using namespace std;

class ParentComponent : IComponent
{
public:
	ParentComponent();
	~ParentComponent();

//private:
public:
	virtual void Initialize() override;
	virtual void Finalize() override;

	virtual void Awake() override;
	virtual void Enable() override;
	virtual void Start() override;

	virtual void InputEvent() override;
	virtual void FixedUpdate() override;
	virtual void Update() override;

	virtual void Render() override;

	virtual void Disable() override;
	virtual void Release() override;

	virtual void SetGameObject(IObject* parentObject);

private:
	string ComponentName;		// ������Ʈ�� �̸�
	static int componentIDs;	// ������Ʈ�� ID? ���� �־�� �Ұ� ���Ƽ�.
	int componentID;			// ������Ʈ�� ID.
	IObject* gameObject;		// ���� �Ҽӵ� ������Ʈ
	bool isEnabled;				// ������Ʈ�� Ȱ��ȭ �Ǿ� �ִ���? �ƴ���.
};