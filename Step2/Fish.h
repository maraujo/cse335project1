#pragma once
#include "Item.h"
#include "ItemVisitor.h"

///Chance to be male;
const double MaleChance = 0.5;
///Minimum number of days after sex to be interested;
const int minDaysAfterSex = 3;
///Days of pregnancy to have babe;
const int maxPregnancyDays = 10;

class CFish :
	public CItem
{
public:
	/// \brief Type Gender
	enum Gender { MALE, FEMALE };
	/// \brief Default constructor (disabled)
	CFish() = delete;
	/// \brief Copy constructor (disabled)
	CFish(const CFish &) = delete;
	/// \brief Desconstructor
	virtual ~CFish();
	void CFish::Update(double elapsed);
	CFish::CFish(CAquarium *aquarium, const std::wstring &filename);
	std::shared_ptr<xmlnode::CXmlNode> CFish::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	bool CFish::IsInterested(){ return mDaysSinceSex > minDaysAfterSex; }
	/// Set Gender
	void CFish::SetGender(Gender gender){ mGender = gender; }
	/// Get Gender
	Gender CFish::GetGender(){ return mGender; }
	
	/// Set Days Since Sex
	void CFish::SetDaysSinceSex(int days){ mDaysSinceSex = days; }

	virtual void CFish::Accept(CItemVisitor *visitor) = 0;
	bool CFish::IsPregnant(){ return mPregnant; }
	void CFish::StartPregnancy(){ mPregnant = true;	}
	void CFish::FinishPregnancy(){ mPregnant = false; }
	
	virtual void CFish::PassTime(){}

protected:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;

	/// Fish gender
	Gender mGender;

	/// Days since had sex
	int mDaysSinceSex;

	/// is Pregnant
	bool mPregnant;

	/// Days since had sex
	int mPregnantDay;



};

