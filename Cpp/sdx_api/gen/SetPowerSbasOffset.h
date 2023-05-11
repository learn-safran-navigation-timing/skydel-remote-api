#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set power offset default value for the SBAS Service Provider given in argument
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------
    /// ServiceProvider string Service Provider key, allowed values: "WAAS", "EGNOS", "MSAS", "GAGAN", "SDCM"
    /// Offset          double Offset in dB (negative value will attenuate signal)
    ///

    class SetPowerSbasOffset;
    typedef std::shared_ptr<SetPowerSbasOffset> SetPowerSbasOffsetPtr;
    
    
    class SetPowerSbasOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetPowerSbasOffset();

      SetPowerSbasOffset(const std::string& serviceProvider, double offset);

      static SetPowerSbasOffsetPtr create(const std::string& serviceProvider, double offset);
      static SetPowerSbasOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    
  }
}

