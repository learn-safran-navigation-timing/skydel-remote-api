#pragma once

#include <memory>
#include "command_base.h"

#include <string>
#include <vector>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the PRNs transmitted by the SV ID for these signals.
    ///
    /// Name        Type         Description
    /// ----------- ------------ ---------------------------------------------------------------------------
    /// SvId        int          Satellite SV ID.
    /// SignalArray array string An array of signals.
    ///                          Accepted values are: "L1CA", "L1C", "L2C", "L5", "E1", "E6BC", "B1", "B2",
    ///                                               "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA",
    ///                                               "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S",
    ///                                               "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5" and "NAVICS"
    ///

    class GetTransmittedPrnForSV;
    typedef std::shared_ptr<GetTransmittedPrnForSV> GetTransmittedPrnForSVPtr;
    
    
    class GetTransmittedPrnForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetTransmittedPrnForSV();

      GetTransmittedPrnForSV(int svId, const std::vector<std::string>& signalArray);

      static GetTransmittedPrnForSVPtr create(int svId, const std::vector<std::string>& signalArray);
      static GetTransmittedPrnForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** svId ****
      int svId() const;
      void setSvId(int svId);


      // **** signalArray ****
      std::vector<std::string> signalArray() const;
      void setSignalArray(const std::vector<std::string>& signalArray);
    };
    
  }
}

