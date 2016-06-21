#ifndef MRG_PLAYER
#define MRG_PLAYER
#include <string>
#include <vector>
#include "item.hpp"
#include "plane.hpp"

namespace mrg {
	class player {
		public:
		player(unsigned seed = 0, plane &where = default_plane);
		virtual point &where();
		virtual bool move(point &target);
		virtual void wear(wearable &gear);
		virtual void remove(wearable &gear);
		virtual void attack(point &target);
		virtual void take_damage(long damage);
		virtual ~player();
	};
}
#endif
