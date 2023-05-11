#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clears all SBAS service message region group for this service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ -----------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    ///

    class ClearAllSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<ClearAllSbasServiceMessageRegionGroup> ClearAllSbasServiceMessageRegionGroupPtr;
    
    
    class ClearAllSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllSbasServiceMessageRegionGroup();

      ClearAllSbasServiceMessageRegionGroup(const std::string& serviceProvider);

      static ClearAllSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider);
      static ClearAllSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);
    };
    
  }
}

