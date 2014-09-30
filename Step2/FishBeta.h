/**
 * \file FishBeta.h
 *
 * \author Matheus Araujo
 *
 * \brief Class that describes the Beta Fish behaviour
 */

#pragma once
#include <memory>
#include "Fish.h"

/**
* \brief Implements a Beta fish
*/
class CFishBeta : public CFish
{
public:
	CFishBeta(CAquarium *aquarium);

	/// \brief Default constructor (disabled)
	CFishBeta() = delete;

	/// \brief Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;

	~CFishBeta();

	std::shared_ptr<xmlnode::CXmlNode> CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitBeta(this); }
};
