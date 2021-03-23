#pragma once

#include "Th10Hook/Common.h"

#include <vector>

#include "Th10Hook/Player.h"
#include "Th10Hook/Item.h"
#include "Th10Hook/Enemy.h"
#include "Th10Hook/Bullet.h"
#include "Th10Hook/Laser.h"

namespace th
{
	class Status
	{
	public:
		Status();

		void update();
		void copy(const Status& other);

		// Player

		// Item

		// Enemy
		bool haveEnemies() const;
		bool isBoss() const;
		bool isTalking() const;
		bool isUnderEnemy() const;

		// Bullet
		int_t collide(const Player& player, float_t frame) const;
		int_t collide(const Player& player, float_t frame, int_t id) const;

		// Laser

		const Player& getPlayer() const;
		const std::vector<Item>& getItems() const;
		const std::vector<Enemy>& getEnemies() const;
		const std::vector<Bullet>& getBullets() const;
		const std::vector<Laser>& getLasers() const;

		uint_t inputFrame;
		uint_t statusFrame;
		uint_t handleFrame;
		int_t frame1;

	private:
		Player m_player;
		std::vector<Item> m_items;
		std::vector<Enemy> m_enemies;
		std::vector<Bullet> m_bullets;
		std::vector<Laser> m_lasers;
	};
}
