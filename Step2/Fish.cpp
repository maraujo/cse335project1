/**
 * \file Fish.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include "Aquarium.h"
#include "Fish.h"

/// Maximum speed in the Y direction in
/// in pixels per second
const double MaxSpeedY = 25;

/// Maximum speed in the X direction in
/// in pixels per second
const double MaxSpeedX = 50;

/// Space between the screen to flip the fish
/// in pixels
const double flipOffset = 50;

/// Space between the screen to change Y direction
/// in pixels
const double heightOffset = 50;

/** Constructor
* \param aquarium The aquarium we are in
* \param filename Filename for the image we use
*/
CFish::CFish(CAquarium *aquarium, const std::wstring &filename) :
CItem(aquarium, filename)
{
	mSpeedX = ((double)rand() / RAND_MAX) * MaxSpeedX;
	
	if (((double)rand() / RAND_MAX) > 0.5){
		mSpeedY = ((double)rand() / RAND_MAX) * MaxSpeedY;
	}
	else{
		mSpeedY = -1*((double)rand() / RAND_MAX) * MaxSpeedY;
	}
	
}

CFish::~CFish()
{
}

/** \brief Handle updates in time of our fish
*
* This is called before we draw and allows us to
* move our fish. We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CFish::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);

	// X movement
	if (mSpeedX > 0 && GetX() + GetWidth()/2 + flipOffset >= GetAquarium()->GetWidth())
	{
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}
	else if (mSpeedX < 0 && GetX() - GetWidth()/2 - flipOffset <= 0){
		mSpeedX = -mSpeedX;
		SetMirror(mSpeedX < 0);
	}

	// Y movement
	if (mSpeedY > 0 && GetY() + GetHeight() / 2 + heightOffset >= GetAquarium()->GetHeight())
	{
		mSpeedY = -mSpeedY;
	}
	else if (mSpeedY < 0 && GetY() - GetHeight() / 2 - heightOffset <= 0){
		mSpeedY = -mSpeedY;
	}

}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CItem::XmlSave(node);
	itemNode->SetAttribute(L"speedX", mSpeedX);
	itemNode->SetAttribute(L"speedY", mSpeedY);
	return itemNode;
}


/**
* brief Load the attributes for an fisg node.
*
* This is the class version that loads the attributes
* common to all fishes. Override this to load custom attributes
* for specific fish.
*
* \param node The Xml node we are loading the fish from
*/
void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	CItem::XmlLoad(node);
	mSpeedX = node->GetAttributeDoubleValue(L"speedX", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedY", 0);
	SetMirror(mSpeedX < 0);
}