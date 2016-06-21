#ifndef MRG_ITEM
#define MRG_ITEM
#include <string>

namespace mrg {
	class player;
	typedef unsigned short weapon_type;
	typedef unsigned short armor_type;
	typedef unsigned short damage_type;
	class item {
		protected:
		unsigned char rank;
		player *owner;
		unsigned weight;

		public:
		virtual std::string &get_name();
		player &get_owner();
		virtual void taken(player &from);
		unsigned get_weight();
	};

	class wearable : public item {
		public:
		virtual void on_set(player &who);
		virtual void on_remove(player &who);
	};

	class weapon : public wearable {
		protected:
		virtual bool block(player &from, weapon &by);

		public:
		virtual void strike(player &target);
		virtual bool parry(player &target);
		double get_range();
		weapon_type get_type();
		std::string &print_type();
		virtual std::string &shot_condition();
	};

	class armor : public wearable {
		public:
		virtual bool check_penetration(player &from, weapon &by, unsigned doom);
		virtual unsigned calc_damage(player &from, damage_type type, long damage);
	};

	class useable : public item {
		virtual void use(player &target);
	};

	class effect {
		public:
		virtual void before(player &target, player &from, item &by);
		virtual bool tic(player &target, player &from, item &by);
		virtual void after(player &target, player &from, item &by);
	};


	std::string &get_weapon_type_name(weapon_type type);
	std::string &get_armor_type_name(armor_type type);
	std::string &get_damage_type_name(damage_type type);
}
#endif
