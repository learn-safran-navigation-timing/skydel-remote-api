#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"


namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetLastHilWarning.
    ///
    /// Name              Type Description
    /// ----------------- ---- -----------------------------------------------------------------------------------------------------------------------------------
    /// IsExtrapolated    bool Indicate if there is receiver position has been extrapolated because of the HIL client that did not send receiver position in time.
    /// ExtrapolationTime int  Time of last extrapolated position
    ///

    class HilWarningResult;
    typedef std::shared_ptr<HilWarningResult> HilWarningResultPtr;
    
    
    class HilWarningResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      HilWarningResult();

      HilWarningResult(bool isExtrapolated, int extrapolationTime);

      HilWarningResult(CommandBasePtr relatedCommand, bool isExtrapolated, int extrapolationTime);

      static HilWarningResultPtr create(bool isExtrapolated, int extrapolationTime);

      static HilWarningResultPtr create(CommandBasePtr relatedCommand, bool isExtrapolated, int extrapolationTime);
      static HilWarningResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isExtrapolated ****
      bool isExtrapolated() const;
      void setIsExtrapolated(bool isExtrapolated);


      // **** extrapolationTime ****
      int extrapolationTime() const;
      void setExtrapolationTime(int extrapolationTime);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(HilWarningResult);
  }
}

