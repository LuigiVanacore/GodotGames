#pragma once

#include <core/Godot.hpp>
#include <Node2D.hpp>
#include <Node.hpp>
#include <PackedScene.hpp>
#include <Viewport.hpp>
#include <Position2D.hpp>
#include <Timer.hpp>
#include "Player.h"
#include "Coin.h"
#include "HUD.h"

namespace godot {
	class Main : public Node {
		GODOT_CLASS(Main, Node)

	private:
		//PackedScene* coin;
		int playtime;
		int level;
		int score;
		int time_left;
		Vector2 screenSize;
		bool playing;
		Player* player;
		Position2D* player_position;
		//Timer* game_timer;
		//Node* coin_container;
		HUD* hud;

	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		Main();
		~Main();
		void start_game();
		//void spawn_coins();
		//void _on_GameTimer_timeout();
		//void game_over();
		//void _on_Player_pickup();
		//void _on_Player_hurt();
		void _on_HUD_start_game();

	};
}