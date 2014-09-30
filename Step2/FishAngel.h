/**
* \file FishAngel.h
*
* \author Matheus Araujo
*
* \brief Class that describes the Angel Fish behaviour
*/

#pragma once
#include <memory>
#include "Fish.h"

/**
* \brief Implements a Angel fish
*/
class CFishAngel : public CFish
{
public:
	CFishAngel(CAquarium *aquarium);

	/// \brief Default constructor (disabled)
	CFishAngel() = delete;

	/// \brief Copy constructor (disabled)
	CFishAngel(const CFishAngel &) = delete;

	~CFishAngel();

	
	virtual std::shared_ptr<xmlnode::CXmlNode> CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual void Accept(CItemVisitor *visitor) override { visitor->VisitAngel(this);  }

	virtual void CFishAngel::PassTime() override {
		CAquarium *aquarium = GetAquarium();
		// If fish is pregnant
		if (IsPregnant()){
			//And it is time to have babes
			if (mPregnantDay > maxPregnancyDays){
				//Have two babes
				auto babe1 = std::make_shared<CFishAngel>(aquarium);
				auto babe2 = std::make_shared<CFishAngel>(aquarium);
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
