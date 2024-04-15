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
    /// Result of GetGpsL1cHealthForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite's SV ID 1..32, or use 0 to apply new value to all satellites.
    /// Health      bool            L1C health, false = signal OK, true = signal bad or unavailable
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsL1cHealthForSVResult;
    typedef std::shared_ptr<GetGpsL1cHealthForSVResult> GetGpsL1cHealthForSVResultPtr;
    
    
    class GetGpsL1cHealthForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsL1cHealthForSVResult();

      GetGpsL1cHealthForSVResult(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      GetGpsL1cHealthForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsL1cHealthForSVResultPtr create(int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});

      static GetGpsL1cHealthForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const Sdx::optional<std::string>& dataSetName = {});
      static GetGpsL1cHealthForSVResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsL1cHealthForSVResult);
  }
}

