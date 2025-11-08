#include <types.h>

namespace Cmn {
class Actor {
    // Size: 0x28
  public:
    // vtable is at 0x1012265C
    virtual ~Actor() {}
    virtual void vfC(); // Deleted
    virtual bool checkDerivedRuntimeTypeInfo(char* a2);
    virtual void vf1C();
    virtual void load();
    virtual void vf2C();
    virtual void onActivate();
    virtual void vf3C();
    virtual void firstCalc();
    virtual void vf4C();
    virtual void secondCalc();
    virtual void vf5C();
    virtual void thirdCalc();
    virtual void fourthCalc();
    virtual void fifthCalc();
    virtual void vf7C();
    virtual void vf84();
    virtual const char* getClassName();
    virtual int maybeMtx1(); // returns either this->_08 + 52 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names and functionality?
    virtual int maybeMtx2(); // returns either this->_08 + 100 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names functionality?
    virtual int vfA4();      // returns firstCalc if this->_subobject2 & 1 == 0
    virtual int vfAC();      // returns vf4C if this->_subobject2 >> 1 & 1 == 0
    virtual int vfB4();      // returns secondCalc if this->_subobject2 >> 2 & 1 == 0
    virtual int vfBC();      // sub_285B100, calls vf10 if this->_subobject2 >> 3 & 1 == 0
    virtual int vfC4();      // calls thirdCalc if this->_subobject2 >> 4 & 1 == 0
    virtual int vfCC();      // calls fourthCalc if this->_subobject2 >> 5 & 1 == 0
    virtual int vfD4();      // calls fifthCalc if this->_subobject2 >> 6 & 1 == 0
    virtual int vfDC();      // returns load()
    virtual int vfE4();      // returns vf2C
    virtual int vfEC();      // returns onActivate
    virtual int vfF4();      // returns vf3C
    virtual int vfFC();      // returns vf7C
    virtual int vf104();      // returns vf84
    virtual void vf10C();     // Unimpd
    virtual int vf114();      // if this->_1C == 3, set 1C to 2 and return vf10C

    // void * vtable;
    void* subobject1;
    u32 _08;
    u32* subobject2;
    u32 _10;
    u32 _14;
    u32 _18;
    u32 _1C;
    u32 _20;
    u8 pad[4];

    Actor();
};
static_assert(sizeof(Actor) == 0x28, "Cmn::Actor size mismatch");
} // namespace Cmn