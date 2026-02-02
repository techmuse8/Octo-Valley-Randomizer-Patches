#pragma once

#include <agl/common/aglTextureEnum.h>
#include <container/seadBuffer.h>
#include <container/seadPtrArray.h>
#include <container/seadSafeArray.h>
#include <heap/seadDisposer.h>
#include <agl/layer/aglLayerEnum.h>
#include <math/seadVector.h>
#include <sead/prim/seadSafeString.h>

namespace sead {

class Controller;

}

namespace agl {

class RenderBuffer;

namespace lyr {

class DrawMethod;
class Layer;

class Renderer
{
    SEAD_SINGLETON_DISPOSER(Renderer)

public:
    Renderer();
    virtual ~Renderer();

    bool draw(DisplayType display_type) const;

    void removeDrawMethod(const DrawMethod* p_draw_method);

    template <typename T>
    T* createLayer(s32 layer_index, const sead::SafeString& name, DisplayType display_type, sead::Heap* heap);

    RenderBuffer* getRenderBuffer(s32 index) const { return mRenderBuffer[index]; }

    s32 getLayerNum() const { return mLayer.size(); }
    Layer* const& getLayer(s32 index) const { return mLayer[index]; }

    template <typename T>
    T* getLayer(s32 index) const
    {
        return sead::DynamicCast<T>(mLayer[index]);
    }

protected:
    void initLayer_(Layer* p_layer, s32 layer_index, const sead::SafeString& name, DisplayType display_type, sead::Heap* heap);

protected: // originally protected
    u32 _14;
 //   MultiSampleType mMultiSampleType;
    sead::UnsafeArray<u32[0x78C / sizeof(u32)], cDisplayType_Max> mRenderDisplay; // sead::UnsafeArray<agl::lyr::RenderDisplay, cDisplayType_Max>
    int pad;
    sead::UnsafeArray<RenderBuffer*, cDisplayType_Max> mRenderBuffer;
    sead::Buffer<Layer*> mLayer;
  //  mutable sead::BitFlag32 mFlag;
 //   u32 _f40;
  //  u8 _db8[16];
  //  sead::UnsafeArray<sead::PtrArrayImpl, cDisplayType_Max> mRenderDisplayJob; // sead::UnsafeArray<sead::PtrArray<agl::lyr::RenderDisplay::Job>, cDisplayType_Max>
    u32 mRenderDLBuffer[0x50 / sizeof(u32)]; // agl::lyr::RenderDLBuffer
    u32 _f90;
    u32 _f94;
    s32 _f98;
    u8 unk_f9c[0xfb4 - 0xf9c];
    sead::UnsafeArray<u32[0x6C / sizeof(u32)], 3> mJobQueue; // sead::UnsafeArray<sead::FixedSizeJQ, 3>
    sead::PtrArrayImpl renderDisplayJobPtrArray[3];
    int _111c;
    int _1120;
    int _1124;
    sead::Controller* mpDebugController;
    f32 _112C;
    sead::Vector2f _1130;
    float _1138;
    u8 _113c;
    u8 _113d;
    u8 _113e;
    u8 _113f;
    u8 _1140;
    u8 _1141;
    u8 _1142;
    u8 unk_1443[0x114c - 0x1143];
};
//static_assert(sizeof(Renderer) == 0x114C, "agl::lyr::Renderer size mismatch");

template <typename T>
T* Renderer::createLayer(s32 layer_index, const sead::SafeString& name, DisplayType display_type, sead::Heap* heap)
{
    T* p_layer = new (heap, 4) T();
    initLayer_(p_layer, layer_index, name, display_type, heap);
    return p_layer;
}

} }
