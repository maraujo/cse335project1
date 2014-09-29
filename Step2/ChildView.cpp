/**
* \file ChildView.cpp
*
* \author Matheus Araujo
*/

#include "stdafx.h"
#include "Step2.h"
#include "FishBeta.h"
#include "FishAngel.h"
#include "FishCat.h"
#include "DecorTreasure.h"
#include "ChildView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

using namespace Gdiplus;
using namespace std;

/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Initial fish X location
const int InitialX = 200;

/// Initial fish Y location
const int InitialY = 200;


// CChildView
/** \brief Constructor */
CChildView::CChildView()
{
	srand((unsigned int)time(nullptr));
}

/** \brief Destrructor */
CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_ADDFISH_BETAFISH, &CChildView::OnAddfishBetafish)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_ADDFISH_ANGELFISH, &CChildView::OnAddfishAngelfish)
	ON_COMMAND(ID_ADDFISH_CATFISH, &CChildView::OnAddfishCatfish)
	ON_COMMAND(ID_FILE_TRASHCAN, &CChildView::ToogleTrashcan)
	ON_COMMAND(ID_ADDFISH_TRESURE, &CChildView::OnAddTresure)
	ON_COMMAND(ID_FILE_SAVEAS, &CChildView::OnFileSaveas)
	ON_COMMAND(ID_FILE_OPEN32777, &CChildView::OnFileOpen)
	ON_WM_TIMER()
END_MESSAGE_MAP()



// CChildView message handlers
/** \brief This function is called before the window is created.
* \param cs A structure with the window creation parameters
* \returns TRUE
*/
BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}
/** \brief This function is called to draw in the window.
*
* This function is called in response to a drawing message
* whenever we need to redraw the window on the screen.
* It is responsible for painting the window.
*/
void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting

	// Get the size of the window
	CRect rect;
	GetClientRect(&rect);

	// Create a memory buffer
	Bitmap memory(rect.Width(), rect.Height(), PixelFormat32bppARGB);

	// And a graphics context for that buffer
	Graphics graphics(&memory);
	graphics.Clear(Color(0, 0, 0));

	mAquarium.OnDraw(&graphics);

	Graphics graphicsReal(dc.m_hDC);
	graphicsReal.DrawImage(&memory, 0, 0, rect.Width(), rect.Height());

	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		* Initialize the elapsed time system
		*/
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	* Compute the elapsed time since the last draw
	*/
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	mAquarium.Update(elapsed);
}



/**
 * \brief Function to handle menu option of Beta Fish
 */
void CChildView::OnAddfishBetafish()
{
	// TODO: Add your command handler code here
	auto fish = make_shared<CFishBeta>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Invalidate();
}

/** \brief Called when there is a left mouse button press
* \param nFlags Flags associated with the mouse button press
* \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mGrabbedItem = mAquarium.HitTest(point.x, point.y);
	if (mGrabbedItem != nullptr)
	{
		mAquarium.sendItemBack(mGrabbedItem);
		// We have selected an item
		// Move it to the end of the list of items
		// you'll need code here to do that...
	}
}

/** \brief Called when the left mouse button is released
* \param nFlags Flags associated with the mouse button release
* \param point Where the button was pressed
*/
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	OnMouseMove(nFlags, point);
}

/** \brief Called when the mouse is moved
* \param nFlags Flags associated with the mouse movement
* \param point Where the button was pressed
*/
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// See if an item is currently being moved by the mouse
	if (mGrabbedItem != nullptr)
	{
		// If an item is being moved, we only continue to 
		// move it while the left button is down.
		if (nFlags & MK_LBUTTON)
		{
			mGrabbedItem->SetLocation(point.x, point.y);
		}
		else
		{
			// When the left button is released, we release the
			// item.
			mGrabbedItem = nullptr;
		}

		if (mAquarium.IsOverTrashcan(point.x, point.y)){
			mAquarium.DeleteItem(mGrabbedItem);
			mGrabbedItem = nullptr;
		}

		// Force the screen to redraw
		Invalidate();
	}
}

/**
* \brief Erase the background prior to drawing.
* \param pDC A device context to draw on
* \returns True it disable the background redraw.
*/
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	// This disabled the default background erase
	return TRUE;
}

/**
* \brief Function to handle menu option of Angel Fish
*/
void CChildView::OnAddfishAngelfish()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	auto fish = make_shared<CFishAngel>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Invalidate();
}

/**
* \brief Function to handle menu option of Cat Fish
*/
void CChildView::OnAddfishCatfish()
{
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	// TODO: Add your command handler code here
	auto fish = make_shared<CFishCat>(&mAquarium);
	fish->SetLocation(InitialX, InitialY);
	mAquarium.Add(fish);
	Invalidate();
}


/**
 * \brief Toggle the visibility of the trash can
 */
void CChildView::ToogleTrashcan()
{
	// TODO: Add your command handler code here
	if (mAquarium.GetTrashcanActive() == true){
		mAquarium.SetTrashcanActive(false);
		Invalidate();
	}
	else{
		mAquarium.SetTrashcanActive(true);
		Invalidate();
	}
}

/**
* \brief Add Tresure to aquarium
*/
 void CChildView::OnAddTresure()
 {
	 // TODO: Add your command handler code here
	 // TODO: Add your command handler code here
	 // TODO: Add your command handler code here
	 auto tresure = make_shared<CDecorTreasure>(&mAquarium);
	 tresure->SetLocation(InitialX, InitialY);
	 mAquarium.Add(tresure);
	 Invalidate();
 }

 /**
 * \brief Behaviour when hit Save As at Menu
 */
 void CChildView::OnFileSaveas()
 {
	 // TODO: Add your command handler code here
	 CFileDialog dlg(false,  // false = Save dialog box
		 L".aqua",           // Default file extension
		 nullptr,            // Default file name (none)
		 OFN_OVERWRITEPROMPT,      // Flags (none)
		 L"Aquarium Files (*.aqua)|*.aqua|All Files (*.*)|*.*||");    // Filter 
	 if (dlg.DoModal() != IDOK)
		 return;
	 wstring filename = dlg.GetPathName();
	 mAquarium.Save(filename);
 }

 /**
 * \brief Behavior when hit Open at Menu
 */
 void CChildView::OnFileOpen()
 {
	 // TODO: Add your command handler code here
	 CFileDialog dlg(true,  // true = Open dialog box
		 L".aqua",           // Default file extension
		 nullptr,            // Default file name (none)
		 0,    // Flags
		 L"Aquarium Files (*.aqua)|*.aqua|All Files (*.*)|*.*||");    // Filter
	 if (dlg.DoModal() != IDOK)
		 return;

	 wstring filename = dlg.GetPathName();

	 mAquarium.Load(filename);
	 Invalidate();
 }


 /**
 * \brief Handle timer events
 * \param nIDEvent The timer event ID
 */
 void CChildView::OnTimer(UINT_PTR nIDEvent)
 {
	 // TODO: Add your message handler code here and/or call default
	 Invalidate();
	 CWnd::OnTimer(nIDEvent);
 }
