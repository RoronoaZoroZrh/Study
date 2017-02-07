/********************************************************************
@file     Main.cpp
@date     2017-2-7
@author   Zoro_Tiger
@brief    »æÖÆÍ¼Ôª
********************************************************************/
#include <d3d9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

#define WINDOW_CLASS  "Chapter 3 Class"
#define WINDOW_NAME   "Chapter 3 Window"
#define D3DFVF_VERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

typedef struct _D3DVertex
{
	float x, y, z, rhw;
	unsigned long color;
}D3DVertex;

LPDIRECT3D9 g_D3D = NULL;
LPDIRECT3DDEVICE9 g_D3DDevice = NULL;
LPDIRECT3DVERTEXBUFFER9 g_VertexBuffer = NULL;

bool InitializeD3D(HWND hWnd, bool bFullScreen);
bool InitializeObjects(void);
void RenderScene(void);
void ShutDown(void);

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
				break;
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
	if (FAILED(RegisterClassEx(&wndClass)))
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
	if (InitializeD3D(hWnd, false))
	{
		ShowWindow(hWnd, SW_SHOWDEFAULT);
		UpdateWindow(hWnd);

		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));
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

	if (FAILED(UnregisterClass(WINDOW_CLASS, hInstance)))
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
	ZeroMemory(&d3dpp, sizeof(D3DPRESENT_PARAMETERS));
	if (bFullScreen)
	{
		d3dpp.Windowed = FALSE;
		d3dpp.BackBufferWidth  = 640;
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
		D3DCREATE_HARDWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_D3DDevice)))
	{
		return false;
	}

	if (!InitializeObjects())
	{
		return false;
	}

	return true;
}

bool InitializeObjects(void)
{
	unsigned long color = D3DCOLOR_XRGB(255, 255, 0);
	D3DVertex vertexArray[] = {
		{ 200.0f, 160.0f, 0.0f, 1.0f, color },
		{ 400.0f, 160.0f, 0.0f, 1.0f, color },
		{ 200.0f, 320.0f, 0.0f, 1.0f, color },
		{ 400.0f, 320.0f, 0.0f, 1.0f, color },
	};

	if (FAILED(g_D3DDevice->CreateVertexBuffer(sizeof(vertexArray),
		0,
		D3DFVF_VERTEX,
		D3DPOOL_DEFAULT,
		&g_VertexBuffer,
		NULL)))
	{
		return false;
	}

	void* ptr = NULL;
	if (FAILED(g_VertexBuffer->Lock(0,
		sizeof(vertexArray),
		(void**)&ptr,
		0)))
	{
		return false;
	}

	memcpy(ptr, vertexArray, sizeof(vertexArray));

	g_VertexBuffer->Unlock();

	return true;
}

void RenderScene(void)
{
	g_D3DDevice->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	g_D3DDevice->BeginScene();

	g_D3DDevice->SetStreamSource(0, g_VertexBuffer, 0, sizeof(D3DVertex));
	g_D3DDevice->SetFVF(D3DFVF_VERTEX);
	g_D3DDevice->DrawPrimitive(D3DPT_LINELIST, 0, 2);

	g_D3DDevice->EndScene();

	g_D3DDevice->Present(NULL, NULL, NULL, NULL);
}

void ShutDown(void)
{
	if (g_VertexBuffer != NULL)
	{
		g_VertexBuffer->Release();
		g_VertexBuffer = NULL;
	}

	if (g_D3DDevice != NULL)
	{
		g_D3DDevice->Release();
		g_D3DDevice = NULL;
	}

	if (g_D3D != NULL)
	{
		g_D3D->Release();
		g_D3D = NULL;
	}
}