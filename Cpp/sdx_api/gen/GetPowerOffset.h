#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Please note the command GetPowerOffset is deprecated since 21.7. You may use GetSignalPowerOffset.
    /// 
    /// Get power offset default value for the signal given in argument
    ///
    /// Name   Type   Description
    /// ------ ------ ----------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                     "B1", "B2", "B1C", "B2a", "B3I", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C",
    ///                                     "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6", "NAVICL1", "NAVICL5", "NAVICS",
    ///                                     "PULSARXL", "PULSARX1"
    ///

    class GetPowerOffset;
    typedef std::shared_ptr<GetPowerOffset> GetPowerOffsetPtr;
    
    
    class GetPowerOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetPowerOffset();

      GetPowerOffset(const std::string& signal);

      static GetPowerOffsetPtr create(const std::string& signal);
      static GetPowerOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

