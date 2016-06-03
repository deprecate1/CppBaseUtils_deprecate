#ifndef __RESIZER_MFC_H
#define __RESIZER_MFC_H
#include <vector>

// Resize Dialog Styles
#define RD_STRETCH_WIDTH		0x0001	// The item has a variable width
#define RD_STRETCH_HEIGHT		0x0002	// The item has a variable height

// Resize Dialog alignments
enum Alignment { topleft, topright, bottomleft, bottomright };

// Define our own MIN and MAX macros
// this avoids inconsistencies with Dev-C++ and other compilers, and
// avoids conflicts between typical min/max macros and std::min/std::max
#define MAX(a,b)            (((a) > (b)) ? (a) : (b))
#define MIN(a,b)            (((a) < (b)) ? (a) : (b))

class CResizer
{
public:
	CResizer() : m_hParent(0), m_xScrollPos(0), m_yScrollPos(0) {}
	~CResizer() {}

	void AddChild(HWND hWnd, Alignment corner, DWORD dwStyle);
	void HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void Initialize(HWND hParent, const RECT& rcMin, const RECT& rcMax = CRect(0,0,0,0));
	void OnHScroll(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnVScroll(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void RecalcLayout();
	CRect GetMinRect() const { return m_rcMin; }
	CRect GetMaxRect() const { return m_rcMax; }

	struct ResizeData
	{
		CRect rcInit;
		CRect rcOld;
		Alignment corner;
		BOOL bFixedWidth;
		BOOL bFixedHeight;
		HWND hWnd;
	};

private:
	HWND m_hParent;
	std::vector<ResizeData> m_vResizeData;

	CRect m_rcInit;
	CRect m_rcMin;
	CRect m_rcMax;

	int m_xScrollPos;
	int m_yScrollPos;
};



/////////////////////////////////////
// Definitions for the CResizer class
//

void inline CResizer::AddChild(HWND hWnd, Alignment corner, DWORD dwStyle)
	// Adds a child window (usually a dialog control) to the set of windows managed by
	// the Resizer.
	//
	// The alignment corner should be set to the closest corner of the dialog. Allowed
	// values are topleft, topright, bottomleft, and bottomright.
	// Set bFixedWidth to TRUE if the width should be fixed instead of variable.
	// Set bFixedHeight to TRUE if the height should be fixed instead of variable.
{
	//assert(hWnd);

	ResizeData rd;
	rd.corner = corner;
	rd.bFixedWidth = !(dwStyle & RD_STRETCH_WIDTH);
	rd.bFixedHeight = !(dwStyle & RD_STRETCH_HEIGHT);
	CRect rcInit;
	::GetWindowRect(hWnd, &rcInit);
	::MapWindowPoints(NULL, m_hParent, (LPPOINT)&rcInit, 2);
	rd.rcInit = rcInit;
	rd.hWnd = hWnd;

	m_vResizeData.insert(m_vResizeData.begin(), rd);
}

inline void CResizer::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
		case WM_SIZE:
			RecalcLayout();
			break;

		case WM_HSCROLL:
			if (lParam == 0)
				OnHScroll(uMsg, wParam, lParam);
			break;

		case WM_VSCROLL:
			if (lParam == 0)
				OnVScroll(uMsg, wParam, lParam);
			break;
	}
}

void inline CResizer::Initialize(HWND hParent, const RECT& rcMin, const RECT& rcMax)
	// Sets up the Resizer by specifying the parent window (usually a dialog),
	//  and the minimum and maximum allowed rectangle sizes.
	//
	// Note:hParent can either be a CWnd or a window handle (HWND)
{
	//assert(::IsWindow(hParent));

	m_hParent = hParent;
	::GetClientRect(hParent, &m_rcInit);

	m_rcMin = rcMin;
	m_rcMax = rcMax;

	m_vResizeData.clear();

	// Add scroll bar support to the parent window
	DWORD dwStyle = (DWORD)::GetClassLongPtr(hParent, GCL_STYLE);
	dwStyle |= WS_HSCROLL | WS_VSCROLL;
	::SetClassLongPtr(hParent, GCL_STYLE, dwStyle);
}

void inline CResizer::OnHScroll(UINT, WPARAM wParam, LPARAM)
{
	int xNewPos;

	switch (LOWORD(wParam))
	{
		case SB_PAGEUP: // User clicked the scroll bar shaft left of the scroll box.
			xNewPos = m_xScrollPos - 50;
			break;

		case SB_PAGEDOWN: // User clicked the scroll bar shaft right of the scroll box.
			xNewPos = m_xScrollPos + 50;
			break;

		case SB_LINEUP: // User clicked the left arrow.
			xNewPos = m_xScrollPos - 5;
			break;

		case SB_LINEDOWN: // User clicked the right arrow.
			xNewPos = m_xScrollPos + 5;
			break;

		case SB_THUMBPOSITION: // User dragged the scroll box.
			xNewPos = HIWORD(wParam);
			break;

		case SB_THUMBTRACK: // User dragging the scroll box.
			xNewPos = HIWORD(wParam);
			break;

		default:
			xNewPos = m_xScrollPos;
	}

	// Scroll the window.
	xNewPos = MAX(0, xNewPos);
	CRect rc;
	::GetClientRect(m_hParent, &rc);
	xNewPos = MIN(xNewPos, GetMinRect().Width() - rc.Width());
	int xDelta = xNewPos - m_xScrollPos;
	m_xScrollPos = xNewPos;
	::ScrollWindow(m_hParent, -xDelta, 0, NULL, NULL);

	// Reset the scroll bar.
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(si);
	si.fMask = SIF_POS;
	si.nPos = m_xScrollPos;
	::SetScrollInfo(m_hParent, SB_HORZ, &si, TRUE);
}

void inline CResizer::OnVScroll(UINT, WPARAM wParam, LPARAM)
{
	int yNewPos;

	switch (LOWORD(wParam))
	{
		case SB_PAGEUP: // User clicked the scroll bar shaft above the scroll box.
			yNewPos = m_yScrollPos - 50;
			break;

		case SB_PAGEDOWN: // User clicked the scroll bar shaft below the scroll box.
			yNewPos = m_yScrollPos + 50;
			break;

		case SB_LINEUP: // User clicked the top arrow.
			yNewPos = m_yScrollPos - 5;
			break;

		case SB_LINEDOWN: // User clicked the bottom arrow.
			yNewPos = m_yScrollPos + 5;
			break;

		case SB_THUMBPOSITION: // User dragged the scroll box.
			yNewPos = HIWORD(wParam);
			break;

		case SB_THUMBTRACK: // User dragging the scroll box.
			yNewPos = HIWORD(wParam);
			break;

		default:
			yNewPos = m_yScrollPos;
	}

	// Scroll the window.
	yNewPos = MAX(0, yNewPos);
	CRect rc;
	GetClientRect(m_hParent, &rc);
	yNewPos = MIN(yNewPos, GetMinRect().Height() - rc.Height());
	int yDelta = yNewPos - m_yScrollPos;
	m_yScrollPos = yNewPos;
	::ScrollWindow(m_hParent, 0, -yDelta, NULL, NULL);

	// Reset the scroll bar.
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(si);
	si.fMask = SIF_POS;
	si.nPos = m_yScrollPos;
	::SetScrollInfo(m_hParent, SB_VERT, &si, TRUE);
}

void inline CResizer::RecalcLayout()
	// Repositions the child windows. Call this function when handling
	// the WM_SIZE message in the parent window.
{
	if (m_rcInit.Width() <= 0 || m_rcInit.Height() <= 0)
		return;
	//assert(m_rcInit.Width() > 0 && m_rcInit.Height() > 0);
	//assert(::IsWindow(m_hParent));

	CRect rcCurrent;
	::GetClientRect(m_hParent, &rcCurrent);

	// Adjust the scrolling if required
	m_xScrollPos = MIN(m_xScrollPos, MAX(0, m_rcMin.Width() - rcCurrent.Width()));
	m_yScrollPos = MIN(m_yScrollPos, MAX(0, m_rcMin.Height() - rcCurrent.Height()));
	SCROLLINFO si;
	ZeroMemory(&si, sizeof(SCROLLINFO));
	si.cbSize = sizeof(si);
	si.fMask = SIF_RANGE | SIF_PAGE | SIF_POS;
	si.nMax = m_rcMin.Width();
	si.nPage = rcCurrent.Width();
	si.nPos = m_xScrollPos;
	::SetScrollInfo(m_hParent, SB_HORZ, &si, TRUE);
	si.nMax = m_rcMin.Height();
	si.nPage = rcCurrent.Height();
	si.nPos = m_yScrollPos;
	::SetScrollInfo(m_hParent, SB_VERT, &si, TRUE);

	// Note: calls to SetScrollInfo may have changed the client rect, so
	// we get it again.
	::GetClientRect(m_hParent, &rcCurrent);

	rcCurrent.right = MAX(rcCurrent.Width(), m_rcMin.Width());
	rcCurrent.bottom = MAX(rcCurrent.Height(), m_rcMin.Height());
	if (!m_rcMax.IsRectEmpty())
	{
		rcCurrent.right = MIN(rcCurrent.Width(), m_rcMax.Width());
		rcCurrent.bottom = MIN(rcCurrent.Height(), m_rcMax.Height());
	}

	// Declare an iterator to step through the vector
	std::vector<ResizeData>::iterator iter;

	// Allocates memory for a multiple-window- position structure. 
	HDWP hdwp = ::BeginDeferWindowPos((int)m_vResizeData.size());

	for (iter = m_vResizeData.begin(); iter != m_vResizeData.end(); ++iter)
	{
		int left = 0;
		int top = 0;
		int width = 0;
		int height = 0;

		// Calculate the new size and position of the child window
		switch ((*iter).corner)
		{
			case topleft:
				width = (*iter).bFixedWidth ? (*iter).rcInit.Width() : (*iter).rcInit.Width() - m_rcInit.Width() + rcCurrent.Width();
				height = (*iter).bFixedHeight ? (*iter).rcInit.Height() : (*iter).rcInit.Height() - m_rcInit.Height() + rcCurrent.Height();
				left = (*iter).rcInit.left;
				top = (*iter).rcInit.top;
				break;
			case topright:
				width = (*iter).bFixedWidth ? (*iter).rcInit.Width() : (*iter).rcInit.Width() - m_rcInit.Width() + rcCurrent.Width();
				height = (*iter).bFixedHeight ? (*iter).rcInit.Height() : (*iter).rcInit.Height() - m_rcInit.Height() + rcCurrent.Height();
				left = (*iter).rcInit.right - width - m_rcInit.Width() + rcCurrent.Width();
				top = (*iter).rcInit.top;
				break;
			case bottomleft:
				width = (*iter).bFixedWidth ? (*iter).rcInit.Width() : (*iter).rcInit.Width() - m_rcInit.Width() + rcCurrent.Width();
				height = (*iter).bFixedHeight ? (*iter).rcInit.Height() : (*iter).rcInit.Height() - m_rcInit.Height() + rcCurrent.Height();
				left = (*iter).rcInit.left;
				top = (*iter).rcInit.bottom - height - m_rcInit.Height() + rcCurrent.Height();
				break;
			case bottomright:
				width = (*iter).bFixedWidth ? (*iter).rcInit.Width() : (*iter).rcInit.Width() - m_rcInit.Width() + rcCurrent.Width();
				height = (*iter).bFixedHeight ? (*iter).rcInit.Height() : (*iter).rcInit.Height() - m_rcInit.Height() + rcCurrent.Height();
				left = (*iter).rcInit.right - width - m_rcInit.Width() + rcCurrent.Width();
				top = (*iter).rcInit.bottom - height - m_rcInit.Height() + rcCurrent.Height();
				break;
		}

		// Determine the position of the child window.
		CRect rc(left - m_xScrollPos, top - m_yScrollPos, left + width - m_xScrollPos, top + height - m_yScrollPos);
		if (rc != (*iter).rcOld)
		{
			// Note: The tab order of the dialog's controls is determined by the order 
			//       they are specified in the resource script (resource.rc).

			// Store the window's new position. Repositioning happens later.
			hdwp = ::DeferWindowPos(hdwp, (*iter).hWnd, NULL, rc.left, rc.top, rc.Width(), rc.Height(), SWP_NOZORDER | SWP_NOCOPYBITS);

			(*iter).rcOld = rc;
		}

	}

	// Reposition all the child windows simultaneously.
	::EndDeferWindowPos(hdwp);
}



#endif

