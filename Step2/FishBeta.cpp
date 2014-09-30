/**
 * \file FishBeta.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include <string>
#include "FishBeta.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishBetaImageName(L"images/Beta.png");
/// Max speed
/// Speed in pixels per second
const int MaxSpeedX = 50;
/// Min speed
/// Speed in pixels per second
const int MinSpeedX = 25;

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium *aquarium) : CFish(aquarium,FishBetaImageName)
{
	mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	
	//Set gender 50% to be MALE or FEMALE
	if ((double)rand() > 0.5){
		mGender = MALE;
	}
	else{
		mGender = FEMALE;
	}
}

/**
* \brief Destructor
*/
CFishBeta::~CFishBeta()
{
}



/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");
	return itemNode;
}