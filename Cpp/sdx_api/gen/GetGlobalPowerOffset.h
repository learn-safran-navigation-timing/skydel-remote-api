#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get global power offset default value for all signals and all systems
    ///
    /// 
    ///

    class GetGlobalPowerOffset;
    typedef std::shared_ptr<GetGlobalPowerOffset> GetGlobalPowerOffsetPtr;
    
    
    class GetGlobalPowerOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGlobalPowerOffset();

      static GetGlobalPowerOffsetPtr create();
      static GetGlobalPowerOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;
    };
    
  }
}

