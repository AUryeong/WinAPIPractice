#include "pch.h"
#include "GameManager.h"

static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreInstance, _In_ LPTSTR lpCmdLine, _In_ int nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// _CrtSetBreakAlloc(13746);

	WNDCLASS wndClass = { 0, };
	wndClass.lpszClassName = TEXT("King God Castle");
	wndClass.lpszMenuName = nullptr;
	wndClass.hInstance = hInstance;
	wndClass.lpfnWndProc = WndProc;
	wndClass.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_KINGGODCASTLECOPYPRACTICE));
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&wndClass);

	HWND hWnd = CreateWindow(wndClass.lpszClassName, wndClass.lpszClassName, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		nullptr, nullptr, wndClass.hInstance, nullptr);

	ShowWindow(hWnd, nCmdShow);

	GameManager::GetInstance()->Init(hWnd, wndClass.hInstance);

	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE) == false)
		{
			GameManager::GetInstance()->Update();
			GameManager::GetInstance()->Render();
			continue;
		}

		if (msg.message == WM_QUIT)
		{
			break;
		}
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	GameManager::GetInstance()->Release();

	return static_cast<int>(msg.wParam);
}

static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_DESTROY)
	{
		PostQuitMessage(0);
		return S_OK;
	}

	return DefWindowProc(hWnd, msg, wParam, lParam);
}