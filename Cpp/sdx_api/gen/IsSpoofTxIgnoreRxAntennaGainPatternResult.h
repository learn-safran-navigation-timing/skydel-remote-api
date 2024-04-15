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
    /// Result of IsSpoofTxIgnoreRxAntennaGainPattern.
    ///
    /// Name   Type   Description
    /// ------ ------ -------------------------------------------------------------
    /// Ignore bool   If true, the receiver's antenna gain pattern will be ignored.
    /// Id     string Transmitter unique identifier.
    ///

    class IsSpoofTxIgnoreRxAntennaGainPatternResult;
    typedef std::shared_ptr<IsSpoofTxIgnoreRxAntennaGainPatternResult> IsSpoofTxIgnoreRxAntennaGainPatternResultPtr;
    
    
    class IsSpoofTxIgnoreRxAntennaGainPatternResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      IsSpoofTxIgnoreRxAntennaGainPatternResult();

      IsSpoofTxIgnoreRxAntennaGainPatternResult(bool ignore, const std::string& id);

      IsSpoofTxIgnoreRxAntennaGainPatternResult(CommandBasePtr relatedCommand, bool ignore, const std::string& id);

      static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr create(bool ignore, const std::string& id);

      static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr create(CommandBasePtr relatedCommand, bool ignore, const std::string& id);
      static IsSpoofTxIgnoreRxAntennaGainPatternResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** ignore ****
      bool ignore() const;
      void setIgnore(bool ignore);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(IsSpoofTxIgnoreRxAntennaGainPatternResult);
  }
}

