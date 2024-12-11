#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSignalPowerOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                     "B1", "B2", "B1C", "B2a", "B3I", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C",
    ///                                     "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
    ///                                     "PULSARXL", "PULSARX1"
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class GetSignalPowerOffsetResult;
    typedef std::shared_ptr<GetSignalPowerOffsetResult> GetSignalPowerOffsetResultPtr;
    typedef GetSignalPowerOffsetResult GetPowerOffsetResult;
    typedef std::shared_ptr<GetPowerOffsetResult> GetPowerOffsetResultPtr;
    
    class GetSignalPowerOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetSignalPowerOffsetResult();

      GetSignalPowerOffsetResult(const std::string& signal, double offset);

      GetSignalPowerOffsetResult(CommandBasePtr relatedCommand, const std::string& signal, double offset);

      static GetSignalPowerOffsetResultPtr create(const std::string& signal, double offset);

      static GetSignalPowerOffsetResultPtr create(CommandBasePtr relatedCommand, const std::string& signal, double offset);
      static GetSignalPowerOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetSignalPowerOffsetResult);
  }
}

