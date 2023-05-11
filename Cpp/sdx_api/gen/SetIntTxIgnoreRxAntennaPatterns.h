#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a dynamic transmitter should ignore the vehicle's antenna patterns (gain and phase).
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------------------
    /// Ignore bool   If true, the vehicle's antenna patterns (gain and phase) will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetIntTxIgnoreRxAntennaPatterns;
    typedef std::shared_ptr<SetIntTxIgnoreRxAntennaPatterns> SetIntTxIgnoreRxAntennaPatternsPtr;
    
    
    class SetIntTxIgnoreRxAntennaPatterns : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetIntTxIgnoreRxAntennaPatterns();

      SetIntTxIgnoreRxAntennaPatterns(bool ignore, const std::string& id);

      static SetIntTxIgnoreRxAntennaPatternsPtr create(bool ignore, const std::string& id);
      static SetIntTxIgnoreRxAntennaPatternsPtr dynamicCast(CommandBasePtr ptr);
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

