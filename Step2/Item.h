/**
 * \file Item.h
 *
 * \author Matheus Araujo
 *
 * \brief Creates Item that will be added to Aquarium
 *
 * This Class will represent the items that will be added to Aquarium
 */

#pragma once
#include <string>
#include <memory>
#include "XmlNode.h"
#include "ItemVisitor.h"

class CAquarium;

/**
* \brief Base class for any item in our aquarium.
*/
class CItem
{
public:
	/// \brief Default constructor (disabled)
	CItem() = delete;

	/// \brief Copy constructor (disabled)
	CItem(const CItem &) = delete;

	/// \brief Constructor
	CItem(CAquarium *aquarium, const std::wstring &filename);

	virtual ~CItem();

	/** The X location of the item
	* \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/** The the width of the item
	* \returns width in pixels */
	int GetWidth(){ return mItemImage->GetWidth() ; };

	/** The the height of the item
	* \returns height in pixels */
	int GetHeight(){ return mItemImage->GetHeight(); };

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	void SetLocation(double x, double y) { mX = x; mY = y; }

	//! Draw this item
	//! \param graphics Device context to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	/** \brief Test this item to see if it has been clicked on
	* \param x X location on the aquarium to test
	* \param y Y location on the aquarium to test
	* \return true if clicked on */
	bool CItem::HitTest(int x, int y);
	virtual void CItem::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);

	virtual std::shared_ptr<xmlnode::CXmlNode> CItem::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

	/// \brief Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}

	/// \brief Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium *GetAquarium() { return mAquarium; }

	/// \brief Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

	/** \brief Accept a visitor
	* \param visitor The visitor we accept */
	virtual void Accept(CItemVisitor *visitor) = 0;

protected:
	
	std::unique_ptr<Gdiplus::Bitmap> mItemImage; ///< member that loads Fish Image 

private:
	/// The aquarium this item is contained in
	CAquarium   *mAquarium;

	// Item location in the aquarium
	double   mX = 0;     ///< X location for the center of the item
	double   mY = 0;     ///< Y location for the center of the item
	bool mMirror = false;   ///< True mirrors the fish image
	
};