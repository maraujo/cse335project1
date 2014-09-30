/**
 * \file Breeding.h
 *
 * \author Matheus Araujo
 *
 * \brief Breeding Visitor File Implementation
 */

#pragma once
#include <vector>
#include "ItemVisitor.h"
#include "Fish.h"
#include "FishAngel.h"
#include "FishCat.h"

/**
* \brief Breeding Visitor Class Implementation
*/

class CBreeding :
	public CItemVisitor
{
public:
	/// \brief  Contructor
	CBreeding();
	/// \brief  Destructor
	virtual ~CBreeding();
	void CBreeding::VisitAngel(CFishAngel* fish) override {mAngelFishs.push_back(fish);	}
	void CBreeding::VisitCat(CFishCat* fish) override {	mCatFishs.push_back(fish);}
	void CBreeding::passDayFishes();
	void CBreeding::CheckAngelsHadSex();
	void CBreeding::CheckCatsHadSex();

protected:
	/// List of Angel fish in the aquarium
	std::vector<CFishAngel*> mAngelFishs;
	/// List of Cat fish in the aquarium
	std::vector<CFishCat*> mCatFishs;
};

