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
    /// Result of GetNavICL5HealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..14, or use 0 to apply new value to all satellites.
    /// Health      bool            L5 health, false = signal OK, true = signal bad
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetNavICL5HealthForSVResult;
    typedef std::shared_ptr<GetNavICL5HealthForSVResult> GetNavICL5HealthForSVResultPtr;
    typedef GetNavICL5HealthForSVResult GetNavICSatelliteL5HealthResult;
    typedef std::shared_ptr<GetNavICSatelliteL5HealthResult> GetNavICSatelliteL5HealthResultPtr;
    
    class GetNavICL5HealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNavICL5HealthForSVResult();

      GetNavICL5HealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      GetNavICL5HealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICL5HealthForSVResultPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetNavICL5HealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static GetNavICL5HealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNavICL5HealthForSVResult);
  }
}

