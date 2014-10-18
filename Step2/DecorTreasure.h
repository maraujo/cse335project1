/**
 * \file DecorTreasure.h
 *
 * \author Matheus Araujo
 *
 * \brief  Class that describes the Treasure Fish behaviour
 */
#pragma once
#include <memory>
#include "Item.h"

/**
* \brief Tresure Class Implementation
*/
class CDecorTreasure :
	public CItem
{
public:
	CDecorTreasure(CAquarium *aquarium);
	
	virtual ~CDecorTreasure();

	/// \brief Default constructor (disabled)
	CDecorTreasure() = delete;

	/// \brief Copy constructor (disabled)
	CDecorTreasure(const CDecorTreasure &) = delete;


	virtual void Draw(Gdiplus::Graphics *graphics);
	
	virtual std::shared_ptr<xmlnode::CXmlNode> CDecorTreasure::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	/** \brief Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitDecorTreasure(this); }
	/// \brief check function \returns false
	virtual bool CheckFood() override { return true; };
	/// \brief check if hungry (does nothing)
	virtual void Hunger() override {};

	/** \brief States that item clicked on is a bubbles object */
	bool IsBubbles() { return false; }
};

