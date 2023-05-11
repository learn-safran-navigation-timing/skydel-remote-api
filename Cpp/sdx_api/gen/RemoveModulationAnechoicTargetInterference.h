#pragma once

#include <memory>
#include "command_base.h"



namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Remove output assignation. This command works only for Anechoic Chamber
    /// target.
    ///
    /// Name  Type Description
    /// ----- ---- ---------------------------------
    /// Group int  Interference group number [1..16]
    ///

    class RemoveModulationAnechoicTargetInterference;
    typedef std::shared_ptr<RemoveModulationAnechoicTargetInterference> RemoveModulationAnechoicTargetInterferencePtr;
    
    
    class RemoveModulationAnechoicTargetInterference : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      RemoveModulationAnechoicTargetInterference();

      RemoveModulationAnechoicTargetInterference(int group);

      static RemoveModulationAnechoicTargetInterferencePtr create(int group);
      static RemoveModulationAnechoicTargetInterferencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** group ****
      int group() const;
      void setGroup(int group);
    };
    
  }
}

