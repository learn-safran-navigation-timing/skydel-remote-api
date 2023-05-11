#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Tells if the signal is enabled or disabled for each satellite.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                     "G1", "G2", "E1", "E1PRS", "E5a", "E5b", "E6BC", "E6PRS",
    ///                                     "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "SBASL5", "QZSSL1CA",
    ///                                     "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5"
    ///

    class IsSignalEnabledForEachSV;
    typedef std::shared_ptr<IsSignalEnabledForEachSV> IsSignalEnabledForEachSVPtr;
    
    
    class IsSignalEnabledForEachSV : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      IsSignalEnabledForEachSV();

      IsSignalEnabledForEachSV(const std::string& signal);

      static IsSignalEnabledForEachSVPtr create(const std::string& signal);
      static IsSignalEnabledForEachSVPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
    
  }
}

