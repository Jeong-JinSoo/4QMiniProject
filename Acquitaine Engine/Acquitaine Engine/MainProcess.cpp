#include "MainProcess.h"
#include "GameProcess.h"

#pragma comment (lib,"Acquitaine Game Engine.lib")

constexpr int windowLength = 1280;
constexpr int windowHeight = 720;

constexpr int windowPositionX = 500;
constexpr int windowPositionY = 100;

HRESULT MainProcess::Initialize(HINSTANCE hInstance)
{
	/// Win32 ����
	// ���� Ŭ����
	LPCWSTR szAppName = L"Acquitain Project";
	WNDCLASS wndclass;

	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc = this->WindowProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.hInstance = hInstance;
	wndclass.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szAppName;

	// ���� Ŭ���� ���
	RegisterClass(&wndclass);

	// ���� ����
	m_hWnd = CreateWindow(
		szAppName,
		szAppName,
		WS_OVERLAPPEDWINDOW,
		windowPositionX, windowPositionY, windowLength, windowHeight,
		NULL, NULL, hInstance, NULL);

	if (!m_hWnd) return S_FALSE;

	// ������ ������ ȭ�鿡 ǥ��
	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	UpdateWindow(m_hWnd);

	// �����, �׽�Ʈ�� �ܼ��� ����
 	AllocConsole();
	FILE* _tempFile;
	freopen_s(&_tempFile, "CONOUT$", "w", stdout);

	deltatime = 0;
	timer = new Timer();
	
	gameprocess = new GameProcess();
	gameprocess->Initialize();


	///���� �Ʒ��� �׷��Ƚ�

	///
 	return S_OK;
}

void MainProcess::Loop()
{
	while (true)
	{
		if (PeekMessage(&m_msg, NULL, 0, 0, PM_REMOVE))
		{
			if (m_msg.message == WM_QUIT) break;
			DispatchMessage(&m_msg);
		}
		else
		{
			// ��Ÿ Ÿ���� ������ �κ�
			timer->Update();
			deltatime = timer->GetDeltaTime();

			// ���� ������ ��ġ�� ����
			gameprocess->RunningGameProcess(deltatime);
		}
	}
}

void MainProcess::Finalize()
{
	gameprocess->Finalize();
}

LRESULT CALLBACK MainProcess::WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		case WM_CREATE:
			break;
		case WM_RBUTTONDOWN:
			return 0;
		case WM_RBUTTONUP:
			return 0;
		case WM_MOUSEMOVE:
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			FreeConsole();
			return 0;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}
