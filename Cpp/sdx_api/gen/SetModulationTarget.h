#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Set a modulation target.
    /// If Id is not set, or if new, a new target is added.
    /// For setter : If the Id is already used, the corresponding target is updated.
    ///
    /// Name            Type   Description
    /// --------------- ------ ------------------------------------------------------------------------------------------------------------------------------------
    /// Type            string Target type can be "DTA-2115B", "File", "N310", "None", "NoneRT", "X300" or "Wavefront Controller".
    /// Path            string File path. Optional, use only if type is "File".
    /// Address         string Optional. IP Address if type is "N310" or "X300".
    /// ClockIsExternal bool   Indicate 10 MHz reference clock is external (true) or internal (false). Optional, use only if type is "DTA-2115B", "N310" or "X300".
    /// Id              string Unique identifier automatically set by simulator
    ///

    class SetModulationTarget;
    typedef std::shared_ptr<SetModulationTarget> SetModulationTargetPtr;
    
    
    class SetModulationTarget : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      SetModulationTarget();

      SetModulationTarget(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);

      static SetModulationTargetPtr create(const std::string& type, const std::string& path, const std::string& address, bool clockIsExternal, const std::string& id);
      static SetModulationTargetPtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


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
    
  }
}

