/**
* \file AirBubbles.h
*
* \author Zachary Walters
*
* \brief Base class for any bubbles in our aquarium
*/

#pragma once
#include "Item.h"

/** \brief Base class for a bubbles
* This applies to all the bubbles of our aquarium
*/
class CAirBubbles : public CItem
{
public:
	/// \brief Default constructor (disabled)
	CAirBubbles() = delete;

	/// \brief Copy constructor (disabled)
	CAirBubbles(const CAirBubbles &) = delete;

	virtual ~CAirBubbles();

	void Update(double elapsed);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	CAirBubbles(CAquarium *aquarium);

	bool CheckFood() { return 1; }
	void Hunger() {};

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
};
