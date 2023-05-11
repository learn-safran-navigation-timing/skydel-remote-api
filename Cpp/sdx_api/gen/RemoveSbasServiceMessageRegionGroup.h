#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Removes a SBAS service message region group for the service provider.
    ///
    /// Name            Type   Description
    /// --------------- ------ -----------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// Id              string Unique identifier of the SBAS service message region group to remove.
    ///

    class RemoveSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<RemoveSbasServiceMessageRegionGroup> RemoveSbasServiceMessageRegionGroupPtr;
    
    
    class RemoveSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveSbasServiceMessageRegionGroup();

      RemoveSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id);

      static RemoveSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, const std::string& id);
      static RemoveSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

