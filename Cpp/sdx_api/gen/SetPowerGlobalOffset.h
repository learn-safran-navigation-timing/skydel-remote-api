#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command SetPowerGlobalOffset is deprecated since 21.7. You may use SetGlobalPowerOffset.
    /// 
    /// Set global power offset default value for all signals and all systems
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class SetPowerGlobalOffset;
    typedef std::shared_ptr<SetPowerGlobalOffset> SetPowerGlobalOffsetPtr;
    
    
    class SetPowerGlobalOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetPowerGlobalOffset();

      SetPowerGlobalOffset(double offset);

      static SetPowerGlobalOffsetPtr create(double offset);
      static SetPowerGlobalOffsetPtr dynamicCast(CommandBasePtr ptr);
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

