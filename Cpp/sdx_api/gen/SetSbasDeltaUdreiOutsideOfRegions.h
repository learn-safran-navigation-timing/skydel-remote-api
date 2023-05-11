#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set SBAS delta UDREI outside all the defined regions for this service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ ----------------------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int    Delta UDREI applicable outside all the defined regions. Accepted range is [0..15].
    ///

    class SetSbasDeltaUdreiOutsideOfRegions;
    typedef std::shared_ptr<SetSbasDeltaUdreiOutsideOfRegions> SetSbasDeltaUdreiOutsideOfRegionsPtr;
    
    
    class SetSbasDeltaUdreiOutsideOfRegions : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasDeltaUdreiOutsideOfRegions();

      SetSbasDeltaUdreiOutsideOfRegions(const std::string& serviceProvider, int deltaUdrei);

      static SetSbasDeltaUdreiOutsideOfRegionsPtr create(const std::string& serviceProvider, int deltaUdrei);
      static SetSbasDeltaUdreiOutsideOfRegionsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** deltaUdrei ****
      int deltaUdrei() const;
      void setDeltaUdrei(int deltaUdrei);
    };
    
  }
}

