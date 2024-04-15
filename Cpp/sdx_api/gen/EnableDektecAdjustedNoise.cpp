
#include "EnableDektecAdjustedNoise.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of EnableDektecAdjustedNoise
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const EnableDektecAdjustedNoise::CmdName = "EnableDektecAdjustedNoise";
    const char* const EnableDektecAdjustedNoise::Documentation = "Adjusts the Advanced Jammer IQ data amplitude on the Dektec output by adding noise to ensure power level linearity on weak jammer signals. Note that enabling this option will increase the noise observed at the RF output for all jammer signal power levels.\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- ----------------------------------------------------------------\n"
      "Enable bool True to enable Advance Jammer noise adjustment on Dektec output.";
    const char* const EnableDektecAdjustedNoise::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(EnableDektecAdjustedNoise);
    REGISTER_COMMAND_TO_FACTORY_IMPL(EnableDektecAdjustedNoise);


    EnableDektecAdjustedNoise::EnableDektecAdjustedNoise()
      : CommandBase(CmdName, TargetId)
    {}

    EnableDektecAdjustedNoise::EnableDektecAdjustedNoise(bool enable)
      : CommandBase(CmdName, TargetId)
    {

      setEnable(enable);
    }

    EnableDektecAdjustedNoisePtr EnableDektecAdjustedNoise::create(bool enable)
    {
      return std::make_shared<EnableDektecAdjustedNoise>(enable);
    }

    EnableDektecAdjustedNoisePtr EnableDektecAdjustedNoise::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<EnableDektecAdjustedNoise>(ptr);
    }

    bool EnableDektecAdjustedNoise::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enable"])
        ;

    }

    std::string EnableDektecAdjustedNoise::documentation() const { return Documentation; }

    const std::vector<std::string>& EnableDektecAdjustedNoise::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enable"}; 
      return names; 
    }


    int EnableDektecAdjustedNoise::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    bool EnableDektecAdjustedNoise::enable() const
    {
      return parse_json<bool>::parse(m_values["Enable"]);
    }

    void EnableDektecAdjustedNoise::setEnable(bool enable)
    {
      m_values.AddMember("Enable", parse_json<bool>::format(enable, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
