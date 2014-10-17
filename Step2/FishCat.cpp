/**
* \file FishCat.cpp
*
* \author Matheus Araujo
*/

#include "stdafx.h"
#include <string>
#include "FishCat.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishCatImageName(L"images/catfish.png");

/// Max speed
/// Speed in pixels per second
const int MaxSpeedX = 100;
/// Min speed
/// Speed in pixels per second
const int MinSpeedX = 50;

/** Constructor
* \param aquarium The aquarium this is a member of
* \returns XML node
*/
CFishCat::CFishCat(CAquarium *aquarium) : CFish(aquarium,FishCatImageName)
{
	mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	/// Days since had sex
	mDaysSinceSex = 0;
	/// is Pregnant
	mPregnant = false;
	/// Days since had sex
	mPregnantDay = 0;
	///Days without food
	mFood = 10;
	///Days since food
	mDaysSinceFed = 0;
	/// Fish's worth
	mMultiplier = 6;
}

/**
* \brief Destructor
*/
CFishCat::~CFishCat()
{
}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CFishCat::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"cat");
	return itemNode;
}
