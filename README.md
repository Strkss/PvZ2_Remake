# Plants vs Zombies 2 Remake

Demo video: [https://youtu.be/EblWeJ6Xlm0](https://youtu.be/EblWeJ6Xlm0)

  - [Introduction](#introduction)
  - [Download Instructions](#download-instructions)
  - [How to Play](#how-to-play)
  - [Plants and Zombies](#plants-and-zombies)
      - [Plants](#plants)
      - [Zombies](#zombies)
  - [Graphics and Sound](#graphics-and-sound)
      - [Graphics](#graphics)
      - [Sound](#sound)
  - [Project Structure](#project-structure)
  - [Implemented Features](#implemented-features)

-----

## Introduction

**Plants vs Zombies 2 Remake** is inspired by the original *Plants vs. Zombies 2* (PopCap/EA). Built using the SDL2 library, this version is designed for desktop compatibility (unlike the mobile-only original). It is a tower defense game where players must strategically plant various flora to defend their home against waves of zombies.

## Download Instructions

1.  Download the compressed game file (ZIP) from: [https://github.com/Strkss/PvZ2\_Remake/releases](https://github.com/Strkss/PvZ2_Remake/releases)
2.  Extract the file and run the `.exe` file to play.

**Note:** As it was developed using Microsoft Visual Studio, the game requires the Microsoft Visual C++ Redistributable to run: [Download here](https://learn.microsoft.com/en-us/cpp/windows/latest-supported-vc-redist?view=msvc-170).

## How to Play

Upon launching, the game displays a splash screen. Click anywhere to proceed to the **World Map**.

### World Map

The World Map allows you to select levels. There are **5 levels** in total with increasing difficulty. Simply click on a numbered level to start. You can also use the **Exit** button to quit the game.

### Level Layout & Components

  * **Level Name:** Displays the current level you are playing.
  * **Progress Bar:** Shows your progress within the level, indicating when large waves of zombies which is marked with flag will attack.
  * **Sun & Sun Counter:** Sun is the primary currency. Collect falling suns and those produced by Sunflower by clicking on them. The counter tracks your current balance.
  * **Seed Packets:** Displays available plants and their costs. Press keys **1, 2, 3, 4** to select a plant, then click on the lawn to place it. Packets have a "cooldown" period after use.
  * **Shovel:** Used to remove plants. Press **Q** and click on a plant to dig it up.
  * **Lawn:** The 5-lane grid where the battle takes place.
  * **Pause Menu:** Press **Escape** to pause. Here you can adjust volume, resume, or quit the level.

**Win/Loss Conditions:**

  * **Win:** Successfully defeat all waves of zombies.
  * **Loss:** If a zombie reaches the house at the end of the lawn.

## Plants and Zombies

### Plants

  * **Peashooter:** Shoots peas to attack zombies in its lane.
  * **Sunflower:** Generates sun over time.
  * **Wall-nut:** Has a hard shell to act as a barrier.
  * **Potato Mine:** Explodes on contact with a zombie (requires time to arm itself underground).

### Zombies

  * **Basic Zombie:** Low health, slow movement.
  * **Conehead Zombie:** Wears a traffic cone, having 3x the health of a Basic Zombie.
  * **Buckethead Zombie:** Wears a metal bucket, having nearly 7x the health of a Basic Zombie.
  * **Flag Zombie:** Marks the arrival of a huge wave of zombies.

## Graphics and Sound

### Graphics

Assets are acquired directly or adapted from *Plants vs. Zombies 2*. Extraction was handled via [Sen Environment](https://github.com/harumazzz/Sen.Environment).

  * **Animations:** https://www.youtube.com/watch?v=fSXOXuL7sUo
  * **UI/Lawn/Packets:** Extracted from `.scg` files (`UI_AlwaysLoaded.scg`, etc.).
  * **Fonts:** https://plantsvszombies.fandom.com/f/p/2519622733529499385
  * **Tools:** Used [GIMP](https://www.gimp.org/) to make UI components and various websites like [ezgif](https://ezgif.com/gif-to-sprite), [kuut.xyz](https://kuut.xyz/spritesheet/), ... for spritesheet conversion.

### Sound

  * **Music:** https://plantsvszombies.fandom.com/wiki/Music
  * **SFX:** From various PvZ Fandom wiki entries.

## Project Structure

  * **Essentials:** Buttons, Constants, Texture wrapper, Global, Init, Math and RenderEngine.
  * **Game States (Scene Management):** Used a stack-based `SceneManager` to handle transitions between `TitleScreen`, `WorldMap`, `Level`, `PauseMenu`, `Win/Lose`, and `LevelIntro` screen.
  * **Level Components:** 
      * `FLawn`, `FGrid`: Manage grids and lawn.
      * `FPlant`, `FZombie` (and inherited subclasses): Entity logic.
      * `SunManager`, `SlotManager`: Handle sun and plant selection.
      * `WaveManager`: Zombie spawning mechanic.
      * `CollisionChecker`: Collision-related helper functions.

## Implemented Features

  * Functional Splash Screen and Level Selection.
  * Core PvZ 2 level mechanics.
  * 4 distinct Plant types and 4 distinct Zombie types.
  * 5 progressive levels.
  * High-resolution graphics with smooth animations.
  * Full audio suite including background music and interactive sound effects.