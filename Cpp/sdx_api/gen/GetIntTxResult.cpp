
#include "gen/GetIntTxResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetIntTxResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetIntTxResult::CmdName = "GetIntTxResult";
    const char* const GetIntTxResult::Documentation = "Result of GetIntTx.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetIntTxResult);


    GetIntTxResult::GetIntTxResult()
      : CommandResult(CmdName)
    {}

    GetIntTxResult::GetIntTxResult(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
      : CommandResult(CmdName)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setGroup(group);
      setDynamic(dynamic);
      setPower(power);
      setId(id);
    }

    GetIntTxResult::GetIntTxResult(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setGroup(group);
      setDynamic(dynamic);
      setPower(power);
      setId(id);
    }


    GetIntTxResultPtr GetIntTxResult::create(const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
    {
      return std::make_shared<GetIntTxResult>(usualName, enabled, group, dynamic, power, id);
    }

    GetIntTxResultPtr GetIntTxResult::create(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, int group, bool dynamic, double power, const std::string& id)
    {
      return std::make_shared<GetIntTxResult>(relatedCommand, usualName, enabled, group, dynamic, power, id);
    }

    GetIntTxResultPtr GetIntTxResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetIntTxResult>(ptr);
    }

    bool GetIntTxResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<int>::is_valid(m_values["Group"])
          && parse_json<bool>::is_valid(m_values["Dynamic"])
          && parse_json<double>::is_valid(m_values["Power"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetIntTxResult::documentation() const { return Documentation; }


    std::string GetIntTxResult::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void GetIntTxResult::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetIntTxResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetIntTxResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetIntTxResult::group() const
    {
      return parse_json<int>::parse(m_values["Group"]);
    }

    void GetIntTxResult::setGroup(int group)
    {
      m_values.AddMember("Group", parse_json<int>::format(group, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetIntTxResult::dynamic() const
    {
      return parse_json<bool>::parse(m_values["Dynamic"]);
    }

    void GetIntTxResult::setDynamic(bool dynamic)
    {
      m_values.AddMember("Dynamic", parse_json<bool>::format(dynamic, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetIntTxResult::power() const
    {
      return parse_json<double>::parse(m_values["Power"]);
    }

    void GetIntTxResult::setPower(double power)
    {
      m_values.AddMember("Power", parse_json<double>::format(power, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetIntTxResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetIntTxResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
