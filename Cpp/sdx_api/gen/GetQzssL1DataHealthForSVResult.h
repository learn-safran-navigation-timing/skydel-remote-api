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
    /// Result of GetQzssL1DataHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..10, or use 0 to apply new value to all satellites.
    /// Health      int             Data health 0..7
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetQzssL1DataHealthForSVResult;
    typedef std::shared_ptr<GetQzssL1DataHealthForSVResult> GetQzssL1DataHealthForSVResultPtr;
    typedef GetQzssL1DataHealthForSVResult GetQzssSatelliteL1DataHealthResult;
    typedef std::shared_ptr<GetQzssSatelliteL1DataHealthResult> GetQzssSatelliteL1DataHealthResultPtr;
    
    class GetQzssL1DataHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetQzssL1DataHealthForSVResult();

      GetQzssL1DataHealthForSVResult(int svId, int health, const std::optional<std::string>& dataSetName = {});

      GetQzssL1DataHealthForSVResult(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName = {});

      static GetQzssL1DataHealthForSVResultPtr create(int svId, int health, const std::optional<std::string>& dataSetName = {});

      static GetQzssL1DataHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int health, const std::optional<std::string>& dataSetName = {});
      static GetQzssL1DataHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** health ****
      int health() const;
      void setHealth(int health);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetQzssL1DataHealthForSVResult);
  }
}

