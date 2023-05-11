#pragma once

#include <memory>
#include "command_base.h"

#include "gen/SVDataUpdateMode.h"

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the SV Data Update Mode.
    ///
    /// Name Type             Description
    /// ---- ---------------- ------------------------------------------------------------------
    /// Mode SVDataUpdateMode SV Data Update Mode:
    ///                       Extrapolation: Skydel extrapolates from the first block (default).
    ///                       Dynamic: Blocks must be pushed during the simulation.
    ///

    class SetSVDataUpdateMode;
    typedef std::shared_ptr<SetSVDataUpdateMode> SetSVDataUpdateModePtr;
    
    
    class SetSVDataUpdateMode : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetSVDataUpdateMode();

      SetSVDataUpdateMode(const Sdx::SVDataUpdateMode& mode);

      static SetSVDataUpdateModePtr create(const Sdx::SVDataUpdateMode& mode);
      static SetSVDataUpdateModePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** mode ****
      Sdx::SVDataUpdateMode mode() const;
      void setMode(const Sdx::SVDataUpdateMode& mode);
    };
    
  }
}

