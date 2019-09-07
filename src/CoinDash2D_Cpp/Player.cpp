#include "Player.h"

using namespace godot;

void Player::_register_methods() {
	register_method((char*)"_ready", &Player::_ready);
	register_method((char*)"_process", &Player::_process);
	register_method((char*)"start", &Player::start);
	//register_method((char*)"_on_Player_area_entered", &Player::_on_Player_area_entered);
	register_method((char*)"setScreenSize", &Player::setScreenSize);
	//register_method((char*)"setPosition", &Player::setPosition);
	//register_signal<Player>((char *)"pickup", "node", GODOT_VARIANT_TYPE_OBJECT);
	//register_signal<Player>((char *)"hurt", "node", GODOT_VARIANT_TYPE_OBJECT);

}

void Player::_init() {}

void Player::_ready() {
	animation = (AnimatedSprite*)this->get_node("animation");
	animation->_set_playing(true);
	animation->set_animation("idle");
}

void Player::start(Vector2 pos) {
	Godot::print("Player start");
	animation = (AnimatedSprite*)this->get_node("animation");
	set_process(true);
	set_position(pos);
	animation->_set_playing(true);
	animation->set_animation("idle");
}

Vector2 Player::getScreenSize() { return screenSize; }


void Player::setScreenSize(Vector2 screenSize) {
	this->screenSize = screenSize;
	Godot::print("screen size " + this->screenSize);

}

Player::Player() {
	velocity = Vector2(0, 0);
}

Player::~Player() {}

void Player::_process(float delta) {
	getInput();
	Godot::print("screen size" + screenSize);
	setPosition(delta);
	setAnimation();
	
		
}

void Player::getInput() {
	velocity = Vector2(0, 0);
	Input* i = Input::get_singleton();
	if (i->is_action_pressed("ui_up")) {
		velocity.y -= 1;
	}
	if (i->is_action_pressed("ui_down")) {
		velocity.y += 1;
	}
	if (i->is_action_pressed("ui_left")) {
		velocity.x -= 1;
	}
	if (i->is_action_pressed("ui_right")) {
		velocity.x += 1;
	}
	if (velocity.length() > 0) {
		velocity = velocity.normalized() * speed;
	}

}


void Player::setPosition(float delta) {
	this->set_position(this->get_position() + velocity * delta);
	this->set_position(Vector2(std::clamp<real_t>(this->get_position().x, 0, screenSize.x), std::clamp<real_t>(this->get_position().y, 0, screenSize.y)));
}


void Player::setAnimation() {

	if (velocity.length() > 0) {
		animation->set_animation("run");
		if (velocity.x < 0)
			animation->set_flip_h(true);
		else if (velocity.x > 0)
			animation->set_flip_h(false);
	}
	else {
		animation->set_animation("idle");
	}

}

void Player::die() {
	animation->set_animation("hurt");
	set_process(false);
}

void Player::_on_Player_area_entered(Area2D* area) {
	if (area->is_in_group("coins")) {
		emit_signal("pickup", this);
	}
	if (area->is_in_group("obstacle")) {
		emit_signal("hurt", this);
		die();
	}
}
