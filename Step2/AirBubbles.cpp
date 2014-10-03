/**
* \file Bubbles.cpp
*
* \author Zachary Walters
*/

#include "stdafx.h"
#include "AirBubbles.h"
#include "Aquarium.h"
#include "DecorSpartyTreasure.h"
#include <string>

using namespace std;

/// Bubbles filename
wstring AirBubblesImageName(L"images/airbubbles.png");

/// Maximum speed in the X direction in
/// pixels per second
const double MaxSpeedX = 25;

/// Maximum speed in the Y direction in
/// pixels per second
const double MaxSpeedY = 100;

/// Minimum speed in the Y direction in
/// pixels per second
const double MinSpeedY = 50;

/** Constructor
* \param aquarium The aquarium we are in
*/
CAirBubbles::CAirBubbles(CAquarium *aquarium) : CItem(aquarium, AirBubblesImageName)
{
	mSpeedX = ((double)rand() / RAND_MAX)*MaxSpeedX;
	mSpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
	mSpeedY = -mSpeedY;
}

/**
* \brief Destructor
*/
CAirBubbles::~CAirBubbles()
{
}

/** \brief Handle updates in time of our bubbles
*
* This is called before we draw and allows us to
* move our bubbles. We add our speed times the amount
* of time that has elapsed.
* \param elapsed Time elapsed since the class call
*/
void CAirBubbles::Update(double elapsed)
{
	SetLocation(GetX() + mSpeedX * elapsed,
		GetY() + mSpeedY * elapsed);
}

/** \brief Save this bubbles to an XML node
* \param node The node we are going to be a child of
*/
std::shared_ptr<xmlnode::CXmlNode> CAirBubbles::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	//auto itemNode = node->AddChild(L"item");

	auto itemNode = CItem::XmlSave(node);

	itemNode->SetAttribute(L"type", L"airbubbles");
	itemNode->SetAttribute(L"speedx", mSpeedX);
	itemNode->SetAttribute(L"speedy", mSpeedY);

	return itemNode;
}

/**
* brief Load the attributes for a bubbles node.
*
* This is the  base class version that loads the attributes
* common to all bubbles. Override this to load custom attributes
* for specific bubbles.
*
* \param node The Xml node we are loading the  from
*/
void CAirBubbles::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	mSpeedX = node->GetAttributeDoubleValue(L"speedx", 0);
	mSpeedY = node->GetAttributeDoubleValue(L"speedy", 0);

	CItem::XmlLoad(node);
}