#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include "sdx_optional.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGpsL2HealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// Health      bool            L2 health, false = signal OK, true = signal bad or unavailable
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsL2HealthForSVResult;
    typedef std::shared_ptr<GetGpsL2HealthForSVResult> GetGpsL2HealthForSVResultPtr;
    
    
    class GetGpsL2HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsL2HealthForSVResult();

      GetGpsL2HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsL2HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsL2HealthForSVResultPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsL2HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsL2HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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
      Sdx::optional<std::string> dataSetName() const;
      void setDataSetName(const Sdx::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsL2HealthForSVResult);
  }
}

