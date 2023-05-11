#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set whether the ionospheric offsets grid should be used for SBAS corrections in message 26
    ///
    /// Name      Type Description
    /// --------- ---- --------------------------------------------
    /// IsEnabled bool True if offsets are applied in Sbas messages
    ///

    class ApplyDelayInSbas;
    typedef std::shared_ptr<ApplyDelayInSbas> ApplyDelayInSbasPtr;
    
    
    class ApplyDelayInSbas : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ApplyDelayInSbas();

      ApplyDelayInSbas(bool isEnabled);

      static ApplyDelayInSbasPtr create(bool isEnabled);
      static ApplyDelayInSbasPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** isEnabled ****
      bool isEnabled() const;
      void setIsEnabled(bool isEnabled);
    };
    
  }
}

