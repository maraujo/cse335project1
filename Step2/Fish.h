#pragma once
#include "Item.h"
#include "ItemVisitor.h"

///Chance to be male;
const double MaleChance = 0.5;
///Minimum number of days after sex to be interested;
const int minDaysAfterSex = 3;
///Days of pregnancy to have babe;
const int maxPregnancyDays = 10;

/**
 * \brief Fish Class Implementation
 */
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
	/// \brief check if it is interested in sex
	bool CFish::IsInterested(){ return mDaysSinceSex > minDaysAfterSex; }
	/// \brief Set Gender
	void CFish::SetGender(Gender gender){ mGender = gender; }
	/// \brief Get Gender
	Gender CFish::GetGender(){ return mGender; }
	/// \brief Set Days Since Sex
	void CFish::SetDaysSinceSex(int days){ mDaysSinceSex = days; }
	/// \brief Accept Visitor
	virtual void CFish::Accept(CItemVisitor *visitor) = 0;
	/// \brief Check if it is Pregnant
	bool CFish::IsPregnant(){ return mPregnant; }
	/// \brief Start Pregnancy
	void CFish::StartPregnancy(){ mPregnant = true;	}
	/// \brief Finish Pregnancy
	void CFish::FinishPregnancy(){ mPregnant = false; }

	/// Pass time each second
	virtual void CFish::PassTime(){}

	virtual bool CheckFood() override 
	{
		if (mFood > mDaysSinceFed)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	virtual void Hunger() override { mDaysSinceFed++; }

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

	///Max days without food
	int mFood;

	///Days since fed
	int mDaysSinceFed;
};

