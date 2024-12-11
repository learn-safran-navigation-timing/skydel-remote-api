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
    /// Result of GetPulsarX5AccuracyIntegrityForSV.
    ///
    /// Name        Type            Description
    /// ----------- --------------- ---------------------------------------------------------------------------------------------------------------------------------
    /// SvId        int             Satellite SV ID 1..258, or use 0 to apply new value to all satellites.
    /// Health      bool            X5 accuracy integrity, false = User Range Error exceeds alarm threshold, true = User Range Error does not exceed alarm threshold.
    /// DataSetName optional string Optional name of the data set to use. If no value is provided, the active data set is used.
    ///

    class GetPulsarX5AccuracyIntegrityForSVResult;
    typedef std::shared_ptr<GetPulsarX5AccuracyIntegrityForSVResult> GetPulsarX5AccuracyIntegrityForSVResultPtr;
    
    
    class GetPulsarX5AccuracyIntegrityForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPulsarX5AccuracyIntegrityForSVResult();

      GetPulsarX5AccuracyIntegrityForSVResult(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      GetPulsarX5AccuracyIntegrityForSVResult(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetPulsarX5AccuracyIntegrityForSVResultPtr create(int svId, bool health, const std::optional<std::string>& dataSetName = {});

      static GetPulsarX5AccuracyIntegrityForSVResultPtr create(CommandBasePtr relatedCommand, int svId, bool health, const std::optional<std::string>& dataSetName = {});
      static GetPulsarX5AccuracyIntegrityForSVResultPtr dynamicCast(CommandBasePtr ptr);
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
    REGISTER_COMMAND_TO_FACTORY_DECL(GetPulsarX5AccuracyIntegrityForSVResult);
  }
}

