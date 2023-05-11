#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include "gen/SVDataUpdateMode.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetSVDataUpdateMode.
    ///
    /// Name Type             Description
    /// ---- ---------------- ------------------------------------------------------------------
    /// Mode SVDataUpdateMode SV Data Update Mode:
    ///                       Extrapolation: Skydel extrapolates from the first block (default).
    ///                       Dynamic: Blocks must be pushed during the simulation.
    ///

    class GetSVDataUpdateModeResult;
    typedef std::shared_ptr<GetSVDataUpdateModeResult> GetSVDataUpdateModeResultPtr;
    
    
    class GetSVDataUpdateModeResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetSVDataUpdateModeResult();

      GetSVDataUpdateModeResult(const Sdx::SVDataUpdateMode& mode);

      GetSVDataUpdateModeResult(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode);

      static GetSVDataUpdateModeResultPtr create(const Sdx::SVDataUpdateMode& mode);

      static GetSVDataUpdateModeResultPtr create(CommandBasePtr relatedCommand, const Sdx::SVDataUpdateMode& mode);
      static GetSVDataUpdateModeResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** mode ****
      Sdx::SVDataUpdateMode mode() const;
      void setMode(const Sdx::SVDataUpdateMode& mode);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetSVDataUpdateModeResult);
  }
}

