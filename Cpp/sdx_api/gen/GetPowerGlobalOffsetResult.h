#pragma once

#include <memory>
#include "command_result.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetPowerGlobalOffset.
    ///
    /// Name   Type   Description
    /// ------ ------ ---------------------------------------------------
    /// Offset double Offset in dB (negative value will attenuate signal)
    ///

    class GetPowerGlobalOffsetResult;
    typedef std::shared_ptr<GetPowerGlobalOffsetResult> GetPowerGlobalOffsetResultPtr;
    
    
    class GetPowerGlobalOffsetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetPowerGlobalOffsetResult();

      GetPowerGlobalOffsetResult(CommandBasePtr relatedCommand, double offset);
  
      static GetPowerGlobalOffsetResultPtr create(CommandBasePtr relatedCommand, double offset);
      static GetPowerGlobalOffsetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** offset ****
      double offset() const;
      void setOffset(double offset);
    };
  }
}

