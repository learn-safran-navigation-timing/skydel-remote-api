#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <optional>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetQzssL2HealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      bool            L2 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL2HealthForSVResult;
    typedef std::shared_ptr<GetQzssL2HealthForSVResult> GetQzssL2HealthForSVResultPtr;
    typedef GetQzssL2HealthForSVResult GetQzssSatelliteL2HealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL2HealthResult> GetQzssSatelliteL2HealthResultPtr;
    
    class GetQzssL2HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetQzssL2HealthForSVResult();

      GetQzssL2HealthForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      GetQzssL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetQzssL2HealthForSVResultPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetQzssL2HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static GetQzssL2HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      bool health() const;
      void setHealth(bool health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL2HealthForSVResult);
  }
}

