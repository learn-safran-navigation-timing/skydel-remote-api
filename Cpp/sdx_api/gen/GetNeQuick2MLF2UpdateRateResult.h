#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetNeQuick2MLF2UpdateRate.
    ///
    /// Name       Type Description
    /// ---------- ---- ----------------------------
    /// UpdateRate int  The update rate, in seconds.
    ///

    class GetNeQuick2MLF2UpdateRateResult;
    typedef std::shared_ptr<GetNeQuick2MLF2UpdateRateResult> GetNeQuick2MLF2UpdateRateResultPtr;
    
    
    class GetNeQuick2MLF2UpdateRateResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetNeQuick2MLF2UpdateRateResult();

      GetNeQuick2MLF2UpdateRateResult(int updateRate);

      GetNeQuick2MLF2UpdateRateResult(CommandBasePtr relatedCommand, int updateRate);

      static GetNeQuick2MLF2UpdateRateResultPtr create(int updateRate);

      static GetNeQuick2MLF2UpdateRateResultPtr create(CommandBasePtr relatedCommand, int updateRate);
      static GetNeQuick2MLF2UpdateRateResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** updateRate ****
      int updateRate() const;
      void setUpdateRate(int updateRate);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetNeQuick2MLF2UpdateRateResult);
  }
}

