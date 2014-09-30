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

	~CFishAngel();

	
	virtual std::shared_ptr<xmlnode::CXmlNode> CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/** \brief Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitFishAngel(this); }
};
