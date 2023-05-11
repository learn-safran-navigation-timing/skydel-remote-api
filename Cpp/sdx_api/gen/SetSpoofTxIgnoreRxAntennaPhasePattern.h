#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a spoofer should ignore the receiver's antenna phase pattern.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna phase pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetSpoofTxIgnoreRxAntennaPhasePattern;
    typedef std::shared_ptr<SetSpoofTxIgnoreRxAntennaPhasePattern> SetSpoofTxIgnoreRxAntennaPhasePatternPtr;
    
    
    class SetSpoofTxIgnoreRxAntennaPhasePattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSpoofTxIgnoreRxAntennaPhasePattern();

      SetSpoofTxIgnoreRxAntennaPhasePattern(bool ignore, const std::string& id);

      static SetSpoofTxIgnoreRxAntennaPhasePatternPtr create(bool ignore, const std::string& id);
      static SetSpoofTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

