#pragma once

#include <memory>
#include "command_result.h"
#include "command_factory.h"
#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Result of GetModulationTarget.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------------------------------------------------------------
    /// Type            string Target type can be "DTA-2115B", "File", "N310", "None", "NoneRT", "X300" or "Wavefront Controller".
    /// Path            string File path. Optional, use only if type is "File".
    /// Address         string Optional. IP Address if type is "N310" or "X300".
    /// ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is "DTA-2115B", "N310" or "X300".
    /// Id              string Unique identifier automatically set by simulator
    ///

    class GetModulationTargetResult;
    typedef std::shared_ptr<GetModulationTargetResult> GetModulationTargetResultPtr;
    
    
    class GetModulationTargetResult : public CommandResult
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      GetModulationTargetResult();

      GetModulationTargetResult(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);

      GetModulationTargetResult(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);

      static GetModulationTargetResultPtr create(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);

      static GetModulationTargetResultPtr create(CommandBasePtr relatedCommand, const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);
      static GetModulationTargetResultPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;


      // **** type ****
      std::string type() const;
      void setType(const std::string& type);


      // **** path ****
      std::string path() const;
      void setPath(const std::string& path);


      // **** address ****
      std::string address() const;
      void setAddress(const std::string& address);


      // **** clockIsExternal ****
      bool clockIsExternal() const;
      void setClockIsExternal(bool clockIsExternal);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    REGISTER_COMMAND_TO_FACTORY_DECL(GetModulationTargetResult);
  }
}

