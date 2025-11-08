#include <basis/seadNew.h>
#include <controller/seadControlDevice.h>
#include <controller/seadControllerMgr.h>
#include <prim/seadDelegate.h>

#ifdef cafe
#include <controller/cafe/seadCafeDRCControllerCafe.h>
#include <controller/cafe/seadCafeRemoteControllerCafe.h>
#endif // cafe

namespace sead {
Controller* ControllerMgr::getControllerByOrder(ControllerDefine::ControllerId id, s32 index) const
{
    for (PtrArray<Controller>::iterator it = mControllers.begin(); it != mControllers.end(); ++it)
    {
        Controller& controller = *it;
        if (controller.mId == id)
        {
            if (index == 0)
                return &controller;

            index--;
        }
    }

    return nullptr;
}
    }      