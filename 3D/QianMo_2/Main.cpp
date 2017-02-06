/********************************************************************
@file     Main.cpp
@date     2017-2-6
@author   Zoro_Tiger
@brief    最简单的DirectX、vc窗口的编写
********************************************************************/
#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#define WINDOW_CLASS "Chapter 2 Class"
#define WINDOW_NAME  "Chapter 2 Window"

bool InitializeD3D(HWND hWnd, bool bFullScreen);
void RenderScene(void);
void ShutDown(void);

LPDIRECT3D9 g_D3D = NULL;
LPDIRECT3DDEVICE9 g_D3DDevice = NULL;

LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
			break;
		}
	case WM_KEYUP:
		{
			if (wParam == VK_ESCAPE)
			{
				PostQuitMessage(0);
			}
		}
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	WNDCLASSEX wndClass = {
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		WndProc,
		0,
		0,
		hInstance,
		NULL,
		NULL,
		NULL,
		NULL,
		WINDOW_CLASS,
		NULL,
	};

	if (!RegisterClassEx(&wndClass))
	{
		return -1;
	}

	HWND hWnd = CreateWindow(WINDOW_CLASS,
		WINDOW_NAME,
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		640,
		480,
		GetDesktopWindow(),
		NULL,
		hInstance,
		NULL);
	if (NULL == hWnd)
	{
		return -1;
	}

	if (InitializeD3D(hWnd, false))
	{
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		MSG msg;
		ZeroMemory(&msg, sizeof(msg));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				RenderScene();
			}
		}
	}

	ShutDown();

	if (!UnregisterClass(WINDOW_CLASS, wndClass.hInstance))
	{
		return -1;
	}

	return 0;
}

bool InitializeD3D(HWND hWnd, bool bFullScreen)
{
	g_D3D = Direct3DCreate9(D3D_SDK_VERSION);
	if (NULL == g_D3D)
	{
		return false;
	}

	D3DDISPLAYMODE displayMode;
	if (FAILED(g_D3D->GetAdapterDisplayMode(D3DADAPTER_DEFAULT, &displayMode)))
	{
		return false;
	}

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	if (bFullScreen)
	{
		d3dpp.Windowed = FALSE;
		d3dpp.BackBufferWidth = 640;
		d3dpp.BackBufferHeight = 480;
	}
	else
	{
		d3dpp.Windowed = TRUE;
	}
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = displayMode.Format;

	if (FAILED(g_D3D->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_D3DDevice)))
	{
		return false;
	}

	return true;
}

void RenderScene(void)
{
	g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);
	g_D3DDevice->BeginScene();
	g_D3DDevice->EndScene();
	g_D3DDevice->Present(NULL, NULL, NULL, NULL);
}

void ShutDown(void)
{
	if (g_D3D != NULL)
	{
		g_D3D->Release();
		g_D3D = NULL;
	}

	if (g_D3DDevice != NULL)
	{
		g_D3DDevice->Release();
		g_D3DDevice = NULL;
	}
}