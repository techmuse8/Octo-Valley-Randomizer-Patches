#include <Lp/Utl/StateMachine.h>

namespace Game {

class StateMachine : public Lp::Utl::StateMachine { // made up derived class name

  public:
    virtual ~StateMachine() {} // stub to replace later

    u8 pad[26];
};

//static_assert(sizeof(StateMachine) == 0x38, "Game::StateMachine size mismatch");

} // namespace Game