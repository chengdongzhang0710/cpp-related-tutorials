#include <Windows.h>

// 窗口过程函数
// HWND hWnd - 窗口句柄，消息所属的窗口
// UINT uMsg - 消息标志
// WPARAM wParam - 附加信息
// LPARAM lParam - 附加信息
LRESULT CALLBACK DealMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		MessageBox(hWnd, TEXT("Mouse Left Button Down!"), TEXT("Message"), MB_OK);
		break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC dc = BeginPaint(hWnd, &ps);
		TCHAR* p = L"ABC";  // 转换为宽字节
		TextOutW(dc, 30, 30, p, wcslen(p));
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(2);  // WM_QUIT，给主函数return msg.wParam
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
}

// WINAPI - 修饰函数，规定函数参数入栈从右往左，函数调用完毕自动清理堆栈
// HINSTANCE hInstance - 应用程序实例
// HINSTANCE hPrevInstance - 上一个应用程序实例，不用
// LPSTR lpCmdLine - Long Pointer String(Char*)，命令行参数
// int nCmdShow - 窗口显示的样式，最大化/最小化
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	// 设计窗口类WNDCLASS
	WNDCLASS wc;
	wc.cbClsExtra = 0;  // 类的附加信息
	wc.cbWndExtra = 0;  // 窗口附加信息
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  // 背景色，必须填；(HBRUSH)GetStockObject(WHITE_BRUSH)获取系统默认的白色画刷
	wc.hCursor = LoadCursor(NULL, IDC_HELP);  // 加载系统默认光标；= NULL使用默认
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);  // 加载系统默认图标；= NULL使用默认
	wc.hInstance = hInstance;  // 应用程序实例
	wc.lpfnWndProc = DealMessage;  // 窗口过程函数名字，消息处理函数
	wc.lpszClassName = TEXT("test");  // 类的名字
	wc.lpszMenuName = NULL;  // 菜单名字
	wc.style = nCmdShow;  // 显示风格

	// 注册窗口类，告诉系统窗口过程函数的入口地址
	RegisterClass(&wc);

	// 创建窗口类
	HWND hWnd = CreateWindow(TEXT("test"), TEXT("Hello Windows"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	// 显示和更新窗口
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	// 消息循环
	MSG msg;
	// 如果接收到WM——QUIT，返回0，退出
	// 如果出错，返回-1，不退出
	while (GetMessage(&msg, NULL, 0, 0))
	{
		// 翻译工作
		// 虚拟按键转换为标准字符WM_CHAR
		TranslateMessage(&msg);
		
		// 给操作系统分发消息
		DispatchMessage(&msg);
	}

	return msg.wParam;
}
