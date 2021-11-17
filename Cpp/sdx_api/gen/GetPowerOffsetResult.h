#pragma once

#include <memory>
#include "command_result.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPowerOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5",
    ///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                     "B1", "B2", "B1C", "B2a", "QZSSL1CA", "QZSSL1C",
    ///                                     "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class GetPowerOffsetResult;
    typedef std::shared_ptr<GetPowerOffsetResult> GetPowerOffsetResultPtr;
    
    
    class GetPowerOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerOffsetResult();

      GetPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset);
  
      static GetPowerOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, double offset);
      static GetPowerOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
  }
}

