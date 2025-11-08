#include <cafe.h>

namespace Lp {
namespace Utl {

class StateMachine {

  public:
    virtual ~StateMachine() {}

    int unk1;
    s32 _8;
    s8 _C;
    s8 _D;
    u8 _E;
    u8 _F;
    u8 _10;
    u8 _11;
    u8 unk[2];
    s32 _14;
    u8 pad[2];
};

//static_assert(sizeof(StateMachine) == 0x1A, "Lp::Utl::StateMachine size mismatch");
} // namespace Utl
} // namespace Lp