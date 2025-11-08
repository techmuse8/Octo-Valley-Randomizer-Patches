#include <types.h>
#include "../Cmn/Actor.h"

namespace Game {

class GambitActor : public Cmn::Actor {

    struct GambitActorSubStructThing {
        // Game::GambitActor *owner;
        u8 unk3;
        u8 unk4;
        u16 pad;
    };

    // Size: 0x50
  public:
    // vtable is at 0x100000D8
    void vfC(); // Deleted(?)
    bool checkDerivedRuntimeTypeInfo(char* a2) override;
    void vf1C() override;
    void load() override;
    void vf2C() override;
    void onActivate() override;
    void vf3C() override;
    void firstCalc() override;
    void vf4C() override;
    void secondCalc() override;
    void vf5C() override;
    void thirdCalc() override;
    void fourthCalc() override;
    void fifthCalc() override;
    void vf7C() override;
    void vf84() override;
    const char* getClassName() override;
    int maybeMtx1() override;    // returns either this->_08 + 52 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names and functionality?
    int maybeMtx2() override;    // returns either this->_08 + 100 if _08 == 0 or 0, maybe Mtx related based on Splatoon 2 names functionality?
    int vfA4() override;         // calls maybeMtx1 if this->_subobject2 & 1 == 0 then returns checkDerivedRTTI
    int vfAC() override;         // returns checkDerivedRTTI if this->_subobject2 >> 1 & 1 == 0
    int vfB4() override;         // returns firstCalc if this->_subobject2 >> 2 & 1 == 0
    int vfBC() override;         // returns secondCalc if this->_subobject2 >> 3 & 1 == 0
    int vfC4() override;         // calls thirdCalc if this->_subobject2 >> 4 & 1 == 0
    int vfCC() override;         // calls fourthCalc if this->_subobject2 >> 5 & 1 == 0
    int vfD4() override;         // calls fifthCalc if this->_   subobject2 >> 6 & 1 == 0
    int vfDC() override;         // ActorLoadChildHeap related
    int vfF4() override;         // returns vf2C
    int vfFC() override;         // Calls onActivate, calls some virt function in _30, sets _38 to 0
    int vf104() override;        // Calls vf3C, then unk_200055C
    void vf10C() override;        // Calls 2884A48 with this_30 and 1, 205BE7C with _30, vf5C, vf7C, and sets some struct flag to 1
    int vf114() override;        // Calls vf84, does some other checks idk
    void vf11C() override;       // More virtfunc calls to list later
    int vf124() override;        // If _1C != 3, call vf114 then set _1C to 2
    void vf12C() override;       // Deleted
    virtual const char* vf134(); // Returns getClassName
    virtual int vf13C();         // Returns vf134
    virtual int vf144();         // ^
    virtual void vf14C();
    virtual void vf154();
    virtual void vf15C();
    virtual void vf164();
    virtual int vf16C();          // Returns 1
    virtual int vf174();          // Returns 4
    virtual int vf17C(int unk);   // Calls unk_2884178(a1->_30, a2, a1->_08, 0), something with skeletal animations?
    virtual void vf184(int* unk); // Comapres something in a struct unk is pointing to
    virtual void vf18C();
    virtual void vf194();
    virtual void vf19C(); // Calls vf214
    virtual void vf204(); // Calls vf21C
    virtual void vf20C(); // Calls vf224
    virtual void vf214();
    virtual void vf224();
    virtual void vf22C();
    virtual void vf234();
    virtual void vf23C();
    virtual void vf244(); // Doc later
    virtual int vf24C();  // Returns 1
    virtual int vf254();  // Returns 0

    u32 _28;
    s32 _2C;
    u32 _30;
    u32 _34;
    u32 _38;
    GambitActorSubStructThing unkThing;
    u8 _40;
    u8 _41;
    u16 _42;
    u8 _44;
    u8 pad[11];

    GambitActor();
};
static_assert(sizeof(GambitActor) == 0x50, "Game::GambitActor size mismatch");
} // namespace Game