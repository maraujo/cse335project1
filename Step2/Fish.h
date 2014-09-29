#pragma once
#include "Item.h"
class CFish :
	public CItem
{
public:
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
protected:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
};

