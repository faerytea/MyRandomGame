#ifndef MRG_PLANE
#define MRG_PLANE
#include <vector>

namespace mrg {
	class item;
	class player;
	class point;

	class plane {
		public:
		plane(unsigned seed = 0);
		virtual std::vector<item *> get_content(point &where);
		virtual std::vector<player *> get_people(point &where);
		virtual ~plane();
	} default_plane;

	class point final {
		friend bool operator==(point &a, point &b);
		friend bool distance(point &a, point &b);

		public:
		point(long x, long y, plane &where = default_plane);
	};
}
#endif
