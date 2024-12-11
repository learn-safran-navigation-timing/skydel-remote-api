#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get all multipath ID for the specified signal.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5",
    ///                                     "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1",
    ///                                     "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "QZSSL6",
    ///                                     "NAVICL1", "NAVICL5", "NAVICS", "PULSARXL" and "PULSARX1"
    ///

    class GetAllMultipathForSignal;
    typedef std::shared_ptr<GetAllMultipathForSignal> GetAllMultipathForSignalPtr;
    
    
    class GetAllMultipathForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetAllMultipathForSignal();

      GetAllMultipathForSignal(const std::string& signal);

      static GetAllMultipathForSignalPtr create(const std::string& signal);
      static GetAllMultipathForSignalPtr dynamicCast(CommandBasePtr ptr);
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

