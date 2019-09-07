#pragma once

#include <core/Godot.hpp>
#include <CanvasLayer.hpp>
#include <MarginContainer.hpp>
#include <Label.hpp>
#include <Button.hpp>
#include <Timer.hpp>
#include <thread>

namespace godot {
	class HUD : public CanvasLayer {
		GODOT_CLASS(HUD, CanvasLayer)

	private:
		Label* message_label;
		MarginContainer* margin_container;
		Label* score_label;
		Label* time_label;
		Button* start_button;
		Timer* message_timer;

	public:
		static void _register_methods();
		void _init();
		void _process(float delta);
		void _ready();

		HUD();
		~HUD();

		void update_score();
		void update_time();
		void _on_MessageTimer_timeout();
		void _on_StartButton_pressed();
		void show_message(godot::String message);
	};
}