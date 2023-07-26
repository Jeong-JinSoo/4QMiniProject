#pragma once
#include <windows.h>
#include "Timer.h"

class DX_GraphicsMain;

class MainProcess
{
public:
	HRESULT Initialize(HINSTANCE hInstance);
	void Loop();
	void Finalize();

	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

private:
	HWND m_hWnd;
	MSG m_msg;
	HINSTANCE m_hInstance;

	// �ð��� ���õ� �κ�
	Timer* timer;
	double deltatime;
};

