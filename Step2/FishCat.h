/**
* \file FishCat.h
*
* \author Matheus Araujo
*
* \brief Class that describes the Cat Fish behaviour
*/

#pragma once
#include <memory>
#include "Fish.h"


/**
* \brief Implements a Cat fish
*/
class CFishCat : public CFish
{
public:
	CFishCat(CAquarium *aquarium);

	/// \brief Default constructor (disabled)
	CFishCat() = delete;

	/// \brief Copy constructor (disabled)
	CFishCat(const CFishCat &) = delete;

	~CFishCat();

	virtual std::shared_ptr<xmlnode::CXmlNode> CFishCat::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

};
