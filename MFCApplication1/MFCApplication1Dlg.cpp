
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCApplication1Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//GradientFillFn(&dc, 10, 10, 210, 210, RGB(0, 128, 255), RGB(0, 255, 255));
		GradientFillFn_3D(&dc, 10, 10, 210, 210, RGB(0, 128, 255), RGB(0, 255, 255));



		/*
		TRIVERTEX data[2];	// 시작좌표 끝좌표 넣는곳
		GRADIENT_RECT r;

		data[0].x = 10;		// left
		data[0].y = 10;		// top

		data[0].Red = 0;
		data[0].Green= 128 << 8;
		data[0].Blue= 255<<8;
		data[0].Alpha = 0;

		data[1].x = 210;	// right
		data[1].y = 210;	// bottom

		data[1].Red = 0;
		data[1].Green = 255 << 8;
		data[1].Blue = 255 << 8;
		data[1].Alpha = 0;

		r.UpperLeft = 0;
		r.LowerRight = 1;

		dc.GradientFill(data, 2, &r, 1, GRADIENT_FILL_RECT_V);
		*/

		// CDialogEx::OnPaint();
	}
}

void CMFCApplication1Dlg::GradientFillFn(CDC* ap_dc, int a_sx, int a_sy, int a_ex, int a_ey,
	COLORREF a_start_color, COLORREF a_end_color) 
{
	TRIVERTEX data[2];	// 시작좌표 끝좌표 넣는곳
	GRADIENT_RECT r;

	data[0].x = a_sx;		// left
	data[0].y = a_sy;		// top

	data[0].Red = GetRValue(a_start_color);
	data[0].Green = GetGValue(a_start_color) << 8;
	data[0].Blue = GetBValue(a_start_color) << 8;
	data[0].Alpha = 0;

	data[1].x = a_ex;	// right
	data[1].y = a_ey;	// bottom

	data[1].Red = GetRValue(a_end_color);
	data[1].Green = GetGValue(a_end_color) << 8;
	data[1].Blue = GetBValue(a_end_color) << 8;
	data[1].Alpha = 0;

	r.UpperLeft = 0;
	r.LowerRight = 1;

	ap_dc->GradientFill(data, 2, &r, 1, GRADIENT_FILL_RECT_V);
}

void CMFCApplication1Dlg::GradientFillFn_3D(CDC* ap_dc, int a_sx, int a_sy, int a_ex, int a_ey,
	COLORREF a_start_color, COLORREF a_end_color)
{
	TRIVERTEX data[2];	// 시작좌표 끝좌표 넣는곳
	GRADIENT_RECT r;

	data[0].x = a_sx;		// left
	data[0].y = a_sy;		// top

	data[0].Red = GetRValue(a_start_color);
	data[0].Green = GetGValue(a_start_color) << 8;
	data[0].Blue = GetBValue(a_start_color) << 8;
	data[0].Alpha = 0;

	data[1].x = a_ex;	// right
	data[1].y = a_sy + (a_ey - a_sy) / 2;	// bottom

	data[1].Red = GetRValue(a_end_color);
	data[1].Green = GetGValue(a_end_color) << 8;
	data[1].Blue = GetBValue(a_end_color) << 8;
	data[1].Alpha = 0;

	r.UpperLeft = 0;
	r.LowerRight = 1;

	ap_dc->GradientFill(data, 2, &r, 1, GRADIENT_FILL_RECT_V);

	data[0].x = a_sx;		// left
	data[0].y = a_sy + (a_ey - a_sy) / 2;		// top

	data[0].Red = GetRValue(a_end_color);
	data[0].Green = GetGValue(a_end_color) << 8;
	data[0].Blue = GetBValue(a_end_color) << 8;
	data[0].Alpha = 0;

	data[1].x = a_ex;	// right
	data[1].y = a_ey;	// bottom

	data[1].Red = GetRValue(a_start_color);
	data[1].Green = GetGValue(a_start_color) << 8;
	data[1].Blue = GetBValue(a_start_color) << 8;
	data[1].Alpha = 0;

	ap_dc->GradientFill(data, 2, &r, 1, GRADIENT_FILL_RECT_V);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

