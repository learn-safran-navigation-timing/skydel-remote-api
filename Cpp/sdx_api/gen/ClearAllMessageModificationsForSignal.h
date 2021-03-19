#pragma once

#include <memory>
#include "command_base.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Clear the signal for all message modifications.
    ///
    /// Name   Type   Description
    /// ------ ------ -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    /// Signal string Signal key, accepted values : "L1CA", "L1C", "L1P", "L1M", "L2C", "L2P", "L2M", "L5", "G1", "G2", "E1", "E5a", "E5b", "B1", "B2", "B2a", "B1C", "QZSSL1CA", "QZSSL1S" and "NAVICL5"
    ///

    class ClearAllMessageModificationsForSignal;
    typedef std::shared_ptr<ClearAllMessageModificationsForSignal> ClearAllMessageModificationsForSignalPtr;
    
    
    class ClearAllMessageModificationsForSignal : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ClearAllMessageModificationsForSignal();

      ClearAllMessageModificationsForSignal(const std::string& signal);
  
      static ClearAllMessageModificationsForSignalPtr create(const std::string& signal);
      static ClearAllMessageModificationsForSignalPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** signal ****
      std::string signal() const;
      void setSignal(const std::string& signal);
    };
  }
}

