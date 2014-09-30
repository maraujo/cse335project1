#pragma once
#include <vector>
#include "ItemVisitor.h"
#include "Fish.h"
#include "FishAngel.h"
#include "FishCat.h"





class CBreeding :
	public CItemVisitor
{
public:
	std::vector<CFishAngel*> mAngelFishs;
	std::vector<CFishCat*> mCatFishs;
	CAquarium *mAquarium;
	
	CBreeding();
	
	virtual ~CBreeding();
	void CBreeding::VisitAngel(CFishAngel* fish) override {
		mAngelFishs.push_back(fish);
	}
	void CBreeding::VisitCat(CFishCat* fish) override {
		mCatFishs.push_back(fish);
	}

	void CBreeding::passDayFishes(){
		for (auto fish : mAngelFishs){
			fish->PassTime();
		}
		for (auto fish : mCatFishs){
			fish->PassTime();
		}
		
	}

	void CBreeding::CheckAngelsHadSex(){
		//Check for all combination of fish pair of the same time
		for (auto fish : mAngelFishs){
			for (auto other_fish : mAngelFishs)
			{
				//Check if they overlap
				if (fish->HitTest((int)other_fish->GetX(), (int)other_fish->GetY()))
				{
					//If they overlap, check if it is not the fish him self
					//check if both are interested
					//check if both are diferent gender
					if (fish != other_fish && fish->IsInterested() && other_fish->IsInterested() && fish->GetGender() != other_fish->GetGender()){
						if (fish->GetGender() == CFish::FEMALE)
						{
							fish->StartPregnancy();
						}
						else
						{
							other_fish->StartPregnancy();
						}
						fish->SetDaysSinceSex(0);
						other_fish->SetDaysSinceSex(0);

					}
				}

			}
		}
	}
	void CBreeding::CheckCatsHadSex(){
		//Check for all combination of fish pair of the same time
		for (auto fish : mCatFishs){
			for (auto other_fish : mCatFishs)
			{
				//Check if they overlap
				if (fish->HitTest((int)other_fish->GetX(), (int)other_fish->GetY()))
				{
					//If they overlap, check if it is not the fish him self
					//check if both are interested
					//check if both are diferent gender
					if (fish != other_fish && fish->IsInterested() && other_fish->IsInterested() && fish->GetGender() != other_fish->GetGender()){
						if (fish->GetGender() == CFish::FEMALE)
						{
							fish->StartPregnancy();
						}
						else
						{
							other_fish->StartPregnancy();
						}
						fish->SetDaysSinceSex(0);
						other_fish->SetDaysSinceSex(0);

					}
				}

			}
		}
	}
};

