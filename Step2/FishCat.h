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

	void Accept(CItemVisitor *visitor) override { visitor->VisitCat(this); }

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
				aquarium->Add(babe1);
				aquarium->Add(babe2);

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

};
