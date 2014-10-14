/**
* \file ChildView.h
*
* \author Matheus Araujo
*
* \brief Class that implements the child window our program draws in.
*
* The window is a child of the main frame, which holds this
* window, the menu bar, and the status bar.
*/

#pragma once
#include "Aquarium.h"


// CChildView window
/** \brief The child window our program draws in. */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:
	

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()

private:
	/// An object that describes our aquarium
	CAquarium  mAquarium;

	/// Any item we are currently dragging
	std::shared_ptr<CItem> mGrabbedItem;

	/// True until the first time we draw
	bool mFirstDraw = true;

	long long mLastTime;    ///< Last time we read the timer
	double mTimeFreq;       ///< Rate the timer updates
	std::unique_ptr<Gdiplus::Bitmap> mScrollingHandEnable;  ///< Scrolling Hand Enable Image
	std::unique_ptr<Gdiplus::Bitmap> mScrollingHandDisable;  ///< Scrolling Hand Disable Image

public:
	afx_msg void OnAddfishBetafish();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnAddfishAngelfish();
	afx_msg void OnAddfishCatfish();
	afx_msg void ToogleTrashcan();
	afx_msg void OnFileSaveas();
	afx_msg void OnFileOpen();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCareFeed();
	afx_msg void OnCareClean();
	afx_msg void OnAdddecorTreasurechest();
	afx_msg void OnAdddecorSpartytreasurechest();
};

