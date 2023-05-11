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
    /// Get the power information for the specified satellite.
    ///
    /// Name        Type         Description
    /// ----------- ------------ -------------------------------------------------------------------------------
    /// System      string       "GPS", "GLONASS", "Galileo", "BeiDou", "SBAS", "QZSS" or "NavIC".
    /// SvId        int          The Satellite's SV ID.
    /// SignalArray array string An array of signals.
    ///                          Accepted values are: "All", "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P",
    ///                                               "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E1PRS", "E5a",
    ///                                               "E5b", "E6BC", "E6PRS", "B1", "B2", "B1C", "B2a", "B3I",
    ///                                               "SBASL1", "SBASL5", "QZSSL1CA", "QZSSL1CB", "QZSSL1C",
    ///                                               "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S" and "NAVICL5"
    ///

    class GetAllPowerForSV;
    typedef std::shared_ptr<GetAllPowerForSV> GetAllPowerForSVPtr;
    
    
    class GetAllPowerForSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetAllPowerForSV();

      GetAllPowerForSV(const std::string& system, int svId, const std::vector<std::string>& signalArray);

      static GetAllPowerForSVPtr create(const std::string& system, int svId, const std::vector<std::string>& signalArray);
      static GetAllPowerForSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


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
    
  }
}

