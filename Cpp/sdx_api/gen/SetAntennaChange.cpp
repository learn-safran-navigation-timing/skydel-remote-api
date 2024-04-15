
#include "SetAntennaChange.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetAntennaChange
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetAntennaChange::CmdName = "SetAntennaChange";
    const char* const SetAntennaChange::Documentation = "Add/edit an antenna change.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ --------------------------------------------------\n"
      "StartTime double Elapsed time in seconds since start of simulation.\n"
      "Antenna   string Antenna model name\n"
      "Id        string Unique identifier of the event";
    const char* const SetAntennaChange::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetAntennaChange);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetAntennaChange);


    SetAntennaChange::SetAntennaChange()
      : CommandBase(CmdName, TargetId)
    {}

    SetAntennaChange::SetAntennaChange(double startTime, const std::string& antenna, const std::string& id)
      : CommandBase(CmdName, TargetId)
    {

      setStartTime(startTime);
      setAntenna(antenna);
      setId(id);
    }

    SetAntennaChangePtr SetAntennaChange::create(double startTime, const std::string& antenna, const std::string& id)
    {
      return std::make_shared<SetAntennaChange>(startTime, antenna, id);
    }

    SetAntennaChangePtr SetAntennaChange::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetAntennaChange>(ptr);
    }

    bool SetAntennaChange::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["StartTime"])
          && parse_json<std::string>::is_valid(m_values["Antenna"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string SetAntennaChange::documentation() const { return Documentation; }

    const std::vector<std::string>& SetAntennaChange::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "Antenna", "Id"}; 
      return names; 
    }


    int SetAntennaChange::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    double SetAntennaChange::startTime() const
    {
      return parse_json<double>::parse(m_values["StartTime"]);
    }

    void SetAntennaChange::setStartTime(double startTime)
    {
      m_values.AddMember("StartTime", parse_json<double>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetAntennaChange::antenna() const
    {
      return parse_json<std::string>::parse(m_values["Antenna"]);
    }

    void SetAntennaChange::setAntenna(const std::string& antenna)
    {
      m_values.AddMember("Antenna", parse_json<std::string>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string SetAntennaChange::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void SetAntennaChange::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
