#include "pch.h"
#include "Spec.h"
#include "Render.h"

#include <cmath>

BAKKESMOD_PLUGIN(Spec, "Spectate your friend's matches.", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

#define X_MIN -4079
#define X_MAX 4079
#define Y_MIN -5013
#define Y_MAX 5013
#define Z_MIN 17
#define Z_MAX 2031

void Spec::onLoad()
{
	_globalCvarManager = cvarManager;
	LOG("Plugin loaded!"); 

	//gameWrapper->HookEvent("Function Engine.Actor.Timer", std::bind(&Spec::onTick, this));

	gameWrapper->RegisterDrawable([this](CanvasWrapper canvas)
	{
		if (!gameWrapper->IsInReplay()) return;

		onTick();
		Render(canvas, this->ballCoords, this->allCarData);
		allCarData.clear();
	});

}

void Spec::onTick()
{
	ServerWrapper server = gameWrapper->GetCurrentGameState();
	if (!server) {
		LOG("SERVER IS NULL");
		return;
	}
	
	BallWrapper ball = server.GetBall();
	if (!ball) {
		LOG("BALL IS NULL");
		return;
	}

	ArrayWrapper<CarWrapper> cars = server.GetCars();
	if (cars.IsNull()) {
		LOG("CARS ARE NULL");
		return;
	}

	for (CarWrapper c : cars) {
		int cTeam = c.GetPRI().GetTeamNum();
		Vector cLoc = c.GetLocation();
		NormalizedLocation cNormLocation = normalizeCoords(cLoc);
		CarData cData = {
			cNormLocation,
			c.GetRotation(),
			cTeam
		};
		allCarData.push_back(cData);
	}

	Vector ballLoc = ball.GetLocation();
	ballCoords = normalizeCoords(ballLoc);
}

NormalizedLocation Spec::normalizeCoords(Vector& loc) 
{
	float normalizedX = (loc.X - X_MIN) / (X_MAX - X_MIN);	
	float normalizedY = (loc.Y - Y_MIN) / (Y_MAX - Y_MIN);
	float normalizedZ = (loc.Z - Z_MIN) / (Z_MAX - Z_MIN);
	return NormalizedLocation{ normalizedX, normalizedY, normalizedZ };
}
