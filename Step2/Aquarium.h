/**
* \file Aquarium.h
*
* \author Matheus Araujo
*
* \brief Class that implements the Aquarium configutation
*
* This class holds the elements necessary to create the aquarium.
* 
*/
#pragma once
#include <memory>
#include <vector>
#include "XmlNode.h"


class CItem;
class CItemVisitor;

/**
* \brief Represents an aquarium
*/
class CAquarium
{
public:
	CAquarium();
	virtual ~CAquarium();

	/// Member functions of CAquarium
	void OnDraw(Gdiplus::Graphics *graphics);
	void CAquarium::Add(std::shared_ptr<CItem> item);
	std::shared_ptr<CItem> CAquarium::HitTest(int x, int y);
	bool CAquarium::IsOverScrollingHand(int x, int y, CRect *window);
	// \brief Set Scrolling status
	void CAquarium::SetScrollingActive(bool status){ mScrollingActive = status; }
	/// \brief Get Scrolling status
	bool CAquarium::GetScrollingActive(){ return mScrollingActive; }
	void UpdateWindowPosition(CRect *window);
	/// \brief Get the bool value of mMoving
	/// \returns if background is being moving
	bool IsMoving(){ return mMoving; }
	/// \brief Set the bool value of mMoving
	void SetMoving(bool moving){ mMoving = moving; }
	void MoveBackground(CPoint *point, CRect *rect);
	/// \brief Get the int value of  mBgOffsetX
	/// \returns he int value of  mBgOffsetX
	int GetBgX(){ return mBgOffsetX; }
	/// \brief Get the int value of  mBgOffsetY
	/// \returns he int value of  mBgOffsetY
	int GetBgY(){ return mBgOffsetY; }

	void SetStartPoint(CPoint *p);
	void sendItemBack(std::shared_ptr<CItem> item);
	bool CAquarium::IsOverTrashcan(int x, int y);
	void CAquarium::SetTrashcanActive(bool status);
	bool CAquarium::GetTrashcanActive();
	void CAquarium::DeleteItem(std::shared_ptr<CItem> item);
	void CAquarium::Save(const std::wstring &filename);
	void CAquarium::Load(const std::wstring &filename);
	void CAquarium::Clear();
	int CAquarium::NumItems();
	void XmlItem(const std::shared_ptr<xmlnode::CXmlNode> &node);
	void CAquarium::Update(double elapsed);
	bool IsEmpty();
	void AddBubbles(std::shared_ptr<CItem> item);
	void DeleteBubbles(std::shared_ptr<CItem> item);

	/// \brief Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// \brief Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }
	/// \brief accepts visitor function
	void Accept(CItemVisitor *visitor);
	/// \brief checks food of fish in aquarium
	void CheckFishFood();
	/// \brief slowly starts to add to dirtyness
	void DirtyTank();
	/// \brief sets the cleanliness of the tank back to max
	void SetTankCleanliness(int Max){ mTankCleanliness = Max; }
	/// \brief gets the max cleanliness of the tank possible
	int GetTankMaxCleanliness(){ return mTankMaxCleanliness; }

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use
	std::unique_ptr<Gdiplus::Bitmap> mTrashcan;  ///< Trash can image
	bool mTrashcanActive = false; ///< Trashcan Status
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
	
	/// Bubbles to be added
	std::vector<std::shared_ptr<CItem> > mItemsAdd;

	/// Bubbles to be deleted
	std::vector<std::shared_ptr<CItem> > mItemsDelete;

	///Max tank cleanliness
	int mTankMaxCleanliness = 40;

	///Cleanliness of tank in days left.
	int mTankCleanliness = 40;
	std::unique_ptr<Gdiplus::Bitmap> mScrollingHandDisable;  ///< Scrolling Hand Disable Image
	std::unique_ptr<Gdiplus::Bitmap> mScrollingHandEnable;  ///< Scrolling Hand Enable Image
	bool mScrollingActive; ///< Scrolling Active
	/// Window position in pixels
	CRect *mWindowPosition;
	/// Background offset in axis X
	int mBgOffsetX;
	/// Background offset in axis Y
	int mBgOffsetY;
	/// Check if the user is moving the background
	bool mMoving;
	/// Reference point when start to movie
	CPoint mStartPoint;

};


