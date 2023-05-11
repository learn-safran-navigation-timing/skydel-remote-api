#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskBelow).
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle below masking angle.
    ///

    class EnableElevationMaskBelow;
    typedef std::shared_ptr<EnableElevationMaskBelow> EnableElevationMaskBelowPtr;
    
    
    class EnableElevationMaskBelow : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      EnableElevationMaskBelow();

      EnableElevationMaskBelow(bool enabled);

      static EnableElevationMaskBelowPtr create(bool enabled);
      static EnableElevationMaskBelowPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

