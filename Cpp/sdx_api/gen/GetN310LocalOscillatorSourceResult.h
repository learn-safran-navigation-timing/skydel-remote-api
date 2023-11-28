#pragma once

#include <memory>
#include "command_result.h"
#include "command_result_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetN310LocalOscillatorSource.
    ///
    /// Name       Type   Description
    /// ---------- ------ -------------------------------------------------------------------------------------------
    /// IsExternal bool   Indicates if the Local Oscillator is external (true) or internal (false). False by default.
    /// Id         string N310 modulation target Id.
    ///

    class GetN310LocalOscillatorSourceResult;
    typedef std::shared_ptr<GetN310LocalOscillatorSourceResult> GetN310LocalOscillatorSourceResultPtr;
    
    
    class GetN310LocalOscillatorSourceResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      GetN310LocalOscillatorSourceResult();

      GetN310LocalOscillatorSourceResult(bool isExternal, const std::string& id);

      GetN310LocalOscillatorSourceResult(CommandBasePtr relatedCommand, bool isExternal, const std::string& id);

      static GetN310LocalOscillatorSourceResultPtr create(bool isExternal, const std::string& id);

      static GetN310LocalOscillatorSourceResultPtr create(CommandBasePtr relatedCommand, bool isExternal, const std::string& id);
      static GetN310LocalOscillatorSourceResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;


      // **** isExternal ****
      bool isExternal() const;
      void setIsExternal(bool isExternal);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_RESULT_TO_FACTORY_DECL(GetN310LocalOscillatorSourceResult);
  }
}

