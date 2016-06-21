#ifndef MRG_BASE
#define MRG_BASE

#include <string>

namespace mrg {
	typedef unsigned short damage_type;
	class player;
	class item;

	class effect {
		public:
		virtual void before(player &target, player &from, item &by);
		virtual bool tic(player &target, player &from, item &by);
		virtual void after(player &target, player &from, item &by);
	};

	std::string &get_damage_type_name(damage_type type);
}
#endif
