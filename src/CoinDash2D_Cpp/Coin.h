#pragma once

#include <core/Godot.hpp>
#include <Area2D.hpp>
#include <AnimatedSprite.hpp>


namespace godot {
	class Coin : public Area2D {
		//GODOT_CLASS(Coin, Area2D)

	private:
		AnimatedSprite* animation;
		Vector2 screenSize;

	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();
		void _on_Player_area_entered(Area2D* area);

		Coin();
		~Coin();
		void pickUp();
		void set_screenSize(Vector2 screenSize);

	};
}