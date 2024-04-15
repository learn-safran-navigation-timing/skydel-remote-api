#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "gen/SbasServiceMessageRegion.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSbasServiceMessageRegionGroup.
    ///
    /// Name            Type                           Description
    /// --------------- ------------------------------ ---------------------------------------------------------------------------------
    /// ServiceProvider string                         Service providers, accepts "WAAS", "EGNOS", "MSAS", "GAGAN" and "SDCM".
    /// DeltaUdrei      int                            Delta UDREI applicable inside the defined regions. Accepted range is [0..15].
    /// PriorityCode    int                            Priority code of the SBAS service message region group. Accepted range is [0..3].
    /// Regions         array SbasServiceMessageRegion Array of SBAS service message regions. Accepted size range is [1..5].
    /// Id              string                         Unique identifier of the SBAS service message region group.
    ///

    class GetSbasServiceMessageRegionGroupResult;
    typedef std::shared_ptr<GetSbasServiceMessageRegionGroupResult> GetSbasServiceMessageRegionGroupResultPtr;
    
    
    class GetSbasServiceMessageRegionGroupResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSbasServiceMessageRegionGroupResult();

      GetSbasServiceMessageRegionGroupResult(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);

      GetSbasServiceMessageRegionGroupResult(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);

      static GetSbasServiceMessageRegionGroupResultPtr create(const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);

      static GetSbasServiceMessageRegionGroupResultPtr create(CommandBasePtr relatedCommand, const std::string& serviceProvider, int deltaUdrei, int priorityCode, const std::vector<Sdx::SbasServiceMessageRegion>& regions, const std::string& id);
      static GetSbasServiceMessageRegionGroupResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSbasServiceMessageRegionGroupResult);
  }
}

