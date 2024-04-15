#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Get the local oscillator source of the N310. Can be Internal or External. By default, the source is Internal.
    ///
    /// Name Type   Description
    /// ---- ------ --------------------------
    /// Id   string N310 modulation target Id.
    ///

    class GetN310LocalOscillatorSource;
    typedef std::shared_ptr<GetN310LocalOscillatorSource> GetN310LocalOscillatorSourcePtr;
    
    
    class GetN310LocalOscillatorSource : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetN310LocalOscillatorSource();

      GetN310LocalOscillatorSource(const std::string& id);

      static GetN310LocalOscillatorSourcePtr create(const std::string& id);
      static GetN310LocalOscillatorSourcePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

