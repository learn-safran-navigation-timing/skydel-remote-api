#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Swaps 2 SBAS service message region group.
    ///
    /// Name            Type   Description
    /// --------------- ------ ---------------------------------------------------------------------------------
    /// ServiceProvider string Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// FirstId         string Unique identifier of the SBAS service message region group to swap with SecondId.
    /// SecondId        string Unique identifier of the SBAS service message region group to swap with FirstId.
    ///

    class SwapSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<SwapSbasServiceMessageRegionGroup> SwapSbasServiceMessageRegionGroupPtr;
    
    
    class SwapSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SwapSbasServiceMessageRegionGroup();

      SwapSbasServiceMessageRegionGroup(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId);

      static SwapSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, const std::string& firstId, const std::string& secondId);
      static SwapSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** firstId ****
      std::string firstId() const;
      void setFirstId(const std::string& firstId);


      // **** secondId ****
      std::string secondId() const;
      void setSecondId(const std::string& secondId);
    };
    
  }
}

