#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Disable all multipath in all satellites but only for the specified signal.
    ///
    /// Name   Type   Description
    /// ------ ------ ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Accepted signal keys: "L1CA", "L1C", "L1P", "L1ME", "L1MR", "L2C", "L2P", "L2ME", "L2MR", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B1C", "B2a", "B3I", "SBASL1", "QZSSL1CA", "QZSSL1CB", "QZSSL1C", "QZSSL2C", "QZSSL5", "QZSSL1S", "QZSSL5S", "NAVICL5", "PULSARXL"
    /// Reset  bool   Reset attributes (PSR offset, power loss, Doppler shift and carrier phase offset are set to zero)
    ///

    class RemoveAllMultipathForSignal;
    typedef std::shared_ptr<RemoveAllMultipathForSignal> RemoveAllMultipathForSignalPtr;
    
    
    class RemoveAllMultipathForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      RemoveAllMultipathForSignal();

      RemoveAllMultipathForSignal(const std::string& signal, bool reset);

      static RemoveAllMultipathForSignalPtr create(const std::string& signal, bool reset);
      static RemoveAllMultipathForSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);


      // **** reset ****
      bool reset() const;
      void setReset(bool reset);
    };
    
  }
}

