#pragma once
#include "Aquarium.h"

class CFishAngel;
class CFishCat;
class CFishBeta;


class CItemVisitor
{
public:
	CItemVisitor();
	virtual ~CItemVisitor();


	/** \brief Visit a CFishAngel object
	* \param Angel we are visiting */
	virtual void VisitAngel(CFishAngel* angel) = 0;
	/** \brief Visit a CFishCat object
	* \param Cat we are visiting */
	virtual void VisitCat(CFishCat* cat) = 0;
	/** \brief Visit a CFishBeta object
	* \param Beta we are visiting */
	virtual void VisitBeta(CFishBeta *beta){};


};

