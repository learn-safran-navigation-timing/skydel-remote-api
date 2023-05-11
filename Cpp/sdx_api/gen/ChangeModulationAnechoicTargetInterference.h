#pragma once

#include <memory>
#include "command_base.h"

#include <string>

namespace Sdx
{
  namespace Cmd
  {
    ///
    /// Assign an output to a specific interference group. This command works only
    /// for Anechoic Chamber target.
    ///
    /// Name        Type   Description
    /// ----------- ------ -------------------------------------------------------------------------------------------
    /// Group       int    Interference group number [1..16]
    /// Output      string Output is radio name and RF output. For example, RF output B on radio 3 is referred as "3B"
    /// CentralFreq double Central frequency (Hz)
    ///

    class ChangeModulationAnechoicTargetInterference;
    typedef std::shared_ptr<ChangeModulationAnechoicTargetInterference> ChangeModulationAnechoicTargetInterferencePtr;
    
    
    class ChangeModulationAnechoicTargetInterference : public CommandBase
    {
    public:
      static const char* const CmdName;
      static const char* const Documentation;


      ChangeModulationAnechoicTargetInterference();

      ChangeModulationAnechoicTargetInterference(int group, const std::string& output, double centralFreq);

      static ChangeModulationAnechoicTargetInterferencePtr create(int group, const std::string& output, double centralFreq);
      static ChangeModulationAnechoicTargetInterferencePtr dynamicCast(CommandBasePtr ptr);
      virtual bool isValid() const override;
      virtual std::string documentation() const override;

      virtual int executePermission() const override;


      // **** group ****
      int group() const;
      void setGroup(int group);


      // **** output ****
      std::string output() const;
      void setOutput(const std::string& output);


      // **** centralFreq ****
      double centralFreq() const;
      void setCentralFreq(double centralFreq);
    };
    
  }
}

