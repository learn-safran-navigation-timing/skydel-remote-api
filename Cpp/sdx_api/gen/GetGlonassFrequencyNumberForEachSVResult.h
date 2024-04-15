#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetGlonassFrequencyNumberForEachSV
    ///
    /// Name            Type      Description
    /// --------------- --------- --------------------------------------------------------------------------------------------------
    /// FrequencyNumber array int Frequency number of each satellite. Zero based index (index 0 => SV ID 1, index 1 => SV ID 2, etc)
    ///

    class GetGlonassFrequencyNumberForEachSVResult;
    typedef std::shared_ptr<GetGlonassFrequencyNumberForEachSVResult> GetGlonassFrequencyNumberForEachSVResultPtr;
    
    
    class GetGlonassFrequencyNumberForEachSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetGlonassFrequencyNumberForEachSVResult();

      GetGlonassFrequencyNumberForEachSVResult(const std::vector<int>& frequencyNumber);

      GetGlonassFrequencyNumberForEachSVResult(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber);

      static GetGlonassFrequencyNumberForEachSVResultPtr create(const std::vector<int>& frequencyNumber);

      static GetGlonassFrequencyNumberForEachSVResultPtr create(CommandBasePtr relatedCommand, const std::vector<int>& frequencyNumber);
      static GetGlonassFrequencyNumberForEachSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** frequencyNumber ****
      std::vector<int> frequencyNumber() const;
      void setFrequencyNumber(const std::vector<int>& frequencyNumber);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetGlonassFrequencyNumberForEachSVResult);
  }
}

