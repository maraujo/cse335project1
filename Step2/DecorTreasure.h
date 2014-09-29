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
};
