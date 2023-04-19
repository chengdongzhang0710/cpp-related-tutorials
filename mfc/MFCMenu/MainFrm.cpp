
// MainFrm.cpp : implementation of the CMainFrame class
//

#include "pch.h"
#include "framework.h"
#include "MFCMenu.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_UPDATE_COMMAND_UI(ID_ITEMA_SUB, &CMainFrame::OnUpdateItemaSub)
	ON_COMMAND(ID_ITEMA_SUBITEM2, &CMainFrame::OnItemaSubitem2)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame construction/destruction

CMainFrame::CMainFrame() noexcept
{
	// TODO: add member initialization code here

	m_bAutoMenuEnable = FALSE;  // 使禁用菜单功能生效
	m_isUpdate = false;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: Delete these three lines if you don't want the toolbar to be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	// 获取菜单
	CMenu* menu = GetMenu();  // 获取主菜单
	CMenu* fileMenu = menu->GetSubMenu(0);  // 获取子菜单
	fileMenu->CheckMenuItem(0, MF_BYPOSITION | MF_CHECKED);  // 通过位置确定
	fileMenu->CheckMenuItem(ID_FILE_OPEN, MF_BYCOMMAND | MF_CHECKED);  // 通过ID确定

	// 设置默认项(加粗)
	fileMenu->SetDefaultItem(ID_FILE_SAVE, FALSE);  // FALSE - ID，TRUE - 位置

	// 禁用菜单(变灰)
	fileMenu->EnableMenuItem(5, MF_BYPOSITION | MF_DISABLED);
	
	// 移除菜单项
	SetMenu(NULL);

	// 加载菜单
	CMenu menu2;
	menu2.LoadMenuW(IDR_MENU1);
	SetMenu(&menu2);

	// 分离
	menu2.Detach();  // 解决menu2作为局部变量带来的问题

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame message handlers



void CMainFrame::OnUpdateItemaSub(CCmdUI* pCmdUI)
{
	// TODO: Add your command update UI handler code here

	if (m_isUpdate)
	{
		pCmdUI->Enable(TRUE);
	}
	else
	{
		pCmdUI->Enable(FALSE);
	}
}


void CMainFrame::OnItemaSubitem2()
{
	// TODO: Add your command handler code here

	m_isUpdate = !m_isUpdate;
}
