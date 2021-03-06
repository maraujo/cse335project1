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
#include "Aquarium.h"

/// Cost of adding baby fish to aquarium
const int BabyCost = 0;

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

	/** \brief Accept a visitor
	* \param visitor The visitor we accept */
	void Accept(CItemVisitor *visitor) override { visitor->VisitCat(this); }
	/// \brief runs a function to increment time and the tests associated with them
	virtual void CFishCat::PassTime() override {
		CAquarium *aquarium = GetAquarium();
		// If fish is pregnant
		if (mPregnant){
			//And it is time to have babes
			if (mPregnantDay > maxPregnancyDays){
				//Have two babes
				auto babe1 = std::make_shared<CFishCat>(aquarium);
				auto babe2 = std::make_shared<CFishCat>(aquarium);
				babe1->SetLocation(GetX(), GetY());
				babe2->SetLocation(GetX(), GetY());
				aquarium->Add(babe1, BabyCost);
				aquarium->Add(babe2, BabyCost);

				FinishPregnancy();
			}
			else
			{
				mPregnantDay++;
			}

		}
		else{
			mDaysSinceSex++;
		}
	}
	/// \brief resets the time since fed back to zero
	void ResetDaysSinceFed() { mDaysSinceFed = 0; }
};
