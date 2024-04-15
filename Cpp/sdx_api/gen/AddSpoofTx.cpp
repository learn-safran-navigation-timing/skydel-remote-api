
#include "AddSpoofTx.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of AddSpoofTx
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const AddSpoofTx::CmdName = "AddSpoofTx";
    const char* const AddSpoofTx::Documentation = "Set a spoofer transmitter. For set : the transmitter Id parameter is not set (empty string),\n"
      "Skydel will assign a unique Id to the transmitter. If the Id is set and already used by Skydel, the\n"
      "command will fail.\n"
      "\n"
      "Name       Type   Description\n"
      "---------- ------ ------------------------------------------------\n"
      "UsualName  string Usual name for the transmitter.\n"
      "Enabled    bool   Enable (true) or disable (false) the transmitter\n"
      "Address    string Remote instance IP address.\n"
      "InstanceId int    Remote instance ID.\n"
      "Id         string Transmitter unique identifier.";
    const char* const AddSpoofTx::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(AddSpoofTx);
    REGISTER_COMMAND_TO_FACTORY_IMPL(AddSpoofTx);


    AddSpoofTx::AddSpoofTx()
      : CommandBase(CmdName, TargetId)
    {}

    AddSpoofTx::AddSpoofTx(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setUsualName(usualName);
      setEnabled(enabled);
      setAddress(address);
      setInstanceId(instanceId);
      setId(id);
    }

    AddSpoofTxPtr AddSpoofTx::create(const std::string& usualName, bool enabled, const std::string& address, int instanceId, const std::string& id)
    {
      return std::make_shared<AddSpoofTx>(usualName, enabled, address, instanceId, id);
    }

    AddSpoofTxPtr AddSpoofTx::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<AddSpoofTx>(ptr);
    }

    bool AddSpoofTx::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["UsualName"])
          && parse_json<bool>::is_valid(m_values["Enabled"])
          && parse_json<std::string>::is_valid(m_values["Address"])
          && parse_json<int>::is_valid(m_values["InstanceId"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string AddSpoofTx::documentation() const { return Documentation; }

    const std::vector<std::string>& AddSpoofTx::fieldNames() const 
    { 
      static const std::vector<std::string> names {"UsualName", "Enabled", "Address", "InstanceId", "Id"}; 
      return names; 
    }


    int AddSpoofTx::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string AddSpoofTx::usualName() const
    {
      return parse_json<std::string>::parse(m_values["UsualName"]);
    }

    void AddSpoofTx::setUsualName(const std::string& usualName)
    {
      m_values.AddMember("UsualName", parse_json<std::string>::format(usualName, m_values.GetAllocator()), m_values.GetAllocator());
    }



    bool AddSpoofTx::enabled() const
    {
      return parse_json<bool>::parse(m_values["Enabled"]);
    }

    void AddSpoofTx::setEnabled(bool enabled)
    {
      m_values.AddMember("Enabled", parse_json<bool>::format(enabled, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddSpoofTx::address() const
    {
      return parse_json<std::string>::parse(m_values["Address"]);
    }

    void AddSpoofTx::setAddress(const std::string& address)
    {
      m_values.AddMember("Address", parse_json<std::string>::format(address, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int AddSpoofTx::instanceId() const
    {
      return parse_json<int>::parse(m_values["InstanceId"]);
    }

    void AddSpoofTx::setInstanceId(int instanceId)
    {
      m_values.AddMember("InstanceId", parse_json<int>::format(instanceId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string AddSpoofTx::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void AddSpoofTx::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
