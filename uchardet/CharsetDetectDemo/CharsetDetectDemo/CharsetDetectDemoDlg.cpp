
// CharsetDetectDemoDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CharsetDetectDemo.h"
#include "CharsetDetectDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCharsetDetectDemoDlg 对话框



CCharsetDetectDemoDlg::CCharsetDetectDemoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHARSETDETECTDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCharsetDetectDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCharsetDetectDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_DETECT_CHARSET, &CCharsetDetectDemoDlg::OnBnClickedButtonDetectCharset)
END_MESSAGE_MAP()


// CCharsetDetectDemoDlg 消息处理程序

BOOL CCharsetDetectDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCharsetDetectDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCharsetDetectDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCharsetDetectDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


#include "xtrace.h"
void CCharsetDetectDemoDlg::OnBnClickedButtonDetectCharset()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strFile = _T("");
	CFileDialog    dlgFile(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("*.*||"), NULL);
	if (dlgFile.DoModal())
	{
		strFile = dlgFile.GetPathName();
		if (!strFile.IsEmpty()) {
			XTRACE(L"filename: %s\n", strFile);

			CFile cfile;
			if (!cfile.Open(strFile, CFile::modeRead | CFile::typeBinary, NULL))
				return;

			int size = (int)cfile.GetLength();
			if (size > 0) {
				char *buf = (char *)malloc(size);
				if (size != cfile.Read(buf, size))
				{
					AfxMessageBox(L"读取文件错误", MB_ICONERROR);
				}
				else
				{
					int codepage = detectCodepage(buf, size);
					CString codepage2 = detectCodepage2(buf, size);
					XTRACE(L"code page: %s, %d\n", (LPCWSTR)codepage2, codepage);
				}
				free(buf);
			}
			cfile.Close();
		}
	}
}

#include "../../uchardet/uchardet.h"
#include "../../EncodingMapper.h"
int CCharsetDetectDemoDlg::detectCodepage(char* buf, size_t len)
{
	uchardet_t ud = uchardet_new();
	uchardet_handle_data(ud, buf, len);
	uchardet_data_end(ud);
	const char* cs = uchardet_get_charset(ud);
	int codepage = EncodingMapper::getInstance()->getEncodingFromString(cs);
	uchardet_delete(ud);
	return codepage;
}

CString CCharsetDetectDemoDlg::detectCodepage2(char* buf, size_t len)
{
	USES_CONVERSION;
	uchardet_t ud = uchardet_new();
	uchardet_handle_data(ud, buf, len);
	uchardet_data_end(ud);
	const char* cs = uchardet_get_charset(ud);
	CString result = A2W(cs);
	uchardet_delete(ud);
	return result;
}
