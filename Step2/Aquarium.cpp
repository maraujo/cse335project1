/**
* \file ChildView.cpp
*
* \author Matheus Araujo
*/
#include "stdafx.h"
#include <algorithm>
#include "Aquarium.h"
#include "resource.h"
#include "FishBeta.h"
#include "FishAngel.h"
#include "FishCat.h"
#include "Breeding.h"
#include "DecorTreasure.h"
#include "XmlNode.h"
#include "DecorSpartyTreasure.h"
#include "AirBubbles.h"

#include <algorithm>

using namespace std;
using namespace Gdiplus;
using namespace xmlnode;

/// Defines TrashCanWidth as a constant
const int TrashCanWidth = 51;
/// Defines TrashCanHeight as a constant
const int TrashCanHeight = 70;
/// FrameCounter
int frameCount = 0;

/**
* \brief Constructor
*/
CAquarium::CAquarium()
{
	mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/backgroundW.png"));
	
	if (mBackground->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/backgroundW.png");
	}

	mTrashcan = unique_ptr<Gdiplus::Bitmap>(Bitmap::FromFile(L"images/trashcan.png"));
	if (mTrashcan->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/trashcan.png");
	}
}


/**
* \brief Destructor
*/
CAquarium::~CAquarium()
{
}

/** \brief Draw the aquarium
* \param graphics The GDI+ graphics context to draw on
*/
void CAquarium::OnDraw(Gdiplus::Graphics *graphics)
{
	graphics->DrawImage(mBackground.get(), 0, 0,
		mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the Sea!", -1, &font, PointF(2, 2), &green);

	
	for (auto item : mItems)
	{
		item->Draw(graphics);
	}


	if (mTrashcanActive)
	{
		graphics->DrawImage(mTrashcan.get(), 0, 0, mTrashcan->GetWidth(), mTrashcan->GetHeight());
	}
}

/** \brief Add an item to the aquarium
* \param item New item to add
*/
void CAquarium::Add(std::shared_ptr<CItem> item)
{
	mItems.push_back(item);
}

/** \brief Test an x,y click location to see if it clicked
* on some item in the aquarium.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
	for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}


/**
 * \brief Send item to the back of vector after move
 * \param item item to be sent
 */
void CAquarium::sendItemBack(std::shared_ptr<CItem> item){
	auto loc = find(begin(mItems), end(mItems), item);
	if (loc != end(mItems))
	{
		mItems.erase(loc);
		mItems.push_back(item);
	}
}


/**
 * \brief Check if mouse over trashcan
 * \param x Mouse position x
 * \param y Mouse position y
 * \returns True if mouse is over trashcan
 */
bool CAquarium::IsOverTrashcan(int x, int y)
{
	if (!mTrashcanActive)
	{
		return false;
	}

	return x < (int)mTrashcan->GetWidth() && y < (int)mTrashcan->GetHeight();
}

/**
 * \brief Set status to member mTrashcanActive
 * \param status to be set for mTrashcanActive
 */
void CAquarium::SetTrashcanActive(bool status){
	mTrashcanActive = status;
}

/**
* \brief Get status to member mTrashcanActive
*/
bool CAquarium::GetTrashcanActive(){
	return mTrashcanActive;
}

/**
 * \brief Delete Item from collection Items
 * \param item to be deleted
 */
void CAquarium::DeleteItem(std::shared_ptr<CItem> item){
	auto loc = find(begin(mItems), end(mItems), item);
	mItems.erase(loc);
}

/** \brief Save the aquarium as a .aqua XML file.
*
* Open an XML file and stream the aquarium data to it.
*
* \param filename The filename of the file to save the aquarium to
*/
void CAquarium::Save(const std::wstring &filename)
{
	//
	// Create an XML document
	//
	auto root = CXmlNode::CreateDocument(L"aqua");

	// Iterate over all items and save them
	for (auto item : mItems)
	{
		item->XmlSave(root);
	}

	try
	{
		root->Save(filename);
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}
}

/** \brief Load the aquarium from a .aqua XML file.
*
* Opens the XML file and reads the nodes, creating items as appropriate.
*
* \param filename The filename of the file to load the aquarium from.
*/
void CAquarium::Load(const std::wstring &filename)
{
	// We surround with a try/catch to handle errors
	try
	{
		// Open the document to read
		shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

		// Once we know it is open, clear the existing data
		Clear();

		//
		// Traverse the children of the root
		// node of the XML document in memory!!!!
		//
		for (auto node : root->GetChildren())
		{
			if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
			{
				XmlItem(node);
			}
		}
	}
	catch (CXmlNode::Exception ex)
	{
		AfxMessageBox(ex.Message().c_str());
	}

}

/**
* \brief Clear the aquarium data.
*
* Deletes all known items in the aquarium.
*/
void CAquarium::Clear()
{

	while (mItems.size() != 0)
	{
		mItems.pop_back();
	}
}

/**
* \brief Get number of item in the aquarium;
*
* Counts number of item in the aquarium;
* \returns integer number of items
*/
int CAquarium::NumItems(){
	int nItems = 0;
	for (auto item : mItems)
	{
		nItems++;
	}
	return nItems;
}

/**
* \brief Handle an item node.
* \param node Pointer to XML node we are handling
*/
void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	// A pointer for the item we are loading
	shared_ptr<CItem> item;

	// We have an item. What type?
	wstring type = node->GetAttributeValue(L"type", L"");
	if (type == L"beta")
	{
		item = make_shared<CFishBeta>(this);
	}
	else if (type == L"treasure-chest")
	{
		item = make_shared<CDecorTreasure>(this);
	}
	else if (type == L"cat")
	{
		item = make_shared<CFishCat>(this);
	}
	else if (type == L"angel")
	{
		item = make_shared<CFishAngel>(this);
	}
	else if (type == L"sparty-treasure-chest")
	{
		item = make_shared<CDecorSpartyTreasure>(this);
	}
	else if (type == L"air-bubbles")
	{
		item = make_shared<CAirBubbles>(this);
	}

	if (item != nullptr)
	{
		item->XmlLoad(node);
		Add(item);
	}
}

/** \brief Handle updates for animation
* \param elapsed The time since the last update
*/
void CAquarium::Update(double elapsed)
{

	/// Frame Conte
	frameCount++;

	
	if (frameCount % 33 == 0){
		CBreeding breedVisitor;
		Accept(&breedVisitor);

		breedVisitor.CheckAngelsHadSex();
		breedVisitor.CheckCatsHadSex();
		breedVisitor.passDayFishes();
		CheckFishFood();
		DirtyTank();
	}

	for (auto item : mItems)
	{
		item->Update(elapsed);
		if (item->GetY() < 0)
		{
			mItemsDelete.push_back(item);
		}
	}
	
	for (auto item : mItemsAdd)
	{
		mItems.push_back(item);
	}

	for (auto item : mItemsDelete)
	{
		DeleteItem(item);
	}

	mItemsAdd.clear();
	mItemsDelete.clear();
}

/** \brief Accept a visitor for the collection
* \param visitor The visitor for the collection
*/
void CAquarium::Accept(CItemVisitor *visitor)
{
	for (auto item : mItems)
	{
		item->Accept(visitor);
	}
}


/**
 * \brief Check for food level and kills fish if below the level
 */
void CAquarium::CheckFishFood()
{
	std::vector<std::shared_ptr<CItem>> ItemsToDelete;
	for (auto item : mItems)
	{
		if (item->CheckFood() == false)
		{
			ItemsToDelete.push_back(item);
		}
		else
		{
			item->Hunger();
		}
	}
	for (auto DelItem : ItemsToDelete)
	{
		DeleteItem(DelItem);
	}
}

/**
 * \brief States if mItems is empty or not
 *
 * \returns Boolean stating whether mItems is empty or not
 */
bool CAquarium::IsEmpty()
{
	bool result;
	result = mItems.empty();

	return result;
}

/** \brief Add an item to vector to be added to aquarium
 * \param item New item to add
 */
void CAquarium::AddBubbles(std::shared_ptr<CItem> item)
{
	mItemsAdd.push_back(item);
}

/** \brief Add an item to vector to be deleted from aquarium
 * \param item New item to delete
 */
void CAquarium::DeleteBubbles(std::shared_ptr<CItem> item)
{
	mItemsDelete.push_back(item);
}


void CAquarium::DirtyTank()
{
	if (mTankCleanliness <= 40 && mTankCleanliness >= 31)
	{
		mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/backgroundW.png"));

		if (mBackground->GetLastStatus() != Ok)
		{
			AfxMessageBox(L"Failed to open images/backgroundW.png");
		}
	}
	if (mTankCleanliness <= 30 && mTankCleanliness >= 21)
	{
		mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/backgroundW1.png"));

		if (mBackground->GetLastStatus() != Ok)
		{
			AfxMessageBox(L"Failed to open images/backgroundW1.png");
		}
	}

	if (mTankCleanliness <= 20 && mTankCleanliness >= 11)
	{
		mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/backgroundW2.png"));

		if (mBackground->GetLastStatus() != Ok)
		{
			AfxMessageBox(L"Failed to open images/backgroundW2.png");
		}
	}
	if (mTankCleanliness <= 10)
	{
		mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/backgroundW3.png"));

		if (mBackground->GetLastStatus() != Ok)
		{
			AfxMessageBox(L"Failed to open images/backgroundW3.png");
		}
		mTankCleanliness = 1;
	}

	mTankCleanliness--;
}