#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.
    ///
    /// 
    ///

    class GetDynamicRangeOffset;
    typedef std::shared_ptr<GetDynamicRangeOffset> GetDynamicRangeOffsetPtr;
    
    
    class GetDynamicRangeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetDynamicRangeOffset();

      static GetDynamicRangeOffsetPtr create();
      static GetDynamicRangeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

