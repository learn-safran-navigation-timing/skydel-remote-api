#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set global power offset default value for all signals and all systems
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class SetGlobalPowerOffset;
    typedef std::shared_ptr<SetGlobalPowerOffset> SetGlobalPowerOffsetPtr;
    
    
    class SetGlobalPowerOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetGlobalPowerOffset();

      SetGlobalPowerOffset(double offset);

      static SetGlobalPowerOffsetPtr create(double offset);
      static SetGlobalPowerOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    
  }
}

