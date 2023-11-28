#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.
    ///
    /// Name       Type   Description
    /// ---------- ------ -------------------------------------------------------------------------------------------
    /// IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.
    /// Id         string N310 modulation target Id.
    ///

    class SetN310LocalOscillatorSource;
    typedef std::shared_ptr<SetN310LocalOscillatorSource> SetN310LocalOscillatorSourcePtr;
    
    
    class SetN310LocalOscillatorSource : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      SetN310LocalOscillatorSource();

      SetN310LocalOscillatorSource(bool isExternal, const std::string& id);

      static SetN310LocalOscillatorSourcePtr create(bool isExternal, const std::string& id);
      static SetN310LocalOscillatorSourcePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** isExternal ****
      bool isExternal() const;
      void setIsExternal(bool isExternal);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

