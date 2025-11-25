#include "pch.h"
#include "Render.h"

LinearColor mapColor(20, 20, 20, 150);
LinearColor ballBorderColor(200, 200, 200, 255);
LinearColor ballColor(150, 150, 150, 255);
LinearColor	orangeColor(255, 165, 0, 255);
LinearColor blueColor(0, 128, 255, 255);

void Render(CanvasWrapper canvas, NormalizedLocation& bLoc, std::vector<CarData> allCarData)
{
	Vector2 mapSize = { 198, 273 }; // make adjustable
	canvas.SetPosition(Vector2F{ 1550.0, 400.0 }); // make adjustable according to montior size
	canvas.SetColor(mapColor);
	canvas.FillBox(mapSize);
	
	// Draw ball
	canvas.SetColor(ballBorderColor);
	canvas.SetPosition(Vector2F{ 1548 + bLoc.X * 198, 398 + bLoc.Y * 273 });
	canvas.FillBox(Vector2(14, 14));

	canvas.SetColor(ballColor);
	canvas.SetPosition(Vector2F{ 1550 + bLoc.X * 198, 400 + bLoc.Y * 273 });
	canvas.FillBox(Vector2(10, 10));
	
	// Draw players
	// use a queue for efficiency
	// build car vector in render() ?
	for (const auto& c : allCarData) {
		canvas.SetColor(c.team == 1 ? orangeColor : blueColor);
		canvas.SetPosition(Vector2F{ 1550 + c.location.X * 198, 400 + c.location.Y * 273 });
		canvas.FillBox(Vector2(10, 10));
	}
}


