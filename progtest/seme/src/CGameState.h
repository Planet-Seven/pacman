#pragma once

#include "CPos.h"
#include "CGameMap.h"

#include "utility"

/** \class CGameState
 A collection of variables and constants used as a context for other functions and methods.
*/
constexpr int PLAYER_SPEED = 5;
constexpr int WINDOW_WIDTH = 840; // choose a multiple of 28
constexpr int WINDOW_HEIGHT = BOARDHEIGHT * (static_cast<double>(WINDOW_WIDTH) / BOARDWIDTH);

struct CGameState
{
    int level;
    CPos playerPos;

    enum class CGameMode
    {
        chase,
        guard,
        powerup,
        lightsout
    };

    enum class CDirection
    {
        none,
        up,
        left,
        down,
        right
    };

    CDirection thisMove = CDirection::none; ///< player move that is currently being executed
    CDirection nextMove = CDirection::none; ///< player move that is next in line. It will either be cached or executed on the next update.
    CGameMode gamemode;                     ///< used to guide ghost behavior and enable eating interaction.
    CGameMap gameMap;                       ///< used to specify the postions of all game elements on game start

    bool isNextMoveLegal();
    bool isThisMoveLegal();
    bool isAMoveLegal(CGameState::CDirection move);
    void updateMoves();
    void updatePos(double deltaTime);
    std::pair<int, int> getIntPos();
};