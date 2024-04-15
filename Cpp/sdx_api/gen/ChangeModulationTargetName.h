#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Change the modulation target name. The name is only used for display purpose.
    ///
    /// Name       Type   Description
    /// ---------- ------ -----------------
    /// TargetName string New target name
    /// Id         string Target identifier
    ///

    class ChangeModulationTargetName;
    typedef std::shared_ptr<ChangeModulationTargetName> ChangeModulationTargetNamePtr;
    
    
    class ChangeModulationTargetName : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;
      static const char* const TargetId;


      ChangeModulationTargetName();

      ChangeModulationTargetName(const std::string& targetName, const std::string& id);

      static ChangeModulationTargetNamePtr create(const std::string& targetName, const std::string& id);
      static ChangeModulationTargetNamePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;
      virtual const std::vector<std::string>& fieldNames() const override;

      virtual int executePermission() const override;


      // **** targetName ****
      std::string targetName() const;
      void setTargetName(const std::string& targetName);


      // **** id ****
      std::string id() const;
      void setId(const std::string& id);
    };
    
  }
}

