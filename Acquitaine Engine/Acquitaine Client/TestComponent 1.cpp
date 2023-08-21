#include "TestComponent 1.h"
#include "TestComponent 2.h"
#include "ParentObject.h"
#include "TransformComponent.h"

TestComponent1::TestComponent1(string name, act::ParentObject* pObject)
{
	_componentName = name;
	_gameObject = pObject;
	cout << _gameObject->objectName << " : component1 Initialize is sucessed." << endl;
}

TestComponent1::~TestComponent1()
{

}

void TestComponent1::Awake()
{
}

void TestComponent1::Enable()
{
	cout << _gameObject->objectName << " : component1 Enable is sucessed." << endl;
}

void TestComponent1::Start()
{
	cout << _gameObject->objectName << " : component1 Start is sucessed." << endl;
	TransformComponent* tempcomp = _gameObject->GetComponentPointer<TransformComponent>();
	tempcomp->SetPosition(12.0f, 8.0f, 10.0f);
}

void TestComponent1::FixedUpdate()
{
}

void TestComponent1::Update()
{
	cout << _gameObject->objectName << " : component1 Update is sucessed." << endl;
	//_gameObject->AddComponent<TestComponent2>("test", _gameObject);
	TransformComponent* tempcomp = _gameObject->GetComponentPointer<TransformComponent>();
	tempcomp->SetPosition(tempcomp->GetPosition().x+1, 8.0f, 10.0f);
	cout << tempcomp->GetPosition().x << " " << tempcomp->GetPosition().y << " " << tempcomp->GetPosition().z << " " << endl;
}

void TestComponent1::Disable()
{
	cout << _gameObject->objectName << " : component2 Disable is sucessed." << endl;
	_gameObject->SetActive(true);
}

void TestComponent1::Release()
{
}
