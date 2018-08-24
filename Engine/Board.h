#pragma once

#include "Graphics.h"
#include "Location.h"
#include <random>

class Board
{
public:
	Board( Graphics& gfx );
	void DrawCell( const Location& loc,Color c );
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool IsInsideBoard( const Location& loc ) const;
	bool CheckForObstacle(const Location& loc) const;
	void SpawnObstacle(std::mt19937& rng, const class Snake& snake, const class Goal& goal);
	bool CheckForPoison(const Location& loc) const;

	void DrawBorder();
	void DrawObstacles();
	void DrawPoison();
private:
	static constexpr Color borderColor = Colors::Blue;
	static constexpr Color obstacleColor = Colors::Gray;
	static constexpr Color poisonColor = Colors::Magenta;
	static constexpr int dimension = 20;
	static constexpr int cellPadding = 1;
	static constexpr int width = 32;
	static constexpr int height = 24;
	static constexpr int borderWidth = 4;
	static constexpr int borderPadding = 2;
	static constexpr int x = 70;
	static constexpr int y = 50;
	bool hasObstacle[width * height] = { false };
	bool hasPoison[width * height] = { false };
	Graphics& gfx;
};