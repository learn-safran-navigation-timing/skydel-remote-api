
#include "gen/ChangeModulationAnechoicTargetInterference.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of ChangeModulationAnechoicTargetInterference
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const ChangeModulationAnechoicTargetInterference::CmdName = "ChangeModulationAnechoicTargetInterference";
    const char* const ChangeModulationAnechoicTargetInterference::Documentation = "Assign an output to a specific interference group. This command works only\nfor Anechoic Chamber target.";

    REGISTER_COMMAND_FACTORY(ChangeModulationAnechoicTargetInterference);


    ChangeModulationAnechoicTargetInterference::ChangeModulationAnechoicTargetInterference()
      : CommandBase(CmdName)
    {}

    ChangeModulationAnechoicTargetInterference::ChangeModulationAnechoicTargetInterference(int group, const std::string& output, double centralFreq)
      : CommandBase(CmdName)
    {

      setGroup(group);
      setOutput(output);
      setCentralFreq(centralFreq);
    }

    ChangeModulationAnechoicTargetInterferencePtr ChangeModulationAnechoicTargetInterference::create(int group, const std::string& output, double centralFreq)
    {
      return std::make_shared<ChangeModulationAnechoicTargetInterference>(group, output, centralFreq);
    }

    ChangeModulationAnechoicTargetInterferencePtr ChangeModulationAnechoicTargetInterference::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<ChangeModulationAnechoicTargetInterference>(ptr);
    }

    bool ChangeModulationAnechoicTargetInterference::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Group"])
          && parse_json<std::string>::is_valid(m_values["Output"])
          && parse_json<double>::is_valid(m_values["CentralFreq"])
        ;

    }

    std::string ChangeModulationAnechoicTargetInterference::documentation() const { return Documentation; }


    int ChangeModulationAnechoicTargetInterference::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int ChangeModulationAnechoicTargetInterference::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void ChangeModulationAnechoicTargetInterference::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string ChangeModulationAnechoicTargetInterference::output() const
    {
      return parse_json<std::string>::parse(m_values["Output"]);
    }

    void ChangeModulationAnechoicTargetInterference::setOutput(const std::string& output)
    {
      m_values.AddMember("Output", parse_json<std::string>::format(output, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double ChangeModulationAnechoicTargetInterference::centralFreq() const
    {
      return parse_json<double>::parse(m_values["CentralFreq"]);
    }

    void ChangeModulationAnechoicTargetInterference::setCentralFreq(double centralFreq)
    {
      m_values.AddMember("CentralFreq", parse_json<double>::format(centralFreq, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
