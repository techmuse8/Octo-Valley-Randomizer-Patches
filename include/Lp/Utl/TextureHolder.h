#pragma once
#include <sead/heap/seadDisposer.h>

namespace Lp {
namespace Utl {

class TextureHolder : public sead::IDisposer {
  public:
    char _10;
    char _11;
    u8 _12;
    int _14;
    int _18;
    u8 unk_1C[192];
    u8 mTextureData[0x84]; // agl::TextureData
    u8 mTextureSampler[348]; // agl::TextureSampler
    int _2B8;
    u8 unk_2BC[164];
    char _360;
    char _361;
    u8 unk_362[2];
    u8 _364;
    u8 _365;
};

static_assert(sizeof(TextureHolder) == 0x36C, "Lp::Utl::TextureHolder size mismatch");

} // namespace Utl
} // namespace Lp