#pragma once
//#include <string>

struct Renderable;

class IDX11Render abstract
{
public:
	IDX11Render() {}
	virtual ~IDX11Render() {};	// �������̽� �Ҹ��ڴ� virtual��

	virtual long Initialize(void* hwnd) abstract;

	virtual void Update(float deltaTime) abstract;
	virtual void Render() abstract;
	virtual void BeginRender(float red, float green, float blue, float alpha) abstract;
	virtual void DrawObject() abstract;
	virtual void EndRender()  abstract;

	virtual void Finalize() abstract;
};

// dll�ܺο��� ��밡���� �Լ���� �˷��ִ� ��
extern "C" __declspec(dllexport) IDX11Render * CreateRenderer();
extern "C" __declspec(dllexport) void DeleteRenderer(IDX11Render * renderer);

// ���������� �������̽��� ������
extern "C" __declspec(dllexport) bool Initialize();
extern "C" __declspec(dllexport) void Finalize();
extern "C" __declspec(dllexport) void Render(float deltaTime);
extern "C" __declspec(dllexport) bool Resize(unsigned __int32 screenWidth, unsigned __int32 screenHeight);
extern "C" __declspec(dllexport) void RegisterObject(Renderable & object);
extern "C" __declspec(dllexport) void DeregisterObject(Renderable & object);

