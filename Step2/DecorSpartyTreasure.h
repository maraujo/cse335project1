/**
* \file DecorSpartyTreasure.h
*
* \author Zachary Walters
*
* \brief Class the implements a Sparty treasure chest
*/

#pragma once

#include <memory>

#include "Item.h"


class CDecorSpartyTreasure :
	public CItem
{
public:
	CDecorSpartyTreasure(CAquarium *aquarium);

	/// \brief Default constructor (disabled)
	CDecorSpartyTreasure() = delete;

	/// \brief Copy constructor (disabled)
	CDecorSpartyTreasure(const CDecorSpartyTreasure &) = delete;

	~CDecorSpartyTreasure();

	void Update(double elapsed);

	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	bool CheckFood() { return 1; }
	void Hunger() {};

private:
	/// The current image of the chest
	int mCurrentImage = 0;

	/// Int to act like bool stating if chest should be opening or closing
	int mOpening = 1;

	/// Int to act like bool stating if image changing should pause
	int mPause = 1;

	/// Keeps track of time
	double mTime = 0;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item
};