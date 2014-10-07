/**
* \file FishAngel.h
*
* \author Matheus Araujo
*
* \brief Class that describes the Angel Fish behaviour
*/

#pragma once
#include <memory>
#include "Fish.h"

/**
* \brief Implements a Angel fish
*/
class CFishAngel : public CFish
{
public:
	CFishAngel(CAquarium *aquarium);

	/// \brief Default constructor (disabled)
	CFishAngel() = delete;

	/// \brief Copy constructor (disabled)
	CFishAngel(const CFishAngel &) = delete;

	/// \brief Destructor
	~CFishAngel();

	
	virtual std::shared_ptr<xmlnode::CXmlNode> CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/// \brief Accept Visitor
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitAngel(this);  }
	/// \brief runs a function to increment time and the tests associated with them
	virtual void CFishAngel::PassTime() override;
	/// \brief resets the time since fed back to zero
	void ResetDaysSinceFed() { mDaysSinceFed = 0; }
};
