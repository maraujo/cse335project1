/**
 * \file ItemVisitor.h
 *
 * \author Nicholas Reuter
 *
 * \brief Contains the visitor base class
 */

#pragma once

//Forward references to all item types
class CFishCat;
class CFishBeta;
class CFishAngel;
class CDecorTreasure;

/**
 * \brief Visitor base class
 */
class CItemVisitor
{
public:
	CItemVisitor();
	virtual ~CItemVisitor();

	/** \brief Visit a CFishCat object
	* \param cat Cat Fish we are visiting */
	virtual void VisitFishCat(CFishCat *cat) {}

	/** \brief Visit a CFishBeta object
	* \param beta Beta Fish we are visiting */
	virtual void VisitFishBeta(CFishBeta *beta) {}

	/** \brief Visit a CFishAngel object
	* \param angel Angel Fish we are visiting */
	virtual void VisitFishAngel(CFishAngel *angel) {}

	/** \brief Visit a CDecorTreasure object
	* \param treasure Treasure Chest we are visiting */
	virtual void VisitDecorTreasure(CDecorTreasure *treasure) {}
};

