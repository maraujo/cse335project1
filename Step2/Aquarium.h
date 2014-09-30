/**
* \file ChildView.h
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

	void OnDraw(Gdiplus::Graphics *graphics);
	void CAquarium::Add(std::shared_ptr<CItem> item);
	std::shared_ptr<CItem> CAquarium::HitTest(int x, int y);
	void sendItemBack(std::shared_ptr<CItem> item);
	bool CAquarium::IsOverTrashcan(int x, int y);
	void CAquarium::SetTrashcanActive(bool status);
	bool CAquarium::GetTrashcanActive();
	void CAquarium::DeleteItem(std::shared_ptr<CItem> item);
	void CAquarium::Save(const std::wstring &filename);
	void CAquarium::Load(const std::wstring &filename);
	void CAquarium::Clear();
	int CAquarium::NumItems();
	void CAquarium::Update(double elapsed);

	/// \brief Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// \brief Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

	void Accept(CItemVisitor *visitor);

private:
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use
	std::unique_ptr<Gdiplus::Bitmap> mTrashcan;  ///< Trash can image
	bool mTrashcanActive; ///< Trashcan Status
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
	void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode> &node);
	
	
};


