#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetTransmittedPrnForSV.
    ///
    /// Name          Type            Description
    /// ------------- --------------- -------------------------------------------------------------------------------
    /// SvId          int             Satellite SV ID.
    /// SignalPrnDict dict string:int A dictionary of signal prn pairs.
    ///                               Accepted keys are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C",
    ///                                                  "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
    ///                                                  "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S",
    ///                                                  "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL" and
    ///                                                  "PULSARX1"
    ///

    class GetTransmittedPrnForSVResult;
    typedef std::shared_ptr<GetTransmittedPrnForSVResult> GetTransmittedPrnForSVResultPtr;
    
    
    class GetTransmittedPrnForSVResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetTransmittedPrnForSVResult();

      GetTransmittedPrnForSVResult(int svId, const std::map<std::string, int>& signalPrnDict);

      GetTransmittedPrnForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict);

      static GetTransmittedPrnForSVResultPtr create(int svId, const std::map<std::string, int>& signalPrnDict);

      static GetTransmittedPrnForSVResultPtr create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict);
      static GetTransmittedPrnForSVResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalPrnDict ****
      std::map<std::string, int> signalPrnDict() const;
      void setSignalPrnDict(const std::map<std::string, int>& signalPrnDict);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetTransmittedPrnForSVResult);
  }
}

