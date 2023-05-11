#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a dynamic transmitter should ignore the receiver's antenna phase pattern.
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna phase pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnoreRxAntennaPhasePattern;
    typedef std::shared_ptr<SetIntTxIgnoreRxAntennaPhasePattern> SetIntTxIgnoreRxAntennaPhasePatternPtr;
    
    
    class SetIntTxIgnoreRxAntennaPhasePattern : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxIgnoreRxAntennaPhasePattern();

      SetIntTxIgnoreRxAntennaPhasePattern(bool ignore, const std::string& id);

      static SetIntTxIgnoreRxAntennaPhasePatternPtr create(bool ignore, const std::string& id);
      static SetIntTxIgnoreRxAntennaPhasePatternPtr dynamicCast(CommandBasePtr ptr);
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

