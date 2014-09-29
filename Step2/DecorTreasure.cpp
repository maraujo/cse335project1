/**
 * \file DecorTreasure.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include <string>
#include "Item.h"
#include "DecorTreasure.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring TresureImageName(L"images/treasure-chest.png");

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CDecorTreasure::CDecorTreasure(CAquarium *aquarium) : CItem(aquarium, TresureImageName)
{
}


CDecorTreasure::~CDecorTreasure()
{
}


/**
* \brief Draw our fish
* \param graphics The graphics context to draw on
*/
void CDecorTreasure::Draw(Gdiplus::Graphics *graphics)
{
	double wid = mItemImage->GetWidth();
	double hit = mItemImage->GetHeight();
	graphics->DrawImage(mItemImage.get(),
		float(GetX() - wid / 2), float(GetY() - hit / 2),
		mItemImage->GetWidth(), mItemImage->GetHeight());
}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CDecorTreasure::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"type", L"treasure-chest");
	return itemNode;
}