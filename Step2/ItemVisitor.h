/**
 * \file ItemVisitor.h
 *
 * \author Matheus Araujo
 *
 * \brief Item Visitor File Implementation
 */

#pragma once
#include "Aquarium.h"

class CFish;
class CFishAngel;
class CFishCat;
class CFishBeta;
class CDecorTreasure;
class CDecorSpartyTreasure;

/**
* \brief Item Visitor Class Implementation
*/
class CItemVisitor
{
public:
	/// \brief Contructor
	CItemVisitor();
	/// \brief Destructor
	virtual ~CItemVisitor();

	/** \brief Visit a CFishAngel object
	* \param angel we are visiting */
	virtual void VisitAngel(CFishAngel* angel) = 0;
	/** \brief Visit a CFishCat object
	* \param cat we are visiting */
	virtual void VisitCat(CFishCat* cat) = 0;
	/** \brief Visit a CFishBeta object
	* \param beta we are visiting */
	virtual void VisitBeta(CFishBeta *beta){};
	/** \brief Visit a CDecorTreasure object
	* \param treasure we are visiting */
	virtual void VisitDecorTreasure(CDecorTreasure *treasure){};

	/** \brief Visit a CDecorSpartyTreasure object
	* \param treasure we are visiting */
	virtual void VisitDecorSpartyTreasure(CDecorSpartyTreasure *treasure){};
};
