#ifndef _RHAPSODIES_IDEBUGVIEW
#define _RHAPSODIES_IDEBUGVIEW

#include <string>

namespace rhapsodies {
	class IDebugView {
    public:
		enum Slot {
			LOOP_FPS,
			LOOP_TIME,
			CAMERAFRAMES_TIME,
			PSO_TIME,
			REDUCTION_TIME,			
			DIFFERENCE,
			UNION,
			INTERSECTION,
			SLOT_LAST
		};

		virtual ~IDebugView() {};
		virtual void Update(Slot slot, std::string sText) = 0;

    private:
	};
}

#endif // _RHAPSODIES_IDEBUGVIEW
