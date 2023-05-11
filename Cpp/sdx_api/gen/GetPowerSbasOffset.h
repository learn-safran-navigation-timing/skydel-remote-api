#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get power offset default value for the SBAS Service Provider given in argument
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------
    /// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
    ///

    class GetPowerSbasOffset;
    typedef std::shared_ptr<GetPowerSbasOffset> GetPowerSbasOffsetPtr;
    
    
    class GetPowerSbasOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerSbasOffset();

      GetPowerSbasOffset(const std::string& serviceProvider);

      static GetPowerSbasOffsetPtr create(const std::string& serviceProvider);
      static GetPowerSbasOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);
    };
    
  }
}

