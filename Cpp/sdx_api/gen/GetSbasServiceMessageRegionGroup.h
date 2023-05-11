#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get infos about the SBAS service message region group at this index.
    ///
    /// Name            Type   Description
    /// --------------- ------ -----------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// Id              string Unique identifier of the SBAS service message region group.
    ///

    class GetSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<GetSbasServiceMessageRegionGroup> GetSbasServiceMessageRegionGroupPtr;
    
    
    class GetSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSbasServiceMessageRegionGroup();

      GetSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& id);

      static GetSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, const std::string& id);
      static GetSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr);
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

