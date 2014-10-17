/**
* \file Game.cpp
*
* \author Zachary Walters
*/

#include "stdafx.h"
#include <memory>
#include "Game.h"
#include "Aquarium.h"
#include "XmlNode.h"

using namespace std;

/**
 * \brief Constructor
 */
CGame::CGame()
{
}

/**
 * \brief Destructor
 */
CGame::~CGame()
{
}

/** \brief Add points to the current score for keeping the fish alive
 * \param add Amount of points to add to the current score
 */
void CGame::AddScore(int add)
{
	mScore += add;
}

/** \brief Subtract points to the current score for fish dying or lack of cleanliness in the aquarium
 * \param reduction Amount of points to subtract from the current score
 */
void CGame::ReduceScore(int reduction)
{
	mScore -= reduction;
	
	if (mScore < 0)
	{
		mGameOver = true;
	}
}

/** \brief Sets the score after a game has been loaded from a .aqua file
 * \param score Score of previous game when saved
 */
void CGame::SetScore(int score)
{
	mScore = score;
}

/** \brief Resets the score and game over boolean when a new game is started after a game over
 */
void CGame::ResetGame()
{
	mScore = 10;
	mGameOver = false;
}