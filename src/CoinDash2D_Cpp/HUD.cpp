#include "HUD.h"

using namespace godot;

 void HUD::_register_methods() {
	 register_method((char*)"_init", &HUD::_init);
	 register_method((char*)"_ready", &HUD::_ready);
	 register_method((char*)"update_score", &HUD::update_score);
	 register_method((char*)"update_time", &HUD::update_time);
	 //register_method((char*)"_on_MessageTimer_timeout", &HUD::_on_MessageTimer_timeout);
	 register_method((char*)"_on_StartButton_pressed", &HUD::_on_StartButton_pressed);
	 register_method((char*)"show_message", &HUD::show_message);
	 register_signal<HUD>((char *)"start_game", "node", GODOT_VARIANT_TYPE_OBJECT);

}

void HUD::_init() {
	
}

void HUD::_process(float delta) {

}

void HUD::_ready() {
	message_label = (Label*)this->get_node("MessageLabel");
	margin_container = (MarginContainer*)this->get_node("MarginContainer");
	//score_label = (Label*)margin_container->get_node("ScoreLabel");
	//time_label = (Label*)margin_container->get_node("TimeLabel");
	start_button = (Button*)this->get_node("StartButton");
	message_timer = (Timer*)this->get_node("MessageTimer");
}

HUD::HUD() {}

HUD::~HUD() {}




void HUD::update_score() {
	//score_label->set_text("sesso");
	Godot::print("sesso");
	//message_label->show();
}

void HUD::update_time() {
	//time_label->set_text(value);
}

void HUD::_on_MessageTimer_timeout() {
	message_label->hide();
}


void HUD::_on_StartButton_pressed() {
	start_button->hide();
	message_label->hide();
	emit_signal("start_game");
}

void HUD::show_message(godot::String message) {
	message_label->set_text(message);
	message_label->show();
	message_timer->start();
}

