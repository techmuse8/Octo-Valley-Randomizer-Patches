#pragma once

#include <gfx/seadColor.h>
#include <math/seadBoundBox.h>
#include <math/seadMatrix.h>
#include <sead/math/seadVector.h>

namespace sead
{
class Viewport;
class Camera;
class Projection;
class DrawContext;
class FontBase;

class TextWriter
{
public:
    explicit TextWriter();
    TextWriter(const Viewport* viewport);
    virtual ~TextWriter();

    FontBase* getDefaultFont();
    static void setDefaultFont(FontBase* font);
    static void setupGraphics();
    void printImpl_(const wchar_t*, int, bool, BoundBox2f*, const Projection*, const Camera*);
    void printImpl_(const char*, int, bool, BoundBox2f*);
    void getCursorFromTopLeft(Vector2f* pos) const;
    void setCursorFromTopLeft(const Vector2f& pos);
    void setScaleFromFontSize(const Vector2f& fontSize);
    void setScaleFromFontHeight(float fontHeight);
    void setProjectionAndCamera(const Projection* projection, const Camera* camera);
    void setLineSpaceFromLineHeight(float lineHeight);
    void setFormatBuffer(wchar_t*, int);
    void setDrawContext(DrawContext* context);
    void beginDraw();
    void endDraw();
    void printf(const char* format, ...);
    void printf(const wchar_t* format, ...);
   
    void printfWithCalcRect(BoundBox2f*, const wchar_t*, ...);
    
   // void vprintfImpl_(const char*, std::va_list, bool, BoundBox2f*);
    void printfWithCalcRect(BoundBox2f*, const char*, ...);
    void calcFormatStringRect(BoundBox2f*, const wchar_t*, ...);
    void calcFormatStringRect(BoundBox2f*, const char*, ...);
    
    void printImpl_(const wchar_t*, int, bool, BoundBox2f*);
    

public: // these are meant to be private until I reimplement the helper methods
    const Viewport *mViewport;
    const Projection *mProjection; 
    const Camera* mCamera;
    const FontBase *mFont;
    Vector2f mPos;
    Vector2f mScale;
    Color4f mColor;
    f32 mCharSpace;
    f32 mLineSpace;
    const Matrix34f* mModelMatrix;
    f32 mWidthLimit;
    char16* mFormatBuffer;
    s32 mFormatBufferLength;
    bool mIsNeedBeginEnd;
    //void *vtable;
};
static_assert(sizeof(TextWriter) == 0x50, "sead::TextWriter size mismatch");
}  // namespace sead