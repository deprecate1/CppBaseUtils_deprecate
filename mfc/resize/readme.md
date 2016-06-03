用法：

	#include "resizer.h"

在mfc对话框头文件里面添加成员：

	CResizer			m_Resizer;

mydialog.cpp里面：

	OnInitDialog()
	{
		......

		// TODO: 在此添加额外的初始化代码
		m_Resizer.Initialize(*this, CRect(0, 0, 0, 0));
		m_Resizer.AddChild(m_btn1, bottomright, 0);		// m_btn1是CButton
		m_Resizer.AddChild(m_btn2, bottomright, 0);		// m_btn1是CButton
	}

	LRESULT CMFCApplication1Dlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
	{
		// TODO: 在此添加专用代码和/或调用基类
		m_Resizer.HandleMessage(message, wParam, lParam);
	
		return CDialogEx::DefWindowProc(message, wParam, lParam);
	}
