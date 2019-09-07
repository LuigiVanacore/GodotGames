#include "Main.h"

using namespace godot;

void Main::_register_methods() {
	register_method((char*)"_ready", &Main::_ready);
	register_method((char*)"_process", &Main::_process);
	register_method((char*)"_on_HUD_start_game", &Main::_on_HUD_start_game);
	register_method((char*)"start_game", &Main::start_game);
	//register_method((char*)"_on_GameTimer_timeout", &Main::_on_GameTimer_timeout);
	//register_method((char*)"_on_Player_pickup", &Main::_on_Player_pickup);
	//register_method((char*)"_on_Player_hurt", &Main::_on_Player_hurt);
	//register_property<Main, PackedScene*>("coin", &Main::coin, PackedScene::_new());


}

Main::Main() {
		playing = false;

}

Main::~Main() {
}

void Main::_init() {
}

void Main::_ready() { 
	Godot::print("Main ready enter");
	screenSize = this->get_viewport()->get_visible_rect().size;
	player = (Player*) this->get_node("Player");
	Godot::print("Player initialized");
	player_position = (Position2D*)this->get_node("PlayerStart");
	//game_timer = (Timer*)this->get_node("GameTimer");
	//coin_container = (Node*)this->get_node("CoinContainer");
	//hud = (HUD*)this->get_node("HUD");
	
	//player->hide();
	Godot::print("Main ready exit");

}

void Main::start_game() {
	Godot::print("Main start_game");

	Godot::print(screenSize);
	player->setScreenSize(screenSize);

	/*playing = true;
	level = 1;
	score = 0;
	time_left = playtime;
	player->start(player_position->get_position());
	player->show();*/
	//game_timer->start();
	//spawn_coins();
}

void Main::_process(float delta) {

	//if (playing && coin_container->get_child_count() == 0) {
	//		level += 1;
	//		time_left += 5;
	//		//spawn_coins();
	//}

}

//void Main::spawn_coins() {
//
//	/*	for (int i = 0; i < 4 + level; i++) {
//			auto c = (Coin*) coin->instance();
//			coin_container->add_child(c);
//			c->set_screenSize(screenSize);
//			c->set_position(Vector2(rand() % (int) screenSize.x + 1, rand() % (int) screenSize.y + 1));
//	}*/
//}


//void Main::_on_GameTimer_timeout() {
//	time_left -= 1;
//	//hud->update_time(time_left);
//	if (time_left <= 0) {
//		//game_over();
//	}
//}

//void Main::_on_Player_pickup() {
//	score += 1;
//	Godot::print("on Enter update score");
//	//hud->update_score();
//	Godot::print("on Exit update score");
//
//}

//void Main::_on_Player_hurt() {
//	//game_over();
//}

//void Main::game_over() {
//	playing = false;
//	game_timer->stop();
//	for (int i = 0; i < coin_container->get_child_count(); i++) {
//		auto c = coin_container->get_child(i);
//		c->queue_free();
//	}
//	//hud->call("show_game_over()");
//	player->die();
//
//}

void Main::_on_HUD_start_game() {
	start_game();
}