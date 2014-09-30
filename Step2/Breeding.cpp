/**
 * \file Breeding.cpp
 *
 * \author Matheus Araujo
 */

#include "stdafx.h"
#include "Breeding.h"


CBreeding::CBreeding()
{
}


CBreeding::~CBreeding()
{
}


/**
 * \brief Make Time pass for fishes who breed
 */
void CBreeding::passDayFishes(){
	for (auto fish : mAngelFishs){
		fish->PassTime();
	}
	for (auto fish : mCatFishs){
		fish->PassTime();
	}

}

/**
* \brief Check overlap and if Angels fishes will do sex
*/
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

/**
* \brief Check overlap and if Cats fishes will do sex
*/
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