#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetEnabledSignalsForSV.
    ///
    /// Name        Type         Description
    /// ----------- ------------ ------------------------------------------------------------------------------------
    /// System      string       The system, can be "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// SvId        int          The satellite SV ID.
    /// SignalArray array string The list of enabled signals.
    ///

    class GetEnabledSignalsForSVResult;
    typedef std::shared_ptr<GetEnabledSignalsForSVResult> GetEnabledSignalsForSVResultPtr;
    
    
    class GetEnabledSignalsForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetEnabledSignalsForSVResult();

      GetEnabledSignalsForSVResult(const std::string& system, int svId, const std::vector<std::string>& signalArray);

      GetEnabledSignalsForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray);

      static GetEnabledSignalsForSVResultPtr create(const std::string& system, int svId, const std::vector<std::string>& signalArray);

      static GetEnabledSignalsForSVResultPtr create(CommandBasePtr relatedCommand, const std::string& system, int svId, const std::vector<std::string>& signalArray);
      static GetEnabledSignalsForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** system ****
      std::string system() const;
      void setSystem(const std::string& system);


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetEnabledSignalsForSVResult);
  }
}

