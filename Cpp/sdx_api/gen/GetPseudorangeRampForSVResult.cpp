
#include "GetPseudorangeRampForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetPseudorangeRampForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetPseudorangeRampForSVResult::CmdName = "GetPseudorangeRampForSVResult";
    const char* const GetPseudorangeRampForSVResult::Documentation = "Result of GetPseudorangeRampForSV.\n"
      "\n"
      "Name          Type   Description\n"
      "------------- ------ ----------------------------------------------------------------------------------\n"
      "System        string \"GPS\", \"GLONASS\", \"Galileo\", \"BeiDou\", \"SBAS\", \"QZSS\", \"NavIC\" or \"PULSAR\"\n"
      "SvId          int    The satellite's SV ID.\n"
      "Offset        double Change to satellite pseudorange in meter when ramp is at maximum. Range -1e7..+1e7\n"
      "StartTime     int    Elapsed time in seconds since start of simulation.\n"
      "HoldStartTime int    Elapsed time in seconds since start of simulation. HoldStartTime >= StartTime\n"
      "HoldStopTime  int    Elapsed time in seconds since start of simulation. HoldStopTime >= HoldStartTime\n"
      "StopTime      int    Elapsed time in seconds since start of simulation. StopTime >= HoldStopTime\n"
      "Id            string Unique identifier automatically set by simulator if empty string.\n"
      "                     The IDs pool is common between all system.";
    const char* const GetPseudorangeRampForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetPseudorangeRampForSVResult);


    GetPseudorangeRampForSVResult::GetPseudorangeRampForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetPseudorangeRampForSVResult::GetPseudorangeRampForSVResult(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
      : CommandResult(CmdName, TargetId)
    {

      setSystem(system);
      setSvId(svId);
      setOffset(offset);
      setStartTime(startTime);
      setHoldStartTime(holdStartTime);
      setHoldStopTime(holdStopTime);
      setStopTime(stopTime);
      setId(id);
    }

    GetPseudorangeRampForSVResult::GetPseudorangeRampForSVResult(CommandBasePtr relatedCommand, const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSystem(system);
      setSvId(svId);
      setOffset(offset);
      setStartTime(startTime);
      setHoldStartTime(holdStartTime);
      setHoldStopTime(holdStopTime);
      setStopTime(stopTime);
      setId(id);
    }


    GetPseudorangeRampForSVResultPtr GetPseudorangeRampForSVResult::create(const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
    {
      return std::make_shared<GetPseudorangeRampForSVResult>(system, svId, offset, startTime, holdStartTime, holdStopTime, stopTime, id);
    }

    GetPseudorangeRampForSVResultPtr GetPseudorangeRampForSVResult::create(CommandBasePtr relatedCommand, const std::string& system, int svId, double offset, int startTime, int holdStartTime, int holdStopTime, int stopTime, const std::string& id)
    {
      return std::make_shared<GetPseudorangeRampForSVResult>(relatedCommand, system, svId, offset, startTime, holdStartTime, holdStopTime, stopTime, id);
    }

    GetPseudorangeRampForSVResultPtr GetPseudorangeRampForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetPseudorangeRampForSVResult>(ptr);
    }

    bool GetPseudorangeRampForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["System"])
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<double>::is_valid(m_values["Offset"])
          && parse_json<int>::is_valid(m_values["StartTime"])
          && parse_json<int>::is_valid(m_values["HoldStartTime"])
          && parse_json<int>::is_valid(m_values["HoldStopTime"])
          && parse_json<int>::is_valid(m_values["StopTime"])
          && parse_json<std::string>::is_valid(m_values["Id"])
        ;

    }

    std::string GetPseudorangeRampForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetPseudorangeRampForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"System", "SvId", "Offset", "StartTime", "HoldStartTime", "HoldStopTime", "StopTime", "Id"}; 
      return names; 
    }


    std::string GetPseudorangeRampForSVResult::system() const
    {
      return parse_json<std::string>::parse(m_values["System"]);
    }

    void GetPseudorangeRampForSVResult::setSystem(const std::string& system)
    {
      m_values.AddMember("System", parse_json<std::string>::format(system, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetPseudorangeRampForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double GetPseudorangeRampForSVResult::offset() const
    {
      return parse_json<double>::parse(m_values["Offset"]);
    }

    void GetPseudorangeRampForSVResult::setOffset(double offset)
    {
      m_values.AddMember("Offset", parse_json<double>::format(offset, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampForSVResult::startTime() const
    {
      return parse_json<int>::parse(m_values["StartTime"]);
    }

    void GetPseudorangeRampForSVResult::setStartTime(int startTime)
    {
      m_values.AddMember("StartTime", parse_json<int>::format(startTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampForSVResult::holdStartTime() const
    {
      return parse_json<int>::parse(m_values["HoldStartTime"]);
    }

    void GetPseudorangeRampForSVResult::setHoldStartTime(int holdStartTime)
    {
      m_values.AddMember("HoldStartTime", parse_json<int>::format(holdStartTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampForSVResult::holdStopTime() const
    {
      return parse_json<int>::parse(m_values["HoldStopTime"]);
    }

    void GetPseudorangeRampForSVResult::setHoldStopTime(int holdStopTime)
    {
      m_values.AddMember("HoldStopTime", parse_json<int>::format(holdStopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int GetPseudorangeRampForSVResult::stopTime() const
    {
      return parse_json<int>::parse(m_values["StopTime"]);
    }

    void GetPseudorangeRampForSVResult::setStopTime(int stopTime)
    {
      m_values.AddMember("StopTime", parse_json<int>::format(stopTime, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::string GetPseudorangeRampForSVResult::id() const
    {
      return parse_json<std::string>::parse(m_values["Id"]);
    }

    void GetPseudorangeRampForSVResult::setId(const std::string& id)
    {
      m_values.AddMember("Id", parse_json<std::string>::format(id, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
