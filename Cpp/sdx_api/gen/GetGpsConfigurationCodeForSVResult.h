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
    /// Result of GetGpsConfigurationCodeForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- -------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..32
    /// SvConfig    int             SV Config 0..4
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetGpsConfigurationCodeForSVResult;
    typedef std::shared_ptr<GetGpsConfigurationCodeForSVResult> GetGpsConfigurationCodeForSVResultPtr;
    
    
    class GetGpsConfigurationCodeForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGpsConfigurationCodeForSVResult();

      GetGpsConfigurationCodeForSVResult(int svId, int svConfig, const std::optional<std::string>& dataSetName = {});

      GetGpsConfigurationCodeForSVResult(CommandBasePtr relatedCommand, int svId, int svConfig, const std::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationCodeForSVResultPtr create(int svId, int svConfig, const std::optional<std::string>& dataSetName = {});

      static GetGpsConfigurationCodeForSVResultPtr create(CommandBasePtr relatedCommand, int svId, int svConfig, const std::optional<std::string>& dataSetName = {});
      static GetGpsConfigurationCodeForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** svConfig ****
      int svConfig() const;
      void setSvConfig(int svConfig);


      // **** dataSetName ****
      std::optional<std::string> dataSetName() const;
      void setDataSetName(const std::optional<std::string>& dataSetName);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGpsConfigurationCodeForSVResult);
  }
}

