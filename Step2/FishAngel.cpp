/**
* \file FishAngel.cpp
*
* \author Matheus Araujo
*/

#include "stdafx.h"
#include <string>
#include "FishAngel.h"

using namespace std;
using namespace Gdiplus;

/// Fish filename 
const wstring FishAngelImageName(L"images/angelfish.png");
/// Max speed
/// Speed in pixels per second
const int MaxSpeedX = 25;
/// Min speed
/// Speed in pixels per second
const int MinSpeedX = 10;

/** Constructor
* \param aquarium The aquarium this is a member of
*/
CFishAngel::CFishAngel(CAquarium *aquarium) : CFish(aquarium, FishAngelImageName)
{
	mSpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	/// Days since had sex
	mDaysSinceSex = 0;
	/// is Pregnant
	mPregnant = false;
	/// Days since had sex
	mPregnantDay = 0;

}

/**
* \brief Destructor
*/
CFishAngel::~CFishAngel()
{
}

/** \brief Save this item to an XML node
* \param node The node we are going to be a child of
* \returns XML node
*/
std::shared_ptr<xmlnode::CXmlNode> CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"angel");
	return itemNode;
}


/**
 * \brief Pass time
 *
 * Increment day since had sex, increment pregnant day, and check if it is time to have a babe
 */
void CFishAngel::PassTime(){
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