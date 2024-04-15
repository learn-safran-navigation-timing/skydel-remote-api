#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether a spoofer should ignore the receiver's antenna patterns (gain and phase).
    ///
    /// Name   Type   Description
    /// ------ ------ --------------------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna patterns (gain and phase) will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class SetSpoofTxIgnoreRxAntennaPatterns;
    typedef std::shared_ptr<SetSpoofTxIgnoreRxAntennaPatterns> SetSpoofTxIgnoreRxAntennaPatternsPtr;
    
    
    class SetSpoofTxIgnoreRxAntennaPatterns : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetSpoofTxIgnoreRxAntennaPatterns();

      SetSpoofTxIgnoreRxAntennaPatterns(bool ignore, const std::string& id);

      static SetSpoofTxIgnoreRxAntennaPatternsPtr create(bool ignore, const std::string& id);
      static SetSpoofTxIgnoreRxAntennaPatternsPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

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

