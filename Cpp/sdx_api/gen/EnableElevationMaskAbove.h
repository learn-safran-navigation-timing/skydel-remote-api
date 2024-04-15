#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set GNSS satellite mask based on elevation enabled or disabled (See SetElevationMaskAbove).
    ///
    /// Name    Type Description
    /// ------- ---- ------------------------------------------------------------------
    /// Enabled bool If true, mask satellites with elevation angle above masking angle.
    ///

    class EnableElevationMaskAbove;
    typedef std::shared_ptr<EnableElevationMaskAbove> EnableElevationMaskAbovePtr;
    
    
    class EnableElevationMaskAbove : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableElevationMaskAbove();

      EnableElevationMaskAbove(bool enabled);

      static EnableElevationMaskAbovePtr create(bool enabled);
      static EnableElevationMaskAbovePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** enabled ****
      bool enabled() const;
      void setEnabled(bool enabled);
    };
    
  }
}

