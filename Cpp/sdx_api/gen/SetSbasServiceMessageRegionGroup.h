#pragma once

#include <memory>
#include "command_base.h"

#include "gen/SbasServiceMessageRegion.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set (or Modify) a SBAS service message region group.
    ///
    /// Name            Type                           Description
    /// --------------- ------------------------------ ---------------------------------------------------------------------------------
    /// ServiceProvider string                         Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].
    /// PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].
    /// Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].
    /// Id              string                         Unique identifier of the SBAS service message region group.
    ///

    class SetSbasServiceMessageRegionGroup;
    typedef std::shared_ptr<SetSbasServiceMessageRegionGroup> SetSbasServiceMessageRegionGroupPtr;
    
    
    class SetSbasServiceMessageRegionGroup : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSbasServiceMessageRegionGroup();

      SetSbasServiceMessageRegionGroup(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);

      static SetSbasServiceMessageRegionGroupPtr create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);
      static SetSbasServiceMessageRegionGroupPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** serviceProvider ****
      std::string serviceProvider() const;
      void setServiceProvider(const std::string& serviceProvider);


      // **** deltaUdrei ****
      int deltaUdrei() const;
      void setDeltaUdrei(int deltaUdrei);


      // **** priorityCode ****
      int priorityCode() const;
      void setPriorityCode(int priorityCode);


      // **** regions ****
      std::vector<Sdx::SbasServiceMessageRegion> regions() const;
      void setRegions(const std::vector<Sdx::SbasServiceMessageRegion>& regions);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

