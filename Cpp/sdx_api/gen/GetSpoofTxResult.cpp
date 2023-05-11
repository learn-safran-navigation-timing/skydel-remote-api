
#include "gen/GetSpoofTxResult.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSpoofTxResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSpoofTxResult::CmdName = "GetSpoofTxResult";
    const char* const GetSpoofTxResult::Documentation = "Result of GetSpoofTx.";

    REGISTER_COMMAND_RESULT_TO_FACTORY_IMPL(GetSpoofTxResult);


    GetSpoofTxResult::GetSpoofTxResult()
      : CommandResult(CmdName)
    {}

    GetSpoofTxResult::GetSpoofTxResult(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
      : CommandResult(CmdName)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setAddress(address);
      setInstanceId(instanceId);
      setId(id);
    }

    GetSpoofTxResult::GetSpoofTxResult(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
      : CommandResult(CmdName, relatedCommand)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setAddress(address);
      setInstanceId(instanceId);
      setId(id);
    }


    GetSpoofTxResultPtr GetSpoofTxResult::create(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
    {
      return std::make_shared<GetSpoofTxResult>(usualName, enabled, address, instanceId, id);
    }

    GetSpoofTxResultPtr GetSpoofTxResult::create(CommandBasePtr relatedCommand, const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
    {
      return std::make_shared<GetSpoofTxResult>(relatedCommand, usualName, enabled, address, instanceId, id);
    }

    GetSpoofTxResultPtr GetSpoofTxResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSpoofTxResult>(ptr);
    }

    bool GetSpoofTxResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<int>::is_valid(m_values["InstanceId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetSpoofTxResult::documentation() const { return Documentation; }


    std::string GetSpoofTxResult::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void GetSpoofTxResult::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool GetSpoofTxResult::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void GetSpoofTxResult::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxResult::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void GetSpoofTxResult::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetSpoofTxResult::instanceId() const
    {
      return parse_json<int>::parse(m_values["InstanceId"]);
    }

    void GetSpoofTxResult::setInstanceId(int instanceId)
    {
      m_values.AddMember("InstanceId", parse_json<int>::format(instanceId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetSpoofTxResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetSpoofTxResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
