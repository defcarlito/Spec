## Context

#### For those passing by...

Rocket League is a popular competitive e-sport video game currently maintained by Epic Games. Players control rocket-powered cars to hit a giant ball in a goal, kind of like soccer but with vehicles. It is known to be the closest a video game can be to a real sport due to its deep iceberg to level of possible skill. So, analytical data can be useful for improving and staying competitve.

BakkesMod, as the name suggests, is a mod for the game made by Chris Bakkes. It began as a standalone tool to help players train but evolved into an SDK for developers to expand the mod via plugins, with permission from Epic Games. The mod injects a .dll into the game's memory and hooks directly to the game's Unreal Engine objects and functions, allowing developers to read modify the game's state.

## Overview

This plugin extends the replay system by providing additional features such as:
- A minimap for a bird's-eye view of the field
    - View the location of the ball and all players as they move around the field
- A widget to view the live boost counts for all players
- An option to toggle line markers between teammates for team shape analyzation
