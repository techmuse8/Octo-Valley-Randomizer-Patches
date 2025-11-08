
//#include <cafe.h>

#pragma once
#include <filedevice/seadFileDevice.h>
#include <filedevice/seadFileDeviceMgr.h>
#include <prim/seadRuntimeTypeInfo.h>
#include <prim/seadSafeString.h>

namespace sead {
class CafeSaveFileDevice : public FileDevice

{
  public:
  u32 field1_0x54;
  u32 field2_0x58;
  u32 field3_0x5c;
  u32 field4_0x60;
  u32 field5_0x64;
  u8 field6_0x68;
  u8 field7_0x69[3];

  static u32 tryFlush(CafeSaveFileDevice* device);
};
} //namespace sead