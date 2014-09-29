/**
* \file FishAngel.cpp
*
* \author Matheus Araujo
*/

#include "stdafx.h"
#include <string>
#include "FishAngel.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishAngelImageName(L"images/angelfish.png");
/// Max speed
/// Speed in pixels per second
const int MaxSpeedX = 25;
/// Min speed
/// Speed in pixels per second
const int MinSpeedX = 10;

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishAngel::CFishAngel(CAquarium *aquarium) : CFish(aquarium, FishAngelImageName)
{
	mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
}

/**
* \brief Destructor
*/
CFishAngel::~CFishAngel()
{
}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"angel");
	return itemNode;
}
