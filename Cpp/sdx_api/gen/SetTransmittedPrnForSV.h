#pragma once

#include <memory>
#include "command_base.h"

#include <map>
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the PRNs transmitted by the SV ID for these signals.
    ///
    /// Name          Type            Description
    /// ------------- --------------- -------------------------------------------------------------------------------
    /// SvId          int             Satellite SV ID.
    /// SignalPrnDict dict string:int A dictionary of signal prn pairs.
    ///                               Accepted keys are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2", "B1C",
    ///                                                  "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB",
    ///                                                  "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S",
    ///                                                  "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL",
    ///                                                  "PULSARX1" and "PULSARX5"
    ///

    class SetTransmittedPrnForSV;
    typedef std::shared_ptr<SetTransmittedPrnForSV> SetTransmittedPrnForSVPtr;
    
    
    class SetTransmittedPrnForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetTransmittedPrnForSV();

      SetTransmittedPrnForSV(int svId, const std::map<std::string, int>& signalPrnDict);

      static SetTransmittedPrnForSVPtr create(int svId, const std::map<std::string, int>& signalPrnDict);
      static SetTransmittedPrnForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalPrnDict ****
      std::map<std::string, int> signalPrnDict() const;
      void setSignalPrnDict(const std::map<std::string, int>& signalPrnDict);
    };
    
  }
}

