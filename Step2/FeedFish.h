/**
 * \file FeedFish.h
 *
 * \author Nicholas Reuter
 *
 * \brief Contains visitor class to reset time since fed
 */

#pragma once
#include "ItemVisitor.h"
#include "ItemVisitor.h"
#include "FishAngel.h"
#include "FishCat.h"
#include "FishBeta.h"

/**
 * \brief Class to reset time since fed
 */
class CFeedFish :
	public CItemVisitor
{
public:
	CFeedFish();
	virtual ~CFeedFish();

	void VisitAngel(CFishAngel *fish) override { fish->ResetDaysSinceFed(); }
	void VisitBeta(CFishBeta *fish) override { fish->ResetDaysSinceFed(); }
	void VisitCat(CFishCat *fish) override { fish->ResetDaysSinceFed(); }
};

