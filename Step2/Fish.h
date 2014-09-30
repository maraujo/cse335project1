#pragma once
#include "Item.h"
#include "ItemVisitor.h"
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

	/** \brief Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) override{};
protected:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
};

