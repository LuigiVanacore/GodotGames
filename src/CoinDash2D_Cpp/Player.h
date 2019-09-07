#pragma once

#include <core/Godot.hpp>
#include <Area2D.hpp>
#include <Input.hpp>
#include <algorithm>
#include <AnimatedSprite.hpp>


namespace godot {
	class Player : public Area2D {
		GODOT_CLASS(Player, Area2D)

	private:
		Vector2 velocity;
		Vector2 screenSize;
		AnimatedSprite* animation;

	public:
		const int speed = 350;
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();
		void _on_Player_area_entered(Area2D* area);

		Player();
		~Player();

		void start(Vector2 pos);
		Vector2 getScreenSize();
		void setScreenSize(Vector2 screenSize);
		void getInput();
		void setPosition(float delta);
		void setAnimation();
		void die();
	};
}