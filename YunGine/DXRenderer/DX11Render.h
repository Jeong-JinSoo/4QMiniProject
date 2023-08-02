#pragma once
#include "IDX11Render.h"

using namespace std;
/// <summary>
/// 차근차근 천천히 dll화 시켜보자
/// 23.06.20
/// </summary>

// DirectX 11에서 3D그래픽을 설정하고 그리기 위한 모든 D3D기능이 포함되어 있다.
#pragma comment(lib, "d3d11.lib")
// 모니터의 재생을 위한 라이브러리
#pragma comment(lib, "dxgi.lib")
// 셰이더 컴파일링 기능
#pragma comment(lib, "d3dcompiler.lib") 
// 이펙트 라이브러리
#ifdef _DEBUG
#pragma comment(lib, "..\\Lib\\Effects11d.lib")
#else
#pragma  comment(lib, "..\\Lib\\Effects11.lib")
#endif

/// 릴리즈 모드에서 RuntimeLibrary에 대해 불일치가 검색되었습니다. 에러가 발생중
/// -23.07.19- 인재원에서
///  #pragma comment를 사용해서 파일을 쓰겠다고 했다면 속성에서 종속성을 풀어줘야 한다. 에러 해결
/// -23.07.21- 인재원에서

#include "Vertex.h"

//스마트 포인터를 사용하기 위한 헤더
#include <wrl\client.h>

// 어댑터를 위한 헤더
// 상위헤더 참조시 하위헤더는 자동으로 포함된다
#include <d3d11_4.h>
#include <dxgi1_2.h>

class Axis;
class Cube;
class Grid;
class Camera;
class FbxLoaderV2;

class DX11Render : public IDX11Render
{
public:
	// 싱글톤으로 하는게 좋을까?
	DX11Render();
	virtual ~DX11Render();

	/// <summary>
	/// dll로 만들면 이 함수들을 모두 하나로 묶어서 사용해야하나?
	/// __declspec(dllexport)func(int a, int b)
	/// -23.06.20 -kocca, Dispact-
	/// </summary>
	/// 
	// bool값으로 만들어서 return false를 반환해야한다.
	virtual long Initialize(void* hwnd) override;	// 그래픽 엔진 초기화

	virtual void Update(float deltaTime) override;
	virtual void Render() override;
	virtual void BeginRender(float red, float green, float blue, float alpha) override;
	virtual void DrawObject() override;
	virtual void EndRender() override;

	HRESULT InitVB();

	virtual void Finalize() override;

private:
	// void OnResize(); 
	// Message쪽에서 사이즈가 재정의 됬을때 호출하는 함수이지만 일단 보류
	// Render 함수 내에서 사용할 것들

	HRESULT CreateDevice();
	HRESULT CreateSwapChain(HWND hWnd);
	HRESULT CreateBackBuffer();
	HRESULT CreateRaster();
	// HRESULT CreateInputLayout();

	// 오브젝트들 생성하기
	HRESULT CreateObject();
	HRESULT CreateLoader();
	HRESULT CreateCamera();
	HRESULT CreateCube();
	HRESULT CreateGrid();
	HRESULT CreateAxis();

	// 시간 변수
	float _deltaTime;

private:
	//int mVideoCardMemory;	// 블로그에서는 있지만 어디다가 쓰는걸까?
	//char mVideoCardDescription[128];
	// 
	// s_SwapChain에서 Preset할 때 필요했던 변수 하지만 굳이?
	//bool bVsyncEnabled = false;
	Microsoft::WRL::ComPtr<ID3D11Device> _p3DDevice;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext> _p3DDeviceContext;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView> _pRenderTargetView;

	Microsoft::WRL::ComPtr<ID3D11Texture2D> _pTexture2D;

	// 뎁스 스탠실
	Microsoft::WRL::ComPtr<ID3D11DepthStencilState> _pDepthStencilState;
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView> _pDepthStencilView;

	// 레스터 상태
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> _pCurrRasterState;	// 현재 레스터
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> _pSolidRasterState;	// 채우는 레스터
	Microsoft::WRL::ComPtr<ID3D11RasterizerState> _pWireRasterState;	// 와이어 레스터-> 선으로 나타낸다는뜻

	// 스왑체인을 만들기 위한 변수
	Microsoft::WRL::ComPtr<IDXGISwapChain> s_SwapChain;
	Microsoft::WRL::ComPtr<IDXGIDevice3> s_dxgiDevice;
	Microsoft::WRL::ComPtr<ID3D11Texture2D>_pbackBuffer;

	// Direct2D와 같은 다른 Factory에서 사용할 DXGI 장치 개체를 만듭니다.
	Microsoft::WRL::ComPtr<IDXGIDevice3> dxgiDevice;

	// 매트릭스
	DirectX::XMFLOAT4X4 _worldMatrix;
	DirectX::XMFLOAT4X4 _viewMatrix;
	DirectX::XMFLOAT4X4 _projectionMatrix;

	// 오브젝트
	Axis* _pAxis;
	Grid* _pGrid;
	Cube* _pCube;
	Camera* _pCamera;
	FbxLoaderV2* _pLoaderV2;

	// 버퍼
	ID3D11Buffer* VertexBuffer;
	ID3D11Buffer* IndexBuffer;

};

