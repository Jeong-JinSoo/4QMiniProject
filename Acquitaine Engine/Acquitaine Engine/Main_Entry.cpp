/// 
/// 
///
#include "MainProcess.h" 

class GameProcess;
#define MAXLOADSTRING 100

//����
HINSTANCE hInst;
WCHAR szTitle[MAXLOADSTRING];
WCHAR szWindowClass[MAXLOADSTRING];

void test() {};

int WINAPI WinMain(_In_ HINSTANCE hInstance,_In_opt_ HINSTANCE hPrevInstance,
					_In_ LPSTR lpCmdLine, _In_ int nCmdShow){
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	//���� ���μ��� �ν��Ͻ� ����
	MainProcess* mainProcess = new MainProcess();

	// ���μ��� �ʱ�ȭ
	mainProcess->Initialize(hInstance);

	// ���� ����
	mainProcess->Loop();

	// ���α׷� ����
	mainProcess->Finalize();

	delete mainProcess;
}