#include "Coin.h"


using namespace godot;

//void Coin::_register_methods() {
//	register_method((char*)"_ready", &Coin::_ready);
//	register_method((char*)"_process", &Coin::_process);
//	register_method((char*)"pickUp", &Coin::pickUp);
//	register_method((char*)"_on_Player_area_entered", &Coin::_on_Player_area_entered);
//
//
//
//}



 Coin::Coin() {
	 screenSize = Vector2(0, 0);
 }


 Coin::~Coin() {}

 void Coin::_init() {}

 void Coin::_process(float delta) {}

 void Coin::_ready() {}

 void Coin::_on_Player_area_entered(Area2D* area) {}

 void Coin::pickUp() {
	 //this->queue_free();
 }

 void Coin::set_screenSize(Vector2 screenSize) {
	 //this->screenSize = screenSize;
 }

