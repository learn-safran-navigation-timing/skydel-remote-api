
#include "GetAntennaChangeResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetAntennaChangeResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetAntennaChangeResult::CmdName = "GetAntennaChangeResult";
    const char* const GetAntennaChangeResult::Documentation = "Result of GetAntennaChange.\n"
      "\n"
      "Name      Type   Description\n"
      "--------- ------ --------------------------------------------------\n"
      "StartTime double Elapsed time in seconds since start of simulation.\n"
      "Antenna   string Antenna model name\n"
      "Id        string Unique identifier of the event";
    const char* const GetAntennaChangeResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetAntennaChangeResult);


    GetAntennaChangeResult::GetAntennaChangeResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetAntennaChangeResult::GetAntennaChangeResult(double startTime, const std::string& antenna, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setStartTime(startTime);
      setAntenna(antenna);
      setId(id);
    }

    GetAntennaChangeResult::GetAntennaChangeResult(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setStartTime(startTime);
      setAntenna(antenna);
      setId(id);
    }


    GetAntennaChangeResultPtr GetAntennaChangeResult::create(double startTime, const std::string& antenna, const std::string& id)
    {
      return std::make_shared<GetAntennaChangeResult>(startTime, antenna, id);
    }

    GetAntennaChangeResultPtr GetAntennaChangeResult::create(CommandBasePtr relatedCommand, double startTime, const std::string& antenna, const std::string& id)
    {
      return std::make_shared<GetAntennaChangeResult>(relatedCommand, startTime, antenna, id);
    }

    GetAntennaChangeResultPtr GetAntennaChangeResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetAntennaChangeResult>(ptr);
    }

    bool GetAntennaChangeResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<double>::is_valid(m_values["StartTime"])
          && parse_json<std::string>::is_valid(m_values["Antenna"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetAntennaChangeResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetAntennaChangeResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"StartTime", "Antenna", "Id"}; 
      return names; 
    }


    double GetAntennaChangeResult::startTime() const
    {
      return parse_json<double>::parse(m_values["StartTime"]);
    }

    void GetAntennaChangeResult::setStartTime(double startTime)
    {
      m_values.AddMember("StartTime", parse_json<double>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetAntennaChangeResult::antenna() const
    {
      return parse_json<std::string>::parse(m_values["Antenna"]);
    }

    void GetAntennaChangeResult::setAntenna(const std::string& antenna)
    {
      m_values.AddMember("Antenna", parse_json<std::string>::format(antenna, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetAntennaChangeResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetAntennaChangeResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
