#pragma once

#include <agl/common/aglRenderBuffer.h>
#include <agl/layer/aglLayerEnum.h>

namespace sead {

class Camera;
class Projection;
class Viewport;

}

namespace agl {

class DisplayList;

namespace lyr {

class Layer;

class RenderInfo
{
public:
    RenderInfo(DisplayList* p_display_list, DisplayType display_type, const sead::FrameBuffer* frame_buffer, bool, const Layer* p_layer);
    RenderInfo(DisplayType display_type, const sead::FrameBuffer* frame_buffer);

    s32 getRenderStep() const { return mRenderStep; }
    DisplayType getDisplayType() const { return mDisplayType; }
    const sead::FrameBuffer* getFrameBuffer() const { return mpFrameBuffer; }
    const agl::RenderBuffer* getRenderBuffer() const { return static_cast<const agl::RenderBuffer*>(mpFrameBuffer); }
    s32 getLayerIndex() const { return mLayerIndex; }
    Layer* getLayer() const { return mpLayer; }
    const sead::Camera* getCamera() const { return mpCamera; }
    const sead::Projection* getProjection() const { return mpProjection; }
    const sead::Viewport* getViewport() const { return mpViewport; }
    DisplayList* getDisplayList() const { return mpDisplayList; }
    void bindFrameBufferAndApplyViewport();

private:
    s32 mRenderStep;
    DisplayType mDisplayType;
    s32 mLayerIndex;
    const sead::FrameBuffer* mpFrameBuffer;
    Layer* mpLayer;
    DisplayList* mpDisplayList;
    const sead::Camera* mpCamera;
    const sead::Projection* mpProjection;
    const sead::Viewport* mpViewport;
    bool _24;
};
static_assert(sizeof(RenderInfo) == 0x28, "agl::lyr::RenderInfo size mismatch");

} }
