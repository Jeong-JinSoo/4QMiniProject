#include "ParentObject.h"
#include "ParentComponent.h"

int ParentObject::_objectIDs;

ParentObject::ParentObject()
	:objectName("Empty_name_space"), _objectID(0), _componentList(0)
	, _includedScene(nullptr), _includedSceneID(0), isEnabled(true)
{
	_objectIDs = 0;

	_objectIDs++;
	_objectID = _objectIDs;
}

ParentObject::~ParentObject()
{
}

vector<ParentComponent*> ParentObject::GetComponentlist()
{
	return _componentList;
}

void ParentObject::RemoveComponent()
{
}

void ParentObject::Initialize()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Initialize();
	}
}

void ParentObject::Finalize()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Finalize();
	}
}

void ParentObject::Awake()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Awake();
	}
}

void ParentObject::Enable()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Enable();
	}
}

void ParentObject::Start()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Start();
	}
}

void ParentObject::InputEvent()
{
}

void ParentObject::FixedUpdate()
{
	for (auto pComponent : _componentList)
	{
		pComponent->FixedUpdate();
	}
}

void ParentObject::Phsics()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Phsics();
	}
}

void ParentObject::Update()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Update();
	}
}

void ParentObject::Render()
{
	for (auto pComponent : _componentList)
	{
		if (isEnabled)
		{
			pComponent->Render();
		}
	}
}

void ParentObject::Disable()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Disable();
	}
}

void ParentObject::Release()
{
	for (auto pComponent : _componentList)
	{
		pComponent->Release();
	}
	Finalize();
}
