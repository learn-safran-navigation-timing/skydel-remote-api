
#include "IsDektecAdjustedNoiseEnabledResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsDektecAdjustedNoiseEnabledResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsDektecAdjustedNoiseEnabledResult::CmdName = "IsDektecAdjustedNoiseEnabledResult";
    const char* const IsDektecAdjustedNoiseEnabledResult::Documentation = "Result of IsDektecAdjustedNoiseEnabled.\n"
      "\n"
      "Name   Type Description\n"
      "------ ---- ----------------------------------------------------------------\n"
      "Enable bool True to enable Advance Jammer noise adjustment on Dektec output.";
    const char* const IsDektecAdjustedNoiseEnabledResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(IsDektecAdjustedNoiseEnabledResult);


    IsDektecAdjustedNoiseEnabledResult::IsDektecAdjustedNoiseEnabledResult()
      : CommandResult(CmdName, TargetId)
    {}

    IsDektecAdjustedNoiseEnabledResult::IsDektecAdjustedNoiseEnabledResult(bool enable)
      : CommandResult(CmdName, TargetId)
    {

      setEnable(enable);
    }

    IsDektecAdjustedNoiseEnabledResult::IsDektecAdjustedNoiseEnabledResult(CommandBasePtr relatedCommand, bool enable)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setEnable(enable);
    }


    IsDektecAdjustedNoiseEnabledResultPtr IsDektecAdjustedNoiseEnabledResult::create(bool enable)
    {
      return std::make_shared<IsDektecAdjustedNoiseEnabledResult>(enable);
    }

    IsDektecAdjustedNoiseEnabledResultPtr IsDektecAdjustedNoiseEnabledResult::create(CommandBasePtr relatedCommand, bool enable)
    {
      return std::make_shared<IsDektecAdjustedNoiseEnabledResult>(relatedCommand, enable);
    }

    IsDektecAdjustedNoiseEnabledResultPtr IsDektecAdjustedNoiseEnabledResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsDektecAdjustedNoiseEnabledResult>(ptr);
    }

    bool IsDektecAdjustedNoiseEnabledResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<bool>::is_valid(m_values["Enable"])
        ;

    }

    std::string IsDektecAdjustedNoiseEnabledResult::documentation() const { return Documentation; }

    const std::vector<std::string>& IsDektecAdjustedNoiseEnabledResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Enable"}; 
      return names; 
    }


    bool IsDektecAdjustedNoiseEnabledResult::enable() const
    {
      return parse_json<bool>::parse(m_values["Enable"]);
    }

    void IsDektecAdjustedNoiseEnabledResult::setEnable(bool enable)
    {
      m_values.AddMember("Enable", parse_json<bool>::format(enable, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
