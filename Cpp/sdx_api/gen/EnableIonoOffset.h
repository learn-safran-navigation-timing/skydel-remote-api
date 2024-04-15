#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the ionospheric offsets grid should be applied to the ionosphere
    ///
    /// Name      Type Description
    /// --------- ---- ---------------------------------------------
    /// IsEnabled bool True if offsets are applied on the ionosphere
    ///

    class EnableIonoOffset;
    typedef std::shared_ptr<EnableIonoOffset> EnableIonoOffsetPtr;
    
    
    class EnableIonoOffset : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      EnableIonoOffset();

      EnableIonoOffset(bool isEnabled);

      static EnableIonoOffsetPtr create(bool isEnabled);
      static EnableIonoOffsetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    
  }
}

