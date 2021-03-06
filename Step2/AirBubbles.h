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

	/// \brief check function \returns false
	bool CheckFood() { return 1; }
	/// \brief check if hungry (does nothing)
	void Hunger() {};

	/** \brief States that item clicked on is a bubbles object */
	bool IsBubbles() { return true; }

private:
	/// Air Bubble in the X direction
	double mSpeedX;

	/// Air Bubble speed in the Y direction
	double mSpeedY;
};
