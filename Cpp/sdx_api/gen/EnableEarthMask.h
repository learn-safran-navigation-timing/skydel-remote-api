#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Enable (or disable) the Earth mask.
    ///
    /// Name    Type Description
    /// ------- ---- ----------------------------------------------------------------------------------------------
    /// Enabled bool If disabled, all satellites will be visible, thereby eliminating the Earth's occlusion effect.
    ///

    class EnableEarthMask;
    typedef std::shared_ptr<EnableEarthMask> EnableEarthMaskPtr;
    
    
    class EnableEarthMask : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableEarthMask();

      EnableEarthMask(bool enabled);

      static EnableEarthMaskPtr create(bool enabled);
      static EnableEarthMaskPtr dynamicCast(CommandBasePtr ptr);
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

