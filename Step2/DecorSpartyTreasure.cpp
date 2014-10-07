/**
* \file DecorSpartyTreasure.cpp
*
* \author Zachary Walters
*/

#include "stdafx.h"
#include <string>
#include "DecorSpartyTreasure.h"
#include "Aquarium.h"
#include "AirBubbles.h"

using namespace std;
using namespace Gdiplus;

/// Sparty treasure chest filename
wstring DecorSpartyTreasureImageName(L"images/chest1.png");

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CDecorSpartyTreasure::CDecorSpartyTreasure(CAquarium *aquarium) : CItem(aquarium, DecorSpartyTreasureImageName)
{
}

/**
* \brief Destructor
*/
CDecorSpartyTreasure::~CDecorSpartyTreasure()
{
}

/** \brief Handle updates in time of our Sparty treasure chest
*
* This is called before we draw and allows us to
* open/close our chest. We change the image of
* the chest if enough time has elapsed
* \param elapsed Time elapsed since the class call
*/
void CDecorSpartyTreasure::Update(double elapsed)
{
	mTime += elapsed;
	static wstring files[] = {
		L"chest1.png",
		L"chest2.png",
		L"chest3.png",
		L"chest4.png",
		L"chest5.png",
	};
	SetImage(files[mCurrentImage]);

	if (mTime > .2 && mCurrentImage != 4 && mOpening == 1 && mPause == 0)
	{
		mCurrentImage++;
		SetImage(files[mCurrentImage]);
		mTime = 0;

		if (mCurrentImage == 4)
		{
			mPause = 1;
			mOpening = 0;


			shared_ptr<CAirBubbles> bubbles;
			bubbles = make_shared<CAirBubbles>(CItem::GetAquarium());

			mX = CItem::GetX();
			mY = CItem::GetY();
			bubbles->SetLocation(mX, mY);
			CItem::GetAquarium()->AddBubbles(bubbles);
		}
	}
	else if (mTime > .2 && mCurrentImage != 0 && mOpening == 0 && mPause == 0)
	{
		mCurrentImage--;
		SetImage(files[mCurrentImage]);
		mTime = 0;

		if (mCurrentImage == 0)
		{
			mPause = 1;
			mOpening = 1;
		}
	}
	else if (mTime > 7 && mOpening == 1 && mPause == 1)
	{
		mPause = 0;
		mTime = 0;
	}
	else if (mTime > 7 && mOpening == 0 && mPause == 1)
	{
		mPause = 0;
		mTime = 0;
	}
}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns itemNode the itme saved to XML
*/
std::shared_ptr<xmlnode::CXmlNode> CDecorSpartyTreasure::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"sparty-treasure-chest");
	itemNode->SetAttribute(L"currentImage", mCurrentImage);
	itemNode->SetAttribute(L"time", mTime);
	itemNode->SetAttribute(L"opening", mOpening);
	itemNode->SetAttribute(L"pause", mPause);

	return itemNode;
}

/**
* brief Load the attributes for a sparty treasure chest node.
*
* This is the  base class version that loads the attributes
* common to all sparty treasure chests. Override this to load custom attributes
* for specific chest.
*
* \param node The Xml node we are loading the fish from
*/
void CDecorSpartyTreasure::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	mCurrentImage = node->GetAttributeIntValue(L"currentImage", 0);
	mTime = node->GetAttributeDoubleValue(L"time", 0);
	mOpening = node->GetAttributeIntValue(L"opening", 0);
	mPause = node->GetAttributeIntValue(L"pause", 0);

	CItem::XmlLoad(node);
}