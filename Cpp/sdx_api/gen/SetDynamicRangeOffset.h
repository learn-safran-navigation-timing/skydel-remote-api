#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the GNSS dynamic range offset. Changing this value shifts the dynamic power range available for GNSS signals. Increasing this value allows to simulate higher power signals and avoid IQ overflows. The range of the satellite power sliders in the Constellation tab is shifted by this offset.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------
    /// Offset double Dynamic Range Offset (dB). Value must be between -10 and +45 dB.
    ///

    class SetDynamicRangeOffset;
    typedef std::shared_ptr<SetDynamicRangeOffset> SetDynamicRangeOffsetPtr;
    
    
    class SetDynamicRangeOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetDynamicRangeOffset();

      SetDynamicRangeOffset(double offset);

      static SetDynamicRangeOffsetPtr create(double offset);
      static SetDynamicRangeOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    
  }
}

